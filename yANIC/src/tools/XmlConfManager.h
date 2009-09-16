#ifndef XML_CONF_H
#define XML_CONF_H

#include <QObject>
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include <QStringListIterator>

typedef struct {
	QString nickname;
	QString ghost;
	QString username;
	QString realname;
} User;

typedef struct {
	QString host;
	QString port;
} Network;

typedef struct networklist{
	Network network;
	networklist *suiv;
} NetworkList;

class XmlConfManager : public QObject {
	Q_OBJECT

private :
	QDomDocument confDesc;
	QDomElement servers;
	QFile confFile;
	QTextStream out;
	static XmlConfManager *instance;

protected :
	XmlConfManager(QObject *parent);

public :
	static XmlConfManager* confManager();

	Network createNetwork(QString host, QString port);
	User createUser(QString nickname, QString ghost,
					QString username, QString realname);
public slots :
	//void initXmlDefinition();

	void addServer(QString name);
	void addNetwork(QString server, Network network);
	void changeUser(QString server, User user);
	void changeFavChan(QString server, QString chanList);
	void changeCommand(QString server, QString code);
	//void addNickServerPass(QString server, QString pass);
	//void addServerPass(QString server, QString pass);

	QString getHostByName(QString serverName);
	QString getPortByName(QString serverName);
	QStringList getServerList();

	void read();
	void save();

private :
	QDomElement findServer(QString name);
};

#endif
