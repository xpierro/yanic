#include "NickList.h"

NickList::NickList(QWidget *parent = 0) : QListWidget(parent) {
	connect(this, SIGNAL(doubleClicked(const QModelIndex&)),
			this, SLOT(relayNickDoubleClicked(const QModelIndex&)));
}

void NickList::addNickname(Nickname nick) {
	qDebug("In nicklist, trying to add a nick");
	bool inserted = false;
	for (int row = 0; row < count(); row++) {
		Nickname nickInList(item(row)->text());
		if (nick >= nickInList) {
			insertItem(row, nick.getNickname());
			inserted = true;
			qDebug("inserted %s before %s", nick.getNickname().toUtf8().constData(), nickInList.getNickname().toUtf8().constData());
			break;
		}
	}
	if (!inserted) {
		addItem(nick.getNickname());
		qDebug("inserted %s at the end", nick.getNickname().toUtf8().constData());
	}
}

void NickList::removeNickname(Nickname nick) {
	// On suppose qu'il ne peut y avoir qu'un seul pseudo.
	qDebug("in nickList, removing nick %s", nick.getNickname().toUtf8().constData());
	delete takeItem(row(findItems("[@+&~%]*"+ nick.getNickname(),Qt::MatchRegExp)[0]));
}

bool NickList::contains(Nickname nick) {
	return !(findItems("[@+&~%]*" + nick.getNickname(),Qt::MatchRegExp).isEmpty());
}

void NickList::addMode(Nickname nick, QChar mode) {
	removeNickname(nick);
	qDebug("removed old nick, adding new");
	addNickname(Nickname(nick.getNickname(), mode));
}

void NickList::relayNickDoubleClicked(const QModelIndex& index) {
	qDebug("A nickname got clicked.");
	emit nickDoubleClicked(indexToNick(index));
}

QString NickList::indexToNick(const QModelIndex& index) {
	return Nickname(itemFromIndex(index)->text()).getLambdaNickname();
}

QStringList NickList::getMatchingNicks(QString beginWith) {
	QList<QListWidgetItem*> mediaList =
			findItems("^[@+&~%]*" + beginWith + ".*", Qt::MatchRegExp);
	QStringList matchingNicks;
	QListIterator<QListWidgetItem*> it(mediaList);
	while (it.hasNext()) {
		matchingNicks.append(Nickname(it.next()->text()).getLambdaNickname());
	}
	return matchingNicks;
}
