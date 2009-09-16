#ifndef LIST_H
#define LIST_H

#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QSortFilterProxyModel>

#include "src/tools/AbstractMess.h"

/*!
 * La liste des canaux.
 */
class List : public QTableView {
	Q_OBJECT

private :
	QStandardItemModel *model;
	QSortFilterProxyModel *proxyModel;
public :
	/*!
	 * Construit les différents éléments nécessaire à l'affichage d'une liste
	 * de canaux
	 * \param parent Le Widget responsable de la destruction.
	 */
	List(QWidget *parent);

public slots :
	/*!
	 * Ajoute un chan à la liste.
	 * \param rawDesc La description des propriétés d'un canal.
	 */
	void addChan(QString rawDesc);

	/*!
	 * Trie par colonne
	 */
	void sortByName(void);

	/*!
	 * Divise en tableau de parametres la description brute.
	 * \param rawDesc La description brute à parser
	 * \returns Le nom, le nombre d'utilisateurs, les modes et le topic d'un
	 *          canal.
	 */
	QString* parseChan(QString rawDesc);

	/*!
	 * Efface la liste.
	 */
	void clearAll(void);
};

#endif
