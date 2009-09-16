#include "ServerList.h"

ServerList::ServerList() : QWidget() {
	ui.setupUi(this);
	ui.networkList->addItems(XmlConfManager::confManager()->getServerList());
	ui.networkList->setCurrentRow(0);
	connect(ui.connectButton, SIGNAL(clicked()), this, SLOT(connectMe()));
	this->setWindowTitle("Liste des reseaux");
}

void ServerList::connectMe() {
	QString serverName = ui.networkList->currentItem()->text();
	QString serverHost =
			XmlConfManager::confManager()->getHostByName(serverName);
	QString serverPort =
			XmlConfManager::confManager()->getPortByName(serverName);
	QString nickname = ui.nicknameEdit->text();
	emit connectSignal(serverHost, serverPort.toInt(), nickname);
}

void ServerList::reconnect() {
	show();
}
