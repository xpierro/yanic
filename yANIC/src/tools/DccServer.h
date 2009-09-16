#ifndef DCC_H
#define DCC_H

#include <QTcpSocket>
#include <QFile>
#include <QWidget>
#include <QHostAddress>
#include <QProgressBar>
#include <QTcpServer>
#include <QtEndian>
#include <QApplication>
#include <QThread>
#include <QMessageBox>
#include "DccThread.h"

/*!
 * \class DccServer
 * \brief Classe permettant le Reverse DCC, ouvre un serveur en ecoute et attend
 * des connection entrante.
 */
class DccServer : public QTcpServer {
	Q_OBJECT
private :
	int portNum;
	int fileSize;
	QFile *dldedFile;
	QString ip;
	QProgressBar *progressBar;

public :
	/*!
	 * Construit le serveur.
	 * \param ip L'ip du receveur, inutile pour l'instant.
	 * \param port Le port à ecouter, devrait changer à
	 *             chaque nouvelle connexion.
	 * \param parent Le widget responsable de la destruction.
	 */
	DccServer(QString ip, int port, QObject *parent);

public slots :
	/*!
	 * Change les parametres du serveur en préparation d'une réception.
	 * \param dldedFile Le fichier à télécharger sur le disque.
	 * \param fileSize La taille du fichier.
	 * \param progressBar La barre de progression.
	 */
	void setNewConnection(QFile *dldedFile, int fileSize,
						  QProgressBar *progressBar);

protected:
	/*!
	 * Surchage de la fonction des QTcpServer.
	 * \param socketDescriptor Le socket natif.
	 */
     void incomingConnection(int socketDescriptor);

};
#endif
