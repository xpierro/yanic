/**
 * \file AbstractMess.h
 * \brief Header de AbstractMess.coo
 * \author Pierre Collignon
 * \version 0.1
 *
 * Déclaration de la classe AbstractMess, l'abstraction des messages IRC.
 *
 */

#ifndef ABSTRACT_H
#define ABSTRACT_H

#include <string.h>
#include <QHash>
#include <QString>
#include <QObject>

#include "Exceptions.h"

/*!
 * Les différents codes IRC utilisés.
 */
enum IRC_Codes {
	UNKNOWN_CODE,
	RPL_WELCOME = 1,
	RPL_YOURHOST,
	RPL_CREATED,
	RPL_MYINFO,
	RPL_BOUNCE,
	RPL_LUSERCLIENT = 251,
	RPL_LUSEROP,
	RPL_LUSERUNKNOWN,
	RPL_LUSERCHANNELS,
	RPL_LUSERME,
	RPL_USERHOST = 302,
	RPL_LIST = 322,
	RPL_ENDOF_LIST,
	RPL_MOTDSTART = 375,
	RPL_MOTD = 372,
	RPL_ENDOFMOTD = 376,
	RPL_WHOISHOST = 378,
	RPL_NAMREPLY = 353,
	TOPIC = 332,
	JOIN,
	PART,
	NOTICE,
	PRIVMSG,
	PING,
	PONG,
	LIST,
	ME,
	ACTION,
	FINGER,
	VERSION,
	SOURCE,
	QUIT,
	MODE
};

/*!
 * Codes de formattage.
 */
enum textFormatCodes {
	BOLD,
	ITALIC,
	UNDERLINE,
	SPAN
};

/*!
 * Direction entrée/sortie.
 */
enum direction {
	INPUT,
	OUTPUT
};

/*!
 * La structure donnant l'état actuel.
 */
typedef struct {
	bool frontColorSet; /*!< La couleur frontale est entrée.*/
	bool backColorSet; /*!< La couleur de fond est entrée.*/
	bool italic; /*!< Le texte est-il en italique? */
	bool bold; /*!< Le texte est-il en gras? */
	bool underlined; /*!< Le texte est-il souligné? */
	int frontCode; /*!< Le code couleur actuel. */
	int backCode; /*!< Le code couleur de fond actuel. */
} formatSet;

/*!
 * \class AbstractMess
 * \brief Abstraction du protocole IRC
 * Cette classe fournit des outils d'abstraction pour traduire les messages.
 */
class AbstractMess : public QObject {
	Q_OBJECT

private :

	QHash<int, QString> *hashColorsName;
	QHash<QString, IRC_Codes> *inHashMap;
	QHash<QString, IRC_Codes> *outHashMap;

	static AbstractMess *instance;

protected :

	/*!
	 * Constructeur de la classe d'abstraction de protocole.
	 * \param parent Le widget parent responsable de la suppression.
	 */
	AbstractMess(QObject *parent);

public :
	/*!
	 * Retourne le code associé a une commande.
	 * \param[in] code Commande à analyser.
	 * \param io Renvoie le typde de commande irc attendue (INPUT/OUTPUT).
	 * \return Le code IRC associé à la commande
	 */
	IRC_Codes getIdByCode(QString code, direction io);

	/*!
	 * Parse une commande et renvoie les arguments associés.
	 * \param[in] command La commande à parser.
	 * \param[out] orig L'origine de la transmission.
	 * \param[out] ircCode Le code de la commande.
	 * \param[out] recev Le destinataire du message.
	 * \param[out] arg Les arguments de la commande
	 */
	void inParser(QString command, QString& orig, QString& ircCode,
								  QString& recev, QString& arg);
	/*!
	 * Parse une commande et renvoie les arguments associés.
	 * \param[in] command La commande à parser.
	 * \param[out] code Le code de la commande.
	 * \param[out] arg Les arguments de la commande
	 */
	void outParser(QString command, QString& code, QString& arg);

	/*!
	 * Renvoie la couleur associé à un numéro.
	 * \param num Le numéro.
	 * \returns La couleur.
	 */
	QString getColorByNum(int num);

	/*!
	 * Initialise un objet de type formatSetInit.
	 * \param format La structure
	 */
	void formatSetInit(formatSet& format);

	/*!
	 * Transforme un texte formatté mirc en plaintext
	 */
	QString ircToPlainText(QString ircText);

	/*!
	 * Renvoie l'instance unique du singleton.
	 * \returns Cette instance.
	 */
	static AbstractMess* ircTools();
};

#endif
