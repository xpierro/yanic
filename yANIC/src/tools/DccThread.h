#ifndef DDCTHREAD_H
#define DDCTHREAD_H

#include <QThread>
#include <QFile>
#include <QTcpSocket>
#include <QtEndian>
#include <QMessageBox>

/*!
 * \class DccThread
 * \brief Classe permettant le téléchargement par dcc simultané.
 */
class DccThread : public QThread {
	Q_OBJECT
private :
	int dccSocketDescriptor;
	QFile *dccFile;
	qint64 fileSize;
	QTcpSocket *dccSocket;
public :
	/*!
	 * Constructeur de la classe
	 * \param dccSocketDescriptor Le socket natif à lire.
	 * \param dccFile Le fichier à écrire.
	 * \param fileSize La taille du fichier.
	 * \param parent Le widget responsable de la destruction
	 */
	DccThread(int dccSocketDescriptor, QFile *dccFile,
			  int fileSize, QObject *parent);

	/*!
	 * Constructeur de la classe
	 * \param dccSocket Le QTcpSocket à lire.
	 * \param dccFile Le fichier à écrire.
	 * \param fileSize La taille du fichier.
	 * \param parent Le widget responsable de la destruction
	 */
	DccThread(QTcpSocket *dccSocket, QFile *dccFile,
			  int fileSize, QObject *parent);

	/*!
	 * Lis le socket puis ecris le fichier, et renvoie un "ACK" pour donner
	 * la taille téléchargée.
	 */
	void run();

signals :
	/*! Signale l'arrivée d'un nouveau bloc */
	void gotNewBytes(int);
};
#endif
