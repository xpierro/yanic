#include "DccServer.h"

DccServer::DccServer(QString ip, int port, QObject *parent)
														: QTcpServer(parent) {
	listen(QHostAddress::Any, port);
	portNum = port;
	this->ip = ip;
}

void DccServer::setNewConnection(QFile *dldedFile, int fileSize,
												QProgressBar *progressBar) {
	this->dldedFile = dldedFile;
	this->fileSize = fileSize;
	this->progressBar = progressBar;
}

void DccServer::incomingConnection(int socketDescriptor) {
	DccThread *downloadThread =
			new DccThread(socketDescriptor, dldedFile, fileSize, this);

	connect(downloadThread, SIGNAL(gotNewBytes(int)),
			progressBar, SLOT(setValue(int)));
	connect(downloadThread, SIGNAL(finished()),
			downloadThread, SLOT(deleteLater()));
	downloadThread->start();
}


