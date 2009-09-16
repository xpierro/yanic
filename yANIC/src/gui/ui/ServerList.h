#ifndef SERVER_LIST_H
#define SERVER_LIST_H

#include "ui_ServerList.h"
#include <QWidget>

#include "src/tools/XmlConfManager.h"

class ServerList : public QWidget {
	Q_OBJECT

private :
	Ui::Form ui;

public :
	ServerList();

public slots :
	void connectMe();
	void reconnect();

signals :
	void connectSignal(QString&, int, QString&);

};

#endif
