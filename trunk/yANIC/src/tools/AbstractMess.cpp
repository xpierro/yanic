/**
 * \file AbstractMess.cpp
 * \brief Implémentation de AbstractMess.h
 * \author Pierre Collignon
 * \version 0.1
 *
 * Implémentation de la classe AbstractMess, l'abstraction des messages IRC.
 *
 */
#include "AbstractMess.h"

AbstractMess::AbstractMess(QObject *parent = 0) : QObject(parent) {
	inHashMap = new QHash<QString, IRC_Codes>();
	inHashMap->insert("001", RPL_WELCOME);
	inHashMap->insert("002", RPL_YOURHOST);
	inHashMap->insert("003", RPL_CREATED);
	inHashMap->insert("004", RPL_MYINFO);
	inHashMap->insert("005", RPL_BOUNCE);
	inHashMap->insert("251", RPL_LUSERCLIENT);
	inHashMap->insert("252", RPL_LUSEROP);
	inHashMap->insert("253", RPL_LUSERUNKNOWN);
	inHashMap->insert("254", RPL_LUSERCHANNELS);
	inHashMap->insert("255", RPL_LUSERME);
	inHashMap->insert("302", RPL_USERHOST);
	inHashMap->insert("322", RPL_LIST);
	inHashMap->insert("323", RPL_ENDOF_LIST);
	inHashMap->insert("332", TOPIC);
	inHashMap->insert("353", RPL_NAMREPLY);
	inHashMap->insert("372", RPL_MOTD);
	inHashMap->insert("375", RPL_MOTDSTART);
	inHashMap->insert("376", RPL_ENDOFMOTD);
	inHashMap->insert("378", RPL_WHOISHOST);
	inHashMap->insert("NOTICE", NOTICE);
	inHashMap->insert("PRIVMSG", PRIVMSG);
	inHashMap->insert("PING", PING);
	inHashMap->insert("PONG", PONG);
	inHashMap->insert("JOIN", JOIN);
	inHashMap->insert("PART", PART);
	inHashMap->insert("QUIT", QUIT);
	inHashMap->insert("MODE", MODE);

	outHashMap = new QHash<QString, IRC_Codes>();
	outHashMap->insert("JOIN", JOIN);
	outHashMap->insert("join", JOIN);
	outHashMap->insert("j", JOIN);
	outHashMap->insert("J", JOIN);
	outHashMap->insert("PART", PART);
	outHashMap->insert("part", PART);
	outHashMap->insert("p", PART);
	outHashMap->insert("P", PART);
	outHashMap->insert("LIST", LIST);
	outHashMap->insert("list", LIST);
	outHashMap->insert("L", LIST);
	outHashMap->insert("l", LIST);
	outHashMap->insert("me", ME);
	outHashMap->insert("ME", ME);
	outHashMap->insert("finger", FINGER);
	outHashMap->insert("FINGER", FINGER);
	outHashMap->insert("VERSION", VERSION);
	outHashMap->insert("version", VERSION);
	outHashMap->insert("SOURCE", SOURCE);
	outHashMap->insert("source", SOURCE);

	hashColorsName = new QHash<int, QString>();
	hashColorsName->insert(0, "white");
	hashColorsName->insert(1, "black");
	hashColorsName->insert(2, "darkblue");
	hashColorsName->insert(3, "darkgreen");
	hashColorsName->insert(4, "red");
	hashColorsName->insert(5, "darkred");
	hashColorsName->insert(6, "magenta");
	hashColorsName->insert(7, "orange");
	hashColorsName->insert(8, "gold");
	hashColorsName->insert(9, "lightgreen");
	hashColorsName->insert(10, "cyan");
	hashColorsName->insert(11, "lightcyan");
	hashColorsName->insert(12, "lightblue");
	hashColorsName->insert(13, "pink");
	hashColorsName->insert(14, "gray");
	hashColorsName->insert(15, "lightslategray");

}

AbstractMess* AbstractMess::instance = 0;

AbstractMess* AbstractMess::ircTools() {
	if (instance == 0) {
		instance = new AbstractMess(NULL);
	}
	return instance;
}

IRC_Codes AbstractMess::getIdByCode(QString code, direction io) {
	if (code == NULL) {
		return UNKNOWN_CODE;
	}
	if (io == INPUT) {
		if (inHashMap->contains(code)) return inHashMap->value(code);
	}
	if (io == OUTPUT) {
		if (outHashMap->contains(code)) return outHashMap->value(code);
	}
	return UNKNOWN_CODE;
}

QString AbstractMess::getColorByNum(int num) {
	return hashColorsName->value(num);
}

void AbstractMess::inParser(QString command, QString& orig, QString& ircCode,
							  QString& recev, QString& codeArg) {
	if (command == NULL) {
		throw IllegalArgumentException("Commande nulle.");
	}
	QString *prefix;
	QString *code;
	QString *suffix;
	QString *dest;
	QString cursor = command;
	//Testons la présence d'un préfixe en début de ligne.
	if (command.mid(0,1) == ":") { //On enregiste l'argument
		prefix = new QString(command.mid(1,command.indexOf(" "))); //ok
		cursor = command.mid(command.indexOf(' ',1) + 1, command.length());
		code = new QString(cursor.mid(0,cursor.indexOf(" ")));
		cursor = cursor.mid(cursor.indexOf(' ',1) + 1, cursor.length());
		dest = new QString(cursor.mid(0,cursor.indexOf(" ")));
		cursor = cursor.mid(cursor.indexOf(' ',1) + 1, cursor.length());
		if (cursor[0] == ':') { //Si suffixe standard
			cursor = cursor.right(cursor.length() - 1);
		}
		suffix = new QString(cursor);
		orig = *prefix;
		ircCode = *code;
		recev = *dest;
		codeArg = *suffix;
		qDebug("orig = %s | ircCode = %s | recev = %s | codeArg = %s",
				prefix->toUtf8().constData(), code->toUtf8().constData(),
				dest->toUtf8().constData(), suffix->toUtf8().constData());
	}
}

void AbstractMess::outParser(QString command, QString& code, QString& arg) {
	if (command == NULL) {
		throw IllegalArgumentException("Saisie clavier nulle.");
	}
	code = command.mid(1,command.indexOf(' ') -1);
	arg = command.mid(command.indexOf(' ') + 1, command.length());
	qDebug("code = %s | arg = %s", code.toUtf8().constData(),
					arg.toUtf8().constData());
}

void AbstractMess::formatSetInit(formatSet& format) {
		format.backCode = 0;
		format.backColorSet = false;
		format.bold = false;
		format.frontCode = 0;
		format.frontColorSet = 0;
		format.italic = false;
		format.underlined = false;
	}

QString AbstractMess::ircToPlainText(QString ircText) {
	QString plainMessage;
	plainMessage = "";

	for (int index = 0; index < ircText.length(); index++) {
		if (ircText[index] >= ' ') { //char normal
			plainMessage += ircText[index];
			continue;
		}
		if (ircText[index] == QChar(0x001F)) {
			continue;
		}
		if (ircText[index] == QChar(0x003)) {
			index++;
			while (ircText[index] >= '0' && ircText[index] <= '9') {
				index++;
			}
			if (ircText[index] == ',') {
				index++;
				while (ircText[index] >= '0' && ircText[index] <= '9') {
					index++;
				}
			}
			index--;
			continue;
		}

		if (ircText[index] == QChar(0x009)) {
			continue;
		}

		if (ircText[index] == QChar(0x002)) {
			continue;
		}
		if (ircText[index] == QChar(0x00F)) {
			continue;
		}
	}
	qDebug(plainMessage.toUtf8().constData());
	return plainMessage;
}
