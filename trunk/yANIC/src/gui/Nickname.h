#ifndef NICKNAME_H
#define NICKNAME_H

#include <QString>
#include "src/tools/Exceptions.h"

/*!
 * \class Nickname
 * \brief Représente un pseudonyme.
 */
class Nickname {
private :
	QString nickname;
	QString ident;
	QString host;
	QString mode;


public :
	// NON SATISFAISANT : peut changer.

	/*!
	 * Décrit un opérateur de canal.
	 */
	static const char CHANOP = '@';
	/*!
	 * Décrit un semi-opérateur.
	 */
	static const char HOP = '%';
	/*!
	 * Décrit un voice.
	 */
	static const char VOICE = '+';
	/*!
	 * Décrit les propriétaires d'un canal.
	 */
	static const char OWNER = '~';
	/*!
	 * Décrit un admin.
	 */
	static const char ADMIN = '&';

	/*!
	 * Construit un pseudonyme à partir de l'identité.
	 * \param id L'identité à parser (ident @ host)
	 */
	Nickname(const QString& id);

	/*!
	 * Construit un pseudonyme à partir de l'identité et d'un mode.
	 * \param id L'identité.
	 * \param mode Le mode.
	 */
	Nickname(const QString& id, const QChar& mode);

	/*!
	 * Renvoie une description du pseudonyme.
	 * \returns Cette description.
	 */
	QString getNickname(void) const;

	/*!
	 * Renvoie le pseudonyme sans status.
	 */
	QString getLambdaNickname(void) const;

	/*!
	 * Associe un mode à ce pseudonyme.
	 * \param mode Le mode.
	 */
	void setMode(const QChar& mode);

	/*!
	 * Indique si je suis un opérateur.
	 */
	bool isChanop(void) const;
	/*!
	 * Indique si je suis semi operateur.
	 */
	bool isHop(void) const;
	/*!
	 * Indique si je suis voice.
	 */
	bool isVoice(void) const;
	/*!
	 * Indique si je suis propriétaire.
	 */
	bool isOwner(void) const;
	/*!
	 * Indique si je suis admin.
	 */
	bool isAdmin(void) const;
	/*!
	 * Indique si je n'ai aucun status particulier.
	 */
	bool isLambda(void) const;

	/*!
	 * Indique l'infériorité à status égal.
	 * \param that L'autre nickname.
	 */
	bool peerInf(const Nickname& that);

	/*!
	 * Infériorité absolue.
	 */
	bool operator < (const Nickname& that);
	/*!
	 * Supériorité absolue.
	 */
	bool operator > (const Nickname& that);
	/*!
	 * Egalité absolue.
	 */
	bool operator == (const Nickname& that);
	/*!
	 * Inférieur ou égal.
	 */
	bool operator <= (const Nickname& that);
	/*!
	 * Supérieur ou égal.
	 */
	bool operator >= (const Nickname& that);
};

#endif
