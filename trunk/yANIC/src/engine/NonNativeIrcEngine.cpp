#include "NonNativeIrcEngine.h"
#define MAX_LEN 600

NonNativeIrcEngine::NonNativeIrcEngine(void) {
	sock = new QTcpSocket(this);
	connected = false;
	connect(sock, SIGNAL(readyRead()), this, SLOT(relayReadyRead()));
}

NonNativeIrcEngine* NonNativeIrcEngine::engine() {
	if (instance == 0) {
		instance = new NonNativeIrcEngine();
	}
	return instance;
}

NonNativeIrcEngine* NonNativeIrcEngine::instance = NULL;

void NonNativeIrcEngine::relayReadyRead() {
	QString bulk;
	QString line;
	while (sock->canReadLine()) {
		/* On ajoute à la masse que si non PING/PONG :) */
		if (returnLine(line)) bulk += line;
	}
		emit lineReceived(bulk);
}

void NonNativeIrcEngine::sendASCIIMessage(const QString& mess) {
	sock->write(mess.toUtf8().constData());
}

bool NonNativeIrcEngine::readLine(char *line, qint64 lSize) {
	sock->readLine(line, lSize);
    if (!strncmp(line, "PING", 4)) { // Message PING/PONG.
    	sendASCIIMessage(QString("PONG :") + QString(line + 6));
    	qDebug("PING PONG");
    	return false;
    } else {
    	return true;
    }
}

bool NonNativeIrcEngine::returnLine(QString& lineStr) {
	char *line = (char*) malloc(MAX_LEN * sizeof(char));
	bool notPing = readLine(line, MAX_LEN);
	lineStr = QString(line);
	free(line);
	return notPing;

}

void NonNativeIrcEngine::connectToHost(QString host, int port) {
	sock->connectToHost(host, port);
	if (!sock->waitForConnected(10000)) {
		QMessageBox::critical(NULL, "Erreur de connexion",
							  "Impossible de se connecter.");
		emit connectError();
	}
	else connected = true;
}

bool NonNativeIrcEngine::canReadLine() {
	return sock->canReadLine();
}

bool NonNativeIrcEngine::isConnected() {
	return connected;
}

void NonNativeIrcEngine::initiateConnection(const QString& host,
											int port,
											const QString& nick) {
	connectToHost(host, port);
    if (isConnected()) {
    	sendASCIIMessage("NICK " + nick + "\r\n");
    	sendASCIIMessage("USER yANIC rien rien :" + nick + "\r\n");
    	//sendASCIIMessage("WHOIS " + nick + "\r\n");
    }
}

