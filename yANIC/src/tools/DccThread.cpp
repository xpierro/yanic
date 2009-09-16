#include "DccThread.h"

DccThread::DccThread(int dccSocketDescriptor, QFile *dccFile,
					 int fileSize, QObject *parent)	: QThread(parent) {
	this->dccSocketDescriptor = dccSocketDescriptor;
	this->dccFile = dccFile;
	this->fileSize = fileSize;
	dccSocket = NULL;
	this->dccSocket = new QTcpSocket(this); // Equivalent au moveToThread
	dccSocket->setSocketDescriptor(dccSocketDescriptor);
	dccSocket->moveToThread(this);
}

DccThread::DccThread(QTcpSocket *dccSocket, QFile *dccFile, int fileSize,
					 QObject *parent) : QThread(parent) {
	this->dccSocket = dccSocket;
	this->dccFile = dccFile;
	this->fileSize = fileSize;
}

void DccThread::run() {
	quint32 sizeRecv;
	quint32 ack;
	quint32 sizeTotal = 0;
	while (dccSocket->waitForReadyRead() && dccSocket->bytesAvailable() > 0) {
	    sizeRecv = dccSocket->bytesAvailable();
	    sizeTotal += sizeRecv;
		dccFile->write(dccSocket->read(sizeRecv));
		ack = qToBigEndian(sizeTotal & 0xffffffff); // Masque inutile ?
		dccSocket->write((char *)&ack, 4);
		emit gotNewBytes((int) (((float) sizeTotal / (float) fileSize) * 100));
	}
	dccSocket->disconnectFromHost();
	dccSocket->deleteLater();
	dccFile->close();
}
