#include "XmlConfManager.h"

XmlConfManager::XmlConfManager(QObject *parent = NULL) : QObject(parent){
	/* Création des balises de haut niveau */
	servers = confDesc.createElement("servers");
	confDesc.appendChild(servers);

}

void XmlConfManager::addServer(QString name) {
	QDomElement server = confDesc.createElement("server");
	servers.appendChild(server);
	server.setAttribute("name", name);
}

Network XmlConfManager::createNetwork(QString host, QString port) {
	Network net;
	net.host = host;
	net.port = port;
	return net;
}

QDomElement XmlConfManager::findServer(QString name) {
	QDomElement serverElement;
	/* Cherchons le serveur demandé */
	for (serverElement = servers.firstChildElement("server");
		 !serverElement.isNull();
		 serverElement = serverElement.nextSiblingElement("server")) {
		if (serverElement.attribute("name", "") == name) {
			break;
		}
	}
	return serverElement;
}

void XmlConfManager::addNetwork(QString server, Network network) {
	QDomElement networkSubElement = confDesc.createElement("network");
	QDomElement host = confDesc.createElement("host");
	QDomElement port = confDesc.createElement("port");
	QDomText hostText = confDesc.createTextNode(network.host);
	QDomText portText = confDesc.createTextNode(network.port);

	host.appendChild(hostText);
	port.appendChild(portText);
	networkSubElement.appendChild(host);
	networkSubElement.appendChild(port);
	findServer(server).appendChild(networkSubElement);
}

User XmlConfManager::createUser(QString nickname, QString ghost,
								QString username, QString realname) {
	User user;
	user.nickname = nickname;
	user.ghost = ghost;
	user.username = username;
	user.realname = realname;
	return user;
}

void XmlConfManager::changeUser(QString server, User user) {
	QDomElement serverElement = findServer(server);
	QDomElement userElement = serverElement.firstChildElement("user");
	serverElement.removeChild(userElement);

	/* Recréation de l'utilisateur */
	userElement = confDesc.createElement("user");

	QDomElement nickname = confDesc.createElement("nickname");
	QDomElement ghost = confDesc.createElement("ghost");
	QDomElement username = confDesc.createElement("username");
	QDomElement realname = confDesc.createElement("realname");

	QDomText nickText = confDesc.createTextNode(user.nickname);
	QDomText ghostText = confDesc.createTextNode(user.ghost);
	QDomText usernameText = confDesc.createTextNode(user.username);
	QDomText realnameText = confDesc.createTextNode(user.realname);

	nickname.appendChild(nickText);
	ghost.appendChild(ghostText);
	username.appendChild(usernameText);
	realname.appendChild(realnameText);

	userElement.appendChild(nickname);
	userElement.appendChild(ghost);
	userElement.appendChild(username);
	userElement.appendChild(realname);

	serverElement.appendChild(userElement);
}

void XmlConfManager::changeFavChan(QString server, QString chanList) {
	QDomElement serverElement = findServer(server);

	QDomNodeList favList = serverElement.elementsByTagName("favorite");
	for (int i = 0; i < favList.size(); i++) {
		serverElement.removeChild(favList.item(i));
	}
	QStringListIterator it(chanList.split(","));
	QDomElement chan;
	QDomText name;
	int i = 0;
	while (it.hasNext()) {
		chan = confDesc.createElement("favorite");
		chan.setAttribute("id", i);
		name = confDesc.createTextNode(it.next());
		chan.appendChild(name);
		serverElement.appendChild(chan);
		i += 1;
	}
}

QString XmlConfManager::getHostByName(QString serverName) {
	return
		findServer(serverName).
			firstChildElement("network").
				firstChildElement("host").
					text();
}
QString XmlConfManager::getPortByName(QString serverName) {
	return
		findServer(serverName).
			firstChildElement("network").
				firstChildElement("port").
					text();
}

QStringList XmlConfManager::getServerList() {
	QStringList serverList;
	QDomNodeList list = servers.elementsByTagName("server");
	for (int i = 0; i < list.size(); i++) {
		serverList.append(list.at(i).toElement().attribute("name", ""));
	}
	return serverList;
}

void XmlConfManager::changeCommand(QString server, QString code) {
	QDomElement serverElement = findServer(server);
	QDomElement changeCommand = serverElement.firstChildElement("command");
	serverElement.removeChild(changeCommand);
	changeCommand = confDesc.createElement("command");

	QDomText command = confDesc.createTextNode(code);
	changeCommand.appendChild(command);
	serverElement.appendChild(changeCommand);
}

void XmlConfManager::save() {
	qDebug("Writing off the xml");
	confFile.setFileName("conf.xml");
	if (!confFile.open(QIODevice::WriteOnly)) {
		qDebug("shit, can't open");
		return; //Mettre une exception ici.
	}
	out.setDevice(&confFile);

	QDomNode node = confDesc.createProcessingInstruction("xml",
														 "version=\"1.0\"");
	confDesc.insertBefore(node, confDesc.firstChild());
	confDesc.save(out, 2);
	confFile.close();
}

void XmlConfManager::read() {
	qDebug("Reading on the xml");
	confFile.setFileName("conf.xml");
	if (!confFile.open(QIODevice::ReadOnly)) {
		qDebug("shit, can't open");
		return; //Mettre une exception ici.
	}
	if(!confDesc.setContent(&confFile)) {
		confFile.close();
		return;
	}
	servers = confDesc.firstChildElement("servers");
	confFile.close();
}

XmlConfManager* XmlConfManager::confManager() {
	if (instance == NULL) {
		instance = new XmlConfManager();
	}
	return instance;
}

XmlConfManager* XmlConfManager::instance = NULL;
