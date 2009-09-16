#include "DccGet.h"

DccGet::DccGet(QObject *parent = 0) : QObject(parent) {
	dccServer = new DccServer("127.0.0.1", 6789, NULL);
}

DccGet* DccGet::instance = 0;

DccGet* DccGet::dccHandle() {
	if (instance == 0) {
		instance = new DccGet(NULL);
	}
	return instance;
}

void DccGet::download(QString orig, QString mess, QProgressBar *progressBar, QString myIP = "127.0.0.1") {
	QString cursor;
	QString fileName;
	QString ipAddress;
	int port;
	int fileSize;
	int token;

	cursor = mess.section(' ',2); //On se place apres le DCC SEND
	if (cursor.at(0) == '\"') { //Si guillemet
		fileName = cursor.section('\"', 1, 1,
				QString::SectionIncludeLeadingSep |
				QString::SectionIncludeTrailingSep);
	} else {
		fileName = cursor.section(' ',0,0);
	}
	cursor = mess.mid(8 + fileName.length() + 2);
	QStringList list = cursor.split(' ');
	ipAddress = list[0];
	port = list[1].toInt();
	fileSize = list[2].toInt();
	if (list.length() > 3) token = list[3].toInt();

	QFile *dldedFile;

	if (fileName[0] == '\"') {
		dldedFile = new QFile(fileName.section('\"', 1, 1));
	} else {
		dldedFile = new QFile(fileName);
	}
	dldedFile->open(QIODevice::WriteOnly);

	progressBar->setWindowTitle(fileName);

	/* Il peut y avoir soit un DCC reverse, soit un DCC standard */
	if (port == 0) { //DCC Reverse
		dccServer->setNewConnection(dldedFile, fileSize, progressBar);
		emit sendCTCP(orig, "DCC SEND " + fileName + " " +
					 (new QString())->setNum((new QHostAddress(myIP))
												 ->toIPv4Address()) +
					 " " + (new QString())->setNum(6789) +
					 " " + (new QString())->setNum(fileSize) + " " +
					 (new QString())->setNum(token));
	} else { // DCC Standard
		QTcpSocket *dccSocket = new QTcpSocket();
		dccSocket
			->connectToHost(QHostAddress((qint32)ipAddress.toInt()), port);
		if(!dccSocket->waitForConnected(1000)) {
			QMessageBox::critical(NULL,"DCC",
										"Impossible de recevoir le fichier "
										+ fileName
										+ " venant de l'hote distant "
										+ QHostAddress((qint32)ipAddress.toInt()).toString()
										+ " sur le port "
										+ (new QString())->setNum(port));
		} else {
			DccThread *downloadThread =
					new DccThread(dccSocket, dldedFile, fileSize, NULL);
					connect(downloadThread, SIGNAL(finished()),
							downloadThread, SLOT(deleteLater()));
					connect (downloadThread, SIGNAL(gotNewBytes(int)),
							 progressBar, SLOT(setValue(int)));
			/* INDISPENSABLE, CAUSE ENORMEMENT D'ERREUR SI OUBLIE */
			dccSocket->moveToThread(downloadThread);
			downloadThread->start();
		}
	}
}
