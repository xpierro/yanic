/**
 * \file MainWindow.h
 * \brief Implémentation de MainWindow.h
 * \author Pierre Collignon
 * \version 0.1
 *
 * Header de la classe MainWindow.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QHash>
#include <QLineEdit>
#include <QListWidget>
#include <QMenuBar>
#include <QMessageBox>
#include <QSplitter>
#include <QTextEdit>
#include <QWidget>
#include <string.h>

#include "../tools/AbstractMess.h"
#include "Chan.h"
#include "../tools/DccGet.h"
#include "List.h"
#include "Nickname.h"
#include "PrivateMessage.h"
#include "AbstractCentralWidget.h"
#include "ChanList.h"
#include "LineEdit.h"

#define TAILLE_MES 600 /*!< Décrit la taille maximale d'un message. */

/*!
 * \class MainWindow
 * \brief Widget central du client irc.
 * Met en cohérence tous les éléments (chan, liste de pseudo).
 */
class MainWindow : public QWidget {
	Q_OBJECT

private :
	/* Eléments graphiques */
	LineEdit *input; // barre de saisie des messages
	QGridLayout *grid; //la grille de positionnement
	QGridLayout *centralGrid;
    ChanList *chanTab; // Arbre des chans.
    PrivateMessage *server;
    AbstractCentralWidget *currentCentralWidget;
	QSplitter *mainSplitter;
    QLineEdit *currentTopic;
    NickList *currentNickList;
    List *chanList; // Liste des canaux.
    QWidget *centralWrapper; // Regroupe topic canal et input.

    /* Chaines */
	QString *nick; //mon pseudo
    QString webIP; // ip sur le WEB
    QString localIP; // ip locale

    /* Outils */
	//QHash<QString, AbstractCentralWidget*> *acwHash;
    DccGet *dccHandle;
    AbstractMess *ircTools;

    /* Informations sur la taille d'éléments */
    int chanTabSize;
    int centerSplitterSize;
    int nickListSize;
    int topicSize;
    int editSize;
    int centralWidgetSize;

public :
    /*!
     * \brief Constructeur
     * \param parent Widget parent.
     * Constructeur de la fenêtre.
     */
    MainWindow(QWidget *parent);

	/*!
	 * \brief Renvoie le widget central associé à name.
	 * \param name Le nom du widget
	 * \return Le widget central correspondant.
	 */
    AbstractCentralWidget* getCenWidByName(QString name);

public slots :
	/*!
	 * \brief Lit les commandes entrées au clavier.
	 */
	void getInputLine(void);

    /*!
     *  \brief Lit les messages envoyés par le serveur.
     *  \param bulk La masse de messages reçus en une fois.
     */
	void readServer(QString bulk);

	/*!
	 * Traduit une ligne reçue.
	 * \param line La ligne à traduire.
	 */
	void readLine(QString line);

    /*!
     * \brief Se connecte au serveur.
     * \param serv Nom du serveur.
     * \param port Numéro de port.
     * \param nick Pseudo de l'utilisateur.
     */
    void connexion(QString& serv, int port, QString& nick);

    /*!
     * \brief Afficher le chan selectionné dans la liste
     * \param index Index de l'élément dans le modèle de l'arbre des canaux.
     */
    void displayCentralWidget(const QModelIndex& index);

    /*!
     * \brief Change le topic affiché.
     */
    void changeTopic();

    /*!
     * Envoie un message brut au serveur.
     * \param message Le message
     */
    void sendServer(QString message);

    /*!
     * Envoie un message privé.
     * \param dest Le destinataire
     * \param mess Le message à envoyer.
     */
    void sendPv (QString dest, QString mess);

    /*!
     * Envoie une commande CTCP à un utilisateur.
     * \param dest Le destinataire.
     * \param mess Le message CTCP à envoyer.
     */
    void sendCTCP (QString dest, QString mess);

    /*!
     * Parse une commande à la recherche d'une ip.
     * \param mess Le message.
     * \returns L'ip
     */
    QString findIp (QString mess);

    /*!
     * Autre méthode pour rechercher son ip.
     * \param mess Le message
     * \returns L'ip.
     */
    QString findIpUserHost (QString mess);

    /*!
     * Supprime un chan de la liste de chans.
     * \param name Le nom du chan à supprimer.
     */
   void deleteChan(QString name);

   /*!
    * Affiche un message sur le widget central.
    * \param mess Le message à afficher.
    */
   void displayToCurrentWidget(QString mess);

   /*!
    * Créé un élément affichable.
    * \param name Le nom de l'élément.
    */
   AbstractCentralWidget* createAcwHash(QString name);

   void autoCompletion(QString line);

private :
   /*!
    * Créé une liste de taille à 3 éléments.
    */
   QList<int> makeSizeList(int a, int b, int c);

   /*!
	* Efface les informations propre au widget central.
	*/
    void clearWindow(void);

signals :

    /*!
     * Demande une connection - Devrait être obsolête d'ici peu.
     * \param server Le serveur.
     * \param port Le port.
     * \param nick Le pseudo.
     */
    void connectMe(const QString& server, int port, const QString& nick);
    /*!
     * Un erreur de connexion est apparue.
     */
    void connectError();

    /*!
     * On veut envoyer un message en clair au serveur.
     */
    void sendASCIIMessage(const QString& message);

};
#endif
