#include "MainWindowView.h"

MainWindowView::MainWindowView(MainWindow *mW, QWidget *parent = 0)
														: QMainWindow(parent) {
	this->mW = mW;
	/* On place mW au centre de la fenêtre */
	setCentralWidget(mW);
	/* On initialise la barre de menu */
	fileMenu = menuBar()->addMenu("&yANIC");
	serverMenu = menuBar()->addMenu("&Serveur");
	paramMenu = menuBar()->addMenu("&Parametres");
	windowMenu = menuBar()->addMenu("&Fenetre");
	helpMenu = menuBar()->addMenu("&Aide");
	/* On ajoute les actions */
	exitAction = new QAction("&Exit",this);
	fileMenu->addAction(exitAction);
	listAction = new QAction("&Liste des canaux", this);
	serverMenu->addAction(listAction);

    connect(exitAction, SIGNAL(triggered()), this, SLOT(quit()));
	connect(listAction, SIGNAL(triggered()), this, SLOT(list()));
    menuBar()->show();
}

void MainWindowView::quit() {
	exit(0);
}

void MainWindowView::list() {
	mW->sendServer("LIST\r\n");
}
