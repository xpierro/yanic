#ifndef NICKLIST_H
#define NICKLIST_H

#include <QListIterator>
#include <QListWidget>
#include <QListWidgetItem>
#include <QList>

#include "Nickname.h"

/*!
 * \class NickList
 * \brief Représente une liste de pseudo.
 */
class NickList : public QListWidget {
	Q_OBJECT

public :
	/*!
	 * \brief Le constructeur de la classe.
	 * \param parent Parent de la classe.
	 */
	NickList(QWidget *parent);

	/*!
	 * \brief Ajoute un pseudo à la liste.
	 * \param nick Le pseudo à ajouter.
	 */
	void addNickname(Nickname nick);

	/*!
	 * \brief Enlève un pseudo de la liste.
	 * \param nick Le pseudo à enlever.
	 */
	void removeNickname(Nickname nick);

	/*!
	 * \brief Indique si la liste contient le pseudo.
	 * \param nick Le pseudo à trouver.
	 * \returns Vrai si le pseudo est dans la liste.
	 */
	bool contains(Nickname nick);

	/*!
	 * BETA
	 * \brief Change le mode de l'utilisateur (et donc son préfixe)
	 * \param nick Le pseudo ou le changement doit s'appliquer.
	 * \param mode Le mode à appliquer.
	 */
	void addMode(Nickname nick, QChar mode);

	/*!
	 * Traduit un index en pseudonyme.
	 * \param index L'index a traduire.
	 * \return le Nickname associé.
	 */
	QString indexToNick(const QModelIndex& index);

	/*!
	 * Renvoie la liste des pseudonymes correspondants.
	 * \param beginWith Le début des pseudonymes.
	 * \returns La liste validant l'expression.
	 */
	QStringList getMatchingNicks(QString beginWith);

private slots :
	void relayNickDoubleClicked(const QModelIndex& index);

signals :
	/*!
	 * Emis quand un nick est double clické.
	 */
	void nickDoubleClicked(QString);
};


#endif
