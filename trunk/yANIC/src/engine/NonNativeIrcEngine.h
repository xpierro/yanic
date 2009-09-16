#ifndef NNIE_H
#define NNIE_H

#include "IIrcEngine.h"
#include "QTcpSocket"

#include <QMessageBox>

/*!
 * Classe permettant d'avoir un ircEngine multi-plateforme.
 */
class NonNativeIrcEngine : public IIrcEngine {
	Q_OBJECT
private :
	QTcpSocket *sock;
	bool connected;
	static NonNativeIrcEngine *instance;

	/*!
	 * Lit une ligne sur le socket.
	 * \param[out] line La ligne capturée.
	 * \param[in] lSize La taille de la ligne.
	 * \returns Vrai si une ligne a été lue.
	 */
	bool readLine(char *line, qint64 lSize);

protected :
	/*!
	 * Le constructeur.
	 */
	NonNativeIrcEngine(void);

public :
	/*!
	 * Renvoie l'instance unique du singleton.
	 * \returns Cette instance.
	 */
	static NonNativeIrcEngine* engine();

public slots :
	/*!
	 * Envoie un message texte au socket.
	 * \param mess Le message à envoyer.
	 */
	virtual void sendASCIIMessage(const QString& mess);

	/*!
	 * Interface de readLine, permet d'utiliser une QString.
	 * \param[out] lineStr La ligne lue.
	 * \returns La valeur de retour de readLine.
	 */
	virtual bool returnLine(QString& lineStr);

	/*!
	 * Se connecte au serveur irc distant.
	 * \param host L'hôte distant.
	 * \param port Le port utilisé.
	 */
	virtual void connectToHost(QString host, int port);

	/*!
	 * Une ligne peut-elle etre lue?
	 * \returns La réponse à cette question.
	 */
	virtual bool canReadLine();

	/*!
	 * Indique si le moteur est connecté.
	 * \returns L'etat de la connexion.
	 */
	virtual bool isConnected();

	virtual void initiateConnection(const QString& server,
									int port,
									const QString& nick);

private slots :
	void relayReadyRead();

signals :
	/*!
	 * Signal émis quand une ligne est prête.
	 */
	virtual void lineReceived(QString);

	/*!
	 * Signal émis quand la connexion est impossible.
	 */
	virtual void connectError();
};

#endif
