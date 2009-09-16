/**
 * \file Chan.cpp
 * \brief Implémentation de Chan.h
 * \author Pierre Collignon
 * \version 0.1
 *
 * Implémentation de la classe Chan permettant la gestion d'un canal IRC.
 *
 */
#include "Chan.h"

Chan::Chan(const QString& name,QWidget *parent=0) : AbstractCentralWidget(parent){
	nickList = new NickList(this);
    nickList->setSortingEnabled (false); //purée...
    topic = "";
    this->name = name;
}

NickList* Chan::getNickList(void){
	qDebug("capturing the nickList");
	return nickList;
}

QString Chan::getName(void) {
	return name;
}

void Chan::setTopic(QString topic) {
	if (topic == NULL) {
		throw IllegalArgumentException("Le topic est vide.");
	}
	this->topic = topic;
	emit topicChanged();
}

QString Chan::getTopic(void){
    return topic;
}

void Chan::addNickname(Nickname nick) {
	if (nick.getNickname() == "") {
		throw IllegalArgumentException("Pseudonyme vide.");
	}
	qDebug("adding in channel %s : %s",getName().toUtf8().constData(), nick.getNickname().toUtf8().constData());
	getNickList()->addNickname(nick);
}

void Chan::removeNickname(const Nickname& nick) {
	if (nick.getNickname() == NULL) {
		throw IllegalArgumentException("Pseudonyme vide.");
	}
	qDebug("removing nickname");
	if (getNickList()->contains(nick)) {
		qDebug("the nickList contains me");
		getNickList()->removeNickname(nick);
	}
}

/*!< Le mode devrait etre codé dans le nickaname */
void Chan::changeMode(Nickname nick, const QString& mode) {
	if (nick.getNickname() == NULL) {
		throw IllegalArgumentException("Pseudonyme vide.");
	}
	if (mode == NULL || mode.length() <= 0) {
		throw IllegalArgumentException("Mode vide.");
	}
	if (mode[0] == '+') {
		qDebug("adding a mode");
		getNickList()->addMode(nick, mode[1]);
	}
}

bool Chan::isNameChan(const QString& name) {
	if (name == NULL) {
		throw IllegalArgumentException("Ce n'est pas un nom.");
	}
	return name[0] == '#' || name[0] == '&';
}
