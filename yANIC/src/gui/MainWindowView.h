#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include "MainWindow.h"

/*!
 * \class MainWindowView
 * \brief Classe enveloppant les widgets.
 */
class MainWindowView : public QMainWindow {
	Q_OBJECT

private:
	QAction *exitAction;
	QAction *listAction;
	QMenu *fileMenu;
	QMenu *windowMenu;
	QMenu *helpMenu;
	QMenu *paramMenu;
	QMenu *serverMenu;
	MainWindow *mW;

public :
	/*!
	 * \param mW Le widget central.
	 * \param parent Le parent de la classe.
	 * Constructeur de la classe MainWindowView.
	 */
	MainWindowView(MainWindow* mW, QWidget *parent);

public slots :
	/*!
	 * Gère la fermeture de l'application.
	 */
	void quit(void);

	/*!
	 * Demande la liste des chans du serveur.
	 */
	void list(void);
};
#endif
