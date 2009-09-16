#include "List.h"

List::List(QWidget *parent = 0) : QTableView(parent) {
	setWindowTitle("Liste des chans");
	model = new QStandardItemModel(0, 4, this);
	model->setHorizontalHeaderItem(0, new QStandardItem("Nom"));
	model->setHorizontalHeaderItem(1, new QStandardItem("Utilisateurs"));
	model->setHorizontalHeaderItem(2, new QStandardItem("Modes"));
	model->setHorizontalHeaderItem(3, new QStandardItem("Topic"));

	/* On ne peut selectionner que ligne par ligne */
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::SingleSelection);

	/* On ne montre pas le cadrillage */
	setShowGrid(false);

	/* On peut trier par colonne */
	setSortingEnabled(true);

	/* On utilisera un proxy pour les tris */
	proxyModel = new QSortFilterProxyModel(this);
	proxyModel->setSourceModel(model);
	proxyModel->setSortCaseSensitivity(Qt::CaseInsensitive);
	setModel(proxyModel);

	verticalHeader()->hide();
	/* On interdit le changement de taille puisque la taille sera
	 * automatiquement la bonne */
	horizontalHeader()->setResizeMode(QHeaderView::Fixed);
}

void List::addChan(QString rawDesc) {
	show();
	QString *arg = parseChan(rawDesc);
	QStandardItem *chanNameItem = new QStandardItem(arg[0]);
	QStandardItem *chanUsersItem = new QStandardItem(arg[1]);
	QStandardItem *chanModeItem = new QStandardItem(arg[2]);
	QStandardItem *chanTopicItem = new QStandardItem(arg[3]);

	chanNameItem->setEditable(false);
	chanUsersItem->setEditable(false);
	chanModeItem->setEditable(false);
	chanTopicItem->setEditable(false);

	QList<QStandardItem*> rowList;
	rowList.append(chanNameItem);
	rowList.append(chanUsersItem);
	rowList.append(chanModeItem);
	rowList.append(chanTopicItem);

	model->appendRow(rowList);

	/* On remet a la bonne taille */
	resizeColumnsToContents();
	resizeRowsToContents();
}

//#Bankai-animes 4 :[+ntf]
QString* List::parseChan(QString rawDesc) {
	QString *argTab = new QString[10]();
	QString cursor;
	/* On a le nom du chan */
	argTab[0] = rawDesc.mid(rawDesc.indexOf('#'), rawDesc.indexOf(' '));
	cursor = rawDesc.right(rawDesc.length() - rawDesc.indexOf(' ') - 1);
	/* On a le nombre d'utilisateurs */
	argTab[1] = cursor.left(1);
	cursor = cursor.mid(cursor.indexOf(":") + 1,cursor.length());
	/* On a les modes du chan entre crochets */
	argTab[2] = cursor.mid(cursor.indexOf("["),cursor.indexOf(']') + 1);
	cursor = cursor.mid(cursor.indexOf("]") + 1, cursor.length());
	/* On a le topic si défini, sinon NULL (a vérif) */
	argTab[3] = AbstractMess::ircTools()->ircToPlainText(cursor);
	qDebug("chan = %s | user# = %s | modes = %s | topic = %s",
			argTab[0].toUtf8().constData(),
			argTab[1].toUtf8().constData(),
			argTab[2].toUtf8().constData(),
			argTab[3].toUtf8().constData());
	return argTab;

}

void List::clearAll(void) {
	model->clear();
}

void List::sortByName(void) {
	/* on trie */
	sortByColumn(0, Qt::AscendingOrder);
}
