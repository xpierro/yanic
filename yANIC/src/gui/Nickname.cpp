#include "Nickname.h"

Nickname::Nickname(const QString& id) {
	if (id == NULL) {
		throw IllegalArgumentException("Ce pseudo ne peut être créé");
	}
	if (!id.contains('!')) {
		nickname = id;
	} else {
		nickname = id.section('!',0,0);
		ident = id.section('@',0,0).section('!',1,1);
		host = id.section('@',1);
	}
}

Nickname::Nickname(const QString& id, const QChar& mode) {
	if (id == NULL) {
		throw IllegalArgumentException("Ce pseudo ne peut être créé.");
	}
	if (mode == NULL) {
		throw IllegalArgumentException("Ce mode est invalide.");
	}
	qDebug("Builing %s as a new Nickname", id.toUtf8().constData());
	if (!id.contains('!')) {
		nickname = id;
	} else {
		nickname = id.section('!',0,0);
		ident = id.section('@',0,0).section('!',1,1);
		host = id.section('@',1);
	}
	if (mode == 'o') {
		qDebug("we have an op as %s",id.toUtf8().constData());
		nickname = CHANOP + id;
	} else {
		if (mode == 'v') {
			nickname = VOICE + id;
		}
	}
}

QString Nickname::getNickname() const {
	return nickname;
}

QString Nickname::getLambdaNickname() const {
	if (isLambda()) {
		return getNickname();
	} else {
		return getNickname().right(getNickname().length() - 1);
	}
}

void Nickname::setMode(const QChar& mode) {
	if (mode == NULL) {
		throw IllegalArgumentException("Mode indéfini.");
	}
	this->mode += mode;
}

bool Nickname::isAdmin() const {
	return nickname[0] == ADMIN;
}

bool Nickname::isChanop() const {
	return nickname[0] == CHANOP;
}

bool Nickname::isVoice() const {
	return nickname[0] == VOICE;
}

bool Nickname::isHop() const {
	return nickname[0] == HOP;
}

bool Nickname::isOwner() const {
	return nickname[0] == OWNER;
}

bool Nickname::isLambda() const {
	return (nickname[0] >= 'a' && nickname[0] <= 'z') ||
		   (nickname[0] >= 'A' && nickname[0] <= 'Z');
}

bool Nickname::peerInf (const Nickname& that) { // Attention, inférieur signifie plus
										  // bas dans la liste, donc chaine
										  // supérieure...pas clair a changer
	return this->getNickname().toUpper() > that.getNickname().toUpper();
}

bool Nickname::operator < (const Nickname& that) {
	if (this->isLambda()) {
		if (that.isLambda()) {
			return peerInf(that);
		}
		return true;
	}

	if (this->isVoice()) {
		if (that.isVoice()) {
			return peerInf(that);
		}
		if (that.isLambda()) {
			return false;
		}
		return true;
	}

	if (this->isChanop()) {
		if (that.isLambda() || that.isVoice() || that.isHop()) {
			return false;
		}
		if (that.isChanop()) {
			return peerInf(that);
		}
		return true;
	}

	if (this->isHop()) {
		if (that.isLambda() || that.isVoice()) {
			return false;
		}
		if (that.isHop()) {
			return peerInf(that);
		}
		return true;
	}

	if (this->isOwner()) {
		if (that.isOwner()) {
			return peerInf(that);
		}
		return false;
	}

	if (this->isAdmin()) {
		if (that.isOwner()) {
			return true;
		}
		if (that.isAdmin()) {
			return peerInf(that);
		}
		return false;
	}
	return true;
}

bool Nickname::operator > (const Nickname& that) {
	return !(this->operator <(that));
}

bool Nickname::operator == (const Nickname& that) {
	return (this->getNickname() == that.getNickname());
}

bool Nickname::operator <= (const Nickname& that) {
	return (this->operator ==(that) || this->operator <(that));
}

bool Nickname::operator >= (const Nickname& that) {
	return (this->operator ==(that) || this->operator >(that));
}
