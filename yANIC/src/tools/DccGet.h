#ifndef DCCGET_H
#define DCCGET_H

#include "DccServer.h"

/*!
 * \class DccGet
 * \brief Permet d'initier un transfert entrant en DCC.
 */
class DccGet : public QObject {
	Q_OBJECT
private :
	DccServer *dccServer;
	static DccGet *instance;

protected :
	/*!
	 * Constructeur de la classe
	 * \param parent Le widget responsable de la destruction.
	 */
	DccGet(QObject *parent);

public :
	/*!
	 * Renvoie l'instance unique du singleton.
	 * \returns Cette instance.
	 */
	static DccGet* dccHandle();

public slots:
	/*!
	 * Telecharge un fichier
	 * \param orig Personne envoyant.
	 * \param mess Le message DCC contenant les informations.
	 * \param progressBar La barre de progression associée.
	 * \param myIP L'ip du receveur en cas de reverse DCC.
	 */
	void download(QString orig, QString mess, QProgressBar *progressBar, QString myIP);

signals :
	/*!
	 * Signal émit lorqu'un message CTCP doit etre envoyé.
	 */
	void sendCTCP(QString, QString);
};

#endif
