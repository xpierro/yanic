/**
 * \file MainWindow.cpp
 * \brief Implémentation de MainWindow.h
 * \author Pierre Collignon
 * \version 0.1
 *
 * Implémentation de la classe MainWindow, widget principal de la fenêtre.
 *
 */
#include "MainWindow.h"

void MainWindow::getInputLine(void){
    QString inputLine = input->text();
    // Ligne qui sera envoyée au server.
    QString outLine;
    if (!(inputLine.left(1) == "/")){ // Simple phrase a dire sur le chan courant.
    	if (currentCentralWidget->getName() == "server") { // Commande serveur, debug only
    		outLine = inputLine + "\r\n";
    	} else {
    		currentCentralWidget->write(*nick + " : " + inputLine);
    		outLine = "PRIVMSG " + currentCentralWidget->getName()
        			+ " :" + inputLine + "\r\n";
    	}
        sendServer(outLine);
    }

    else {
    	QString code;
    	QString suffix;
    	ircTools->outParser(inputLine, code, suffix);

    	switch(ircTools->getIdByCode(code, OUTPUT)) {
    	case JOIN :
    		if (Chan::isNameChan(suffix)) {
    			createAcwHash(suffix);
    			sendServer("JOIN " + suffix + "\r\n");
    		}
    		break;
    	case PART :
    		if (currentCentralWidget->getName() != "server") {
    			sendServer("PART " + currentCentralWidget->getName() + "\r\n");
    			qDebug("part sent to server");
    			deleteChan(currentCentralWidget->getName());
    			qDebug("Chan deleted");
    		}
    		break;
    	case LIST :
    		sendServer("LIST \r\n");
    		break;
    	case ME :
    		currentCentralWidget->write("*" + *nick + " " + suffix);
    		sendCTCP(currentCentralWidget->getName(), "ACTION " + suffix);
    		break;
    	case FINGER :
    		sendCTCP(suffix, "FINGER");
    		break;
    	case VERSION :
    		sendCTCP(suffix, "VERSION");
    		break;
    	case SOURCE :
    		sendCTCP(suffix, "SOURCE");
    	default :
    		qDebug("Commande inconnue");
    	}

    }
    input->setText("");
}

void MainWindow::readServer(QString bulk) {
	QStringList lines = bulk.split("\r\n", QString::SkipEmptyParts);
	QStringListIterator it(lines);
	while (it.hasNext()) {
		readLine(it.next());
	}
}

void MainWindow::readLine(QString line){ // Lit une ligne envoyée par le server.
	QRegExp matchingRegExp;
	QString orig;
	QString recev;
	QString ircCode;
	QString codeArg;
	QString nickStr;
	QString nickList;
	QStringList list;
	QHashIterator<QString, AbstractCentralWidget*> *it = chanTab->chanIterator();
	int indexNick;
	Chan *channel = NULL;
	AbstractCentralWidget *acw = NULL;

    ircTools->inParser(line, orig, ircCode, recev, codeArg);

    /* Abstractions des messages */
    switch(ircTools->getIdByCode(ircCode, INPUT)) {
		case RPL_WELCOME :
		case RPL_YOURHOST :
		case RPL_CREATED :
		case RPL_MYINFO :
		case RPL_BOUNCE :
		case RPL_LUSERCLIENT :
		case RPL_LUSEROP :
		case RPL_LUSERUNKNOWN :
		case RPL_LUSERCHANNELS :
		case RPL_MOTDSTART :
		case RPL_MOTD :
		case RPL_ENDOFMOTD :
		case RPL_LUSERME :
			server->write(codeArg);break;
		case RPL_WHOISHOST :
			webIP = findIp(codeArg.section(':', 1));
			break;
		case RPL_USERHOST :
			findIpUserHost(codeArg);
			break;
		case TOPIC :
			channel = dynamic_cast<Chan*>(getCenWidByName(codeArg.section(' ',0,0)));
			channel->setTopic(codeArg.section(':',1));
			channel->write(codeArg.section(':',1));
			currentTopic->setText(codeArg.section(':',1));
			currentTopic->setCursorPosition(0);
			break;
		case RPL_NAMREPLY :
			indexNick = 0;
			// On a le début de la liste
			nickList = codeArg.section(':', 1);
			nickStr = nickList.section(' ', indexNick, indexNick);
			while (nickStr != NULL) {
				dynamic_cast<Chan*> (getCenWidByName(codeArg.section(' ',1,1)))->addNickname(Nickname(nickStr));
				indexNick++;
				nickStr = nickList.section(' ', indexNick,indexNick);
			}
            break;
		case NOTICE :
			displayToCurrentWidget(orig + " : NOTICE : " + codeArg); break;
		case PRIVMSG :
			if (codeArg.contains(QString(QChar(0x001)) + "ACTION")) {
				getCenWidByName(recev)->write("*" +
					//Nickname::parseNickname(orig) +
					Nickname(orig).getNickname() +
					" " +
					codeArg.right(
							codeArg.length() - 8).section(QChar(0x001),
															0, 0));
				break;
			}
			if (codeArg.contains(QString(QChar(0x001)) + "DCC SEND")) {
				QProgressBar *progressBar = new QProgressBar(NULL);
				progressBar->setRange(0,100);
				progressBar->show();
				dccHandle->download(Nickname(orig).getNickname(),
						codeArg.right(codeArg.length() - 1).section(
															QChar(0x001),
															0, 0),
						progressBar,
						localIP);
				break;
			}
			if (!(codeArg.contains(QString(QChar(0x001))))) {
				if (!Chan::isNameChan(recev)) { // Si pv
					if (getCenWidByName(orig) == NULL) {
						createAcwHash(Nickname(orig).getLambdaNickname());
					}
					getCenWidByName(Nickname(orig).getLambdaNickname())->write(Nickname(orig).getLambdaNickname() +
																": " + codeArg);
					qDebug("Pv recu de : %s", Nickname(orig).getLambdaNickname().toUtf8().constData());
				} else {
					getCenWidByName(recev)->write(Nickname(orig).getNickname() +
											": " + codeArg);
				}
			}
			break;
		case JOIN :
			if (Nickname(orig).getNickname() != nick) {
				dynamic_cast<Chan*>(getCenWidByName(recev.mid(recev.indexOf(':') + 1)))
					->addNickname(Nickname(orig));
			}
			break;
		case QUIT :
			while (it->hasNext()) {
				acw = it->next().value();
				if (Chan::isNameChan(acw->getName())) {
					dynamic_cast<Chan*>(acw)->removeNickname(Nickname(orig));
				}
			}
			break;
		case PART :
			if (getCenWidByName(recev) != NULL) {
				dynamic_cast<Chan*>(getCenWidByName(recev))->removeNickname(Nickname(orig));
			}
			break;
		case RPL_LIST :
			chanList->addChan(codeArg);
			break;
		case RPL_ENDOF_LIST :
			chanList->sortByName();
			break;
		case MODE :
			if (getCenWidByName(recev) != NULL && (codeArg.contains("+o") || (codeArg.contains("+v")))) {
				dynamic_cast<Chan*>(getCenWidByName(recev))->changeMode(codeArg.section(' ', 1, 1),
												 codeArg.section(' ', 0, 0));
			}
			break;
		default :
			qDebug("stub : message inconnu : ");
			qDebug("%s %s %s %s", orig.toUtf8().constData(),
					ircCode.toUtf8().constData(),
					recev.toUtf8().constData(),
					codeArg.toUtf8().constData());
	}
}


void MainWindow::connexion(QString& serv,int port,QString& nick) {
	if (serv == NULL || port < 1000 || nick == NULL) {
		throw IllegalArgumentException("Connexion impossible.");
	}
    QString nickCommand("");
    QString userCommand("");

    this->nick = new QString(nick);

    emit connectMe(serv, port, nick);
    sendServer("USERHOST " + nick + "\r\n");
    sendServer("WHOIS " + nick + "\r\n");
}

MainWindow::MainWindow(QWidget *parent=0)
														: QWidget(parent){

    /* Singletons */
    chanTab = ChanList::chanListHandle();
	ircTools = AbstractMess::ircTools();
	dccHandle = DccGet::dccHandle();

	QString name("server");

	localIP = "127.0.0.1";
	webIP = localIP;

	mainSplitter = new QSplitter(Qt::Horizontal, this);
	centralWrapper = new QWidget(mainSplitter);
	centralGrid = new QGridLayout(centralWrapper);

	chanList = new List(NULL);

	nickListSize = 80;

    /* On initialise les divers élèments de la fenêtre */

	server = new PrivateMessage(name, mainSplitter);

	input = new LineEdit("", centralWrapper);

	grid = new QGridLayout(this);

	currentTopic = new QLineEdit("", centralWrapper);
	currentTopic->hide();

	currentCentralWidget = server;
	currentNickList = NULL;

	//acwHash = new QHash<QString, AbstractCentralWidget*>();
	//acwHash->insert("server", server);
	 chanTab->addServerWidget(server, "server");

    /* Positionnement des divers élèments */

	centralGrid->addWidget(currentTopic, 0, 0);
	centralGrid->addWidget(currentCentralWidget, 1, 0);
	centralGrid->addWidget(input, 2, 0);
	centralWrapper->setLayout(centralGrid);

	mainSplitter->addWidget(chanTab);
	mainSplitter->addWidget(centralWrapper);

	grid->addWidget(mainSplitter);

    setLayout(grid);

    /* Connection des signaux aux slots */
    //Edition d'un message
    connect(input,SIGNAL(returnPressed()),this,SLOT(getInputLine()));
    //Clique sur un chan
    connect(chanTab, SIGNAL(clicked(const QModelIndex&)),
    		this, SLOT(displayCentralWidget(const QModelIndex&)));
    //Edition du topic
    connect(currentTopic,SIGNAL(editingFinished()),
    		this,SLOT(changeTopic()));
    //Initiation d'un transfert
	connect(dccHandle,SIGNAL(sendCTCP(QString, QString)),
			this, SLOT(sendCTCP(QString,QString)));
	//Appuie sur TAB :
	connect(input, SIGNAL(tabPressed(QString)),
			this, SLOT(autoCompletion(QString)));
}

AbstractCentralWidget* MainWindow::getCenWidByName(QString name) {
	return chanTab->getCenWidByName(name);
}

/* Nombre d'arguments variables souhaitables */
QList<int> MainWindow::makeSizeList(int a, int b, int c) {
	QList<int> list;
	return list << a << b << c;
}

void MainWindow::displayCentralWidget(const QModelIndex& index) {
	/* NB POUR DEBILE : SI ITEM DEJA DANS SPLITTER ALORS INSERT CHANGE SA
	 * POSITION, DONC PAS DE SURCONSOMMATION !!!!!!
	 */
    QString name = chanTab->getName(index);
    clearWindow();

    QList<int>mainSizeList = mainSplitter->sizes();

    /* On cherche le nombre de non-zéro */
    int mainDefinedElemNb = mainSizeList.count() - mainSizeList.count(0);

    chanTabSize = mainSizeList.at(0);
    centerSplitterSize = mainSizeList.at(1);

	currentCentralWidget = getCenWidByName(name.toLower());
	currentCentralWidget->ensureCursorVisible();

    if (Chan::isNameChan(name)) {
    	currentNickList =
    			dynamic_cast<Chan*>(currentCentralWidget)->getNickList();
		currentTopic
			->setText(dynamic_cast<Chan*>(currentCentralWidget)->getTopic());
		currentTopic->setCursorPosition(0);

		mainSplitter->insertWidget(2,currentNickList);

		currentTopic->show();
		currentNickList->show();

		/* Correction de taille du splitter principal */
		if (mainDefinedElemNb == 2) { // Si on vient d'un pv
			centerSplitterSize -= nickListSize;
		} else {
			nickListSize = mainSizeList.at(2);
		}

    } else {
		if (mainDefinedElemNb == 3) { // On vient d'un chan
			nickListSize = mainSizeList.at(2);
			centerSplitterSize += nickListSize;
		}
    }
	currentCentralWidget->show();
    mainSplitter->setSizes(makeSizeList(chanTabSize, centerSplitterSize, nickListSize));
    setWindowTitle(name);
}

AbstractCentralWidget* MainWindow::createAcwHash(QString name) {
	if (getCenWidByName(name) == NULL) {
		AbstractCentralWidget *acw;
		clearWindow();
		if (Chan::isNameChan(name)) {
			acw = new Chan(name, centralWrapper);
			centralGrid->addWidget(acw, 1, 0);
			/* IMMONDE */
			connect(dynamic_cast<Chan*>(acw)->getNickList(), SIGNAL(nickDoubleClicked(QString)),
					this, SLOT(createAcwHash(QString)));
		} else {
			acw = new PrivateMessage(name, centralWrapper);
			centralGrid->addWidget(acw, 0, 0);
		}
		chanTab->addCentralWidget("server", acw);
		return acw;
	} else {
		return getCenWidByName(name);
	}
}

void MainWindow::clearWindow() {
	if (currentTopic != NULL) {
		currentTopic->hide();
	}
	if (currentCentralWidget != NULL) {
		currentCentralWidget->hide();
		currentCentralWidget = NULL;
	}
	if (currentNickList != NULL) {
		currentNickList->hide();
		currentNickList = NULL;
	}
}

void MainWindow::deleteChan(QString name) {
	if (name != "server") {
		qDebug("Ok deleting");
		chanTab->deleteChan("server", name);
		qDebug("Intra-deletion done");
		displayCentralWidget(chanTab->getServerIndex("server"));
		qDebug("Done");
		delete getCenWidByName(name); //Etrange deleteChan devrait le faire.
	}
}

void MainWindow::changeTopic() {
	if (dynamic_cast<Chan*>(currentCentralWidget)->getTopic() != currentTopic->text()) {
		qDebug("stub:Topic changed = %s",
				currentTopic->text().toUtf8().constData());
	}
}

void MainWindow::sendServer(QString message) {
	emit sendASCIIMessage(message);
}

void MainWindow::sendPv(QString dest, QString mess) {
	sendServer("PRIVMSG " + dest + " :" + mess + "\r\n");
}

void MainWindow::sendCTCP(QString dest, QString mess) {
	sendPv(dest, QString(QChar(0x001)) + mess + QString(QChar(0x001)));
}

QString MainWindow::findIp(QString mess) {
	QString ip;
	qDebug("Finding your web IP address in = %s", mess.toUtf8().constData());
	QRegExp matchingRegExp;
	matchingRegExp.setPattern("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");
	int pos = matchingRegExp.indexIn(mess);
	qDebug("index de l'ip = %d",pos);
	QStringList list = matchingRegExp.capturedTexts();
	QStringListIterator javaStyleIterator(list);
	while (javaStyleIterator.hasNext()) {
		ip = javaStyleIterator.next();
		qDebug("web ip = %s",ip.toUtf8().constData());
	}
	return ip;
}

QString MainWindow::findIpUserHost(QString mess) {
	QString ip;
	QRegExp matchingRegExp;
	matchingRegExp.setPattern("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\-\\d{1,3}");
	int pos = matchingRegExp.indexIn(mess);
	QStringList list2 = matchingRegExp.capturedTexts();
	QStringListIterator javaStyleIterator(list2);
	while (javaStyleIterator.hasNext()) {
		ip = javaStyleIterator.next();
		qDebug("userhost web ip = %s",ip.toUtf8().constData());
	}
	QStringList list = ip.split('.');
	ip = list.at(2).section('-',1, 1) + "." +
		 list.at(2).section('-', 0, 0) + "." +
		 list.at(1) + "." +
		 list.at(0);
	qDebug("userhost web ip = %s",ip.toUtf8().constData());
	return ip;
}

void MainWindow::displayToCurrentWidget(QString mess) {
	if (currentCentralWidget != NULL) {
		currentCentralWidget->write(mess);
	} else {
		qDebug("Impossible de trouver un acces ou afficher : %s",
			   mess.toUtf8().constData());
	}

}

void MainWindow::autoCompletion(QString line) {
	// On doit maintenant trouver le dernier mot :
	QString lastWord;
	if (line == NULL) {
		lastWord = "";
	} else {
		lastWord = line.split(' ',
				              QString::SkipEmptyParts,
							  Qt::CaseInsensitive)
												   .last();
	}
	// On va maintenant soit afficher la liste des pseudos possibles,
	// soit completer ac une partie ou la totalité des solutions possibles.
	if (currentNickList != NULL) {
		/* On cherche la liste des pseudos commençant par lastWord */
		QStringList nickList = currentNickList->getMatchingNicks(lastWord);
		/* On calcule la taille conservée dans la ligne de saisie,
		 * cad la taille totale de la saisie moins la taille du dernier mot.
		 */
		int keptLength = input->text().length() - lastWord.length();
		/* Si au moins un pseudo correspond a la description */
		if (nickList.size() >= 1) {
			/* Si un seul est possible, pas d'ambiguité */
			if (nickList.size() == 1) {
				input->setText(line.left(keptLength) + nickList.at(0));
			} else {
				/* Sinon, on essaye d'abord de trouver un tronc commun
				 * entre toutes les possibilités.
				 * Description :
				 * 	1. On démarre à partir du premier mot + 1 lettre
				 *  2. On considère la premiere possibilité de la liste
				 *     comme étant le tronc commun idéal (si tronc commun il
				 *     y a, alors le premier pseudo l'aura en totalité ou en
				 *     partie).
				 *  3. Tant que le premier pseudo tronqué de sa fin est un
				 *     tronc commun, on continue.
				 *  4. Si la liste des filtres correspondant aux troncs commun
				 *     est différente de la liste des pseudos possible, alors on
				 *     a été trop loin et on obtient aisin la longueur du tronc
				 *     commun + 1.
				 *
				 */
				int filterSize = lastWord.size() + 1;
				QStringList commonTruncList; // Liste des pseudos ayant un tronc
											 //	commun
				for (int i = filterSize; i <= nickList.at(0).size(); i++) {
					commonTruncList =
							nickList.filter(nickList.at(0).left(filterSize));
					if (commonTruncList.size() != nickList.size()) {
						filterSize -= 1;
						break;
					} else {
						filterSize += 1;
					}
				}
				// On affiche alors ce tronc commun.
				input->setText(
						line.left(keptLength) +
						nickList.at(0).left(filterSize));
				/* On va ensuite afficher l'ensemble des pseudos possibles */
				QStringListIterator it(nickList);
				// On créé un tas de pseudos afin de ne pas sonsommer trop
				// de lignes et n'utiliser qu'une seule fois la fonction
				// d'affichage assez lourde.
				QString nickBulk;
				while (it.hasNext()) {
					nickBulk += it.next() + "  ";
				}
				displayToCurrentWidget(nickBulk);
			}
		} else {
			qDebug("Aucun pseudo ne correspond");
		}
	} else {
		qDebug("Liste de pseudo inexistante.");
	}
}
