#ifndef IIRE_H
#define IIRE_H

#include <QObject>
/*!
 * \class IIrcEngine
 * \brief Interface décrivant un moteur IRC.
 */

class IIrcEngine : public QObject {
	Q_OBJECT
public slots:
	/*!
	 * \brief Envoie un message standard au serveur.
	 * Le fait de terminer ou non pas une fin de ligne est à définir.
	 * \param mess Le message à envoyer.
	 */
	virtual void sendASCIIMessage(const QString& mess) = 0;

	/*!
	 * \brief Lit une ligne du serveur.
	 * \param lineStr La référence de la chaine enregistrant la ligne.
	 * \returns Un booleen indiquant le succes de l'opération de lecture.
	 */
	virtual bool returnLine(QString& lineStr) = 0;

	/*!
	 * \brief Initie la connexion avec un hote distant.
	 * \param host L'adresse ip de l'hôte en format chaine aaa.aaa.aaa.aaa
	 * \param port Le port sur lequel se connecter.
	 */
	virtual void connectToHost(QString host, int port) = 0;

	/*!
	 * \brief Indique si une ligne peut être lue sur le serveur.
	 * \returns La réponse à la question "peut-on lire une ligne?".
	 */
	virtual bool canReadLine() = 0;

	/*!
	 * \brief Indique l'état de la connexion à l'hôte distant.
	 * \returns L'état de la connexion.
	 */
	virtual bool isConnected() = 0;

	/*!
	 * \brief Permet d'initier une connexion IRC de A à Z
	 * \param host Le serveur où se connecter.
	 * \param port Le port à utiliser.
	 * \param nick Le pseudonyme à utiliser.
	 */
	virtual void initiateConnection(const QString& host,
									int port,
									const QString& nick) = 0;

signals :

	/*!
	 * Est émis quand une ligne est reçue.
	 */
	virtual void lineReceived(QString) = 0;

	/*!
	 * Est émis quand une erreur survient.
	 */
	virtual void connectError(void) = 0;
};

#endif
