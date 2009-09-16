/*!
 * \file main.cpp
 * Lancement du programme, création des fenêtre.
 */

#include "main.h"

/*!
 * \fn int main(int argc, char **argv)
 * Fonction principale
 * \return Le code de fin d'execution de la main loop.
 */
int main (int argc,char **argv) {
    QApplication app(argc,argv);

    MainWindow *fen = new MainWindow(NULL);

    IIrcEngine *engine = NonNativeIrcEngine::engine();



    QObject::connect(fen,
    		SIGNAL(connectMe(const QString&, int, const QString&)),
    		engine,
    		SLOT(initiateConnection(const QString&, int, const QString&)));
    QObject::connect(engine, SIGNAL(lineReceived(QString)), fen, SLOT(readServer(QString)));
    QObject::connect(fen, SIGNAL(sendASCIIMessage(const QString&)), engine, SLOT(sendASCIIMessage(const QString&)));
	/* La QMainWindow */
	MainWindowView *mW = new MainWindowView(fen,NULL);
	mW->show();

	XmlConfManager *confMan = XmlConfManager::confManager();
	/*confMan->addServer("test");
	confMan->addNetwork("test", confMan->createNetwork("irc.fansub-irc.eu", "6667"));
	confMan->changeUser("test", confMan->createUser("pierre", "pierreghost", "user", "real"));
	confMan->changeFavChan("test", "#fsf,#Kyubi-Wolf");
	confMan->changeCommand("test", "/ns identify albachat");
	confMan->save();*/
	confMan->read();

	ServerList *serverList = new ServerList();
	QObject::connect(serverList, SIGNAL(connectSignal(QString&, int, QString&)),
					 fen, SLOT(connexion(QString&, int, QString&)));
	QObject::connect(engine, SIGNAL(connectError()),
					 serverList, SLOT(reconnect()));
	serverList->show();

    return app.exec();
    }
