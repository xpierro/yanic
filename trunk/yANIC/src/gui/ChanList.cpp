#include "ChanList.h"

ChanList::ChanList(QWidget *parent = 0) : QTreeView(parent) {
	model = new QStandardItemModel(0, 0, this);
	serverHash = new QHash<QString, QStandardItem*>();
	centralWidHash = new QHash<QString, AbstractCentralWidget*>();

	/* On ne peut selectionner que ligne par ligne */
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::SingleSelection);

	setModel(model);

	header()->hide(); // Un seul header ...

	/* On interdit le changement de taille puisque la taille sera
	 * automatiquement la bonne */
	header()->setResizeMode(QHeaderView::Fixed);
	show();
}

ChanList* ChanList::chanList = NULL;

ChanList* ChanList::chanListHandle() {
	if (chanList == NULL) {
		chanList = new ChanList(NULL);
	}
	return chanList;
}

void ChanList::addChan(QString server, QString name) {
	QStandardItem *item = new QStandardItem(name);
	serverHash->find(server).value()->appendRow(item);
	/* On selectionne le chan dans l'arbre */
	selectionModel()->clearSelection();
	selectionModel()->select(item->index(), QItemSelectionModel::Select);
	expandAll(); /* /!\ MULTISERVER INCOMPATIBLE /!\ */
	emit clicked(getChanIndex(server, name));
}

/* Le nom du serveur devrait être dans chan */
void ChanList::addCentralWidget(QString server, AbstractCentralWidget *acw) {
	centralWidHash->insert(acw->getName().toLower(), acw);
	addChan(server, acw->getName());
}

AbstractCentralWidget* ChanList::getCenWidByName(QString name) {
	qDebug("Name to obtain : %s", name.toLower().toUtf8().constData());
	return centralWidHash->value(name.toLower());
}

void ChanList::addServer(QString name) {
	QStandardItem *item = new QStandardItem(name);
	serverHash->insert(name, item);
	selectionModel()->clearSelection();
	model->appendRow(item);
	selectionModel()->select(item->index(), QItemSelectionModel::Select);
}

void ChanList::addServerWidget(AbstractCentralWidget *server, QString name) {
	centralWidHash->insert(name, server);
	addServer(name);
}

void ChanList::deleteChan(QString server, QString name) {
	QStandardItem *serverItem = serverHash->find(server).value();
	QStandardItem *childItem = NULL;
	for (int row = 0; row < serverItem->rowCount(); row++) {
		childItem = serverItem->child(row, 0);
		if (childItem->text() == name) { // On a trouvé le chan
			selectionModel()->clearSelection();
			selectionModel()
				->select(serverItem->index(), QItemSelectionModel::Select);
			delete serverItem->takeChild(row, 0);
			serverItem->removeRow(row);

			centralWidHash->remove(name);

			break;
		}
	}
}

QString ChanList::getName(const QModelIndex& index) {
	qDebug("Row : %d | Column : %d", index.row(), index.column());
	/* Si l'index a un parent, alors c'est un sous-objet,
	 * sinon c'est un parent
	 */
	if (!index.parent().isValid()) {
		return(model->item(index.row(), 0))->text();
	} else {
		return model->item(index.parent().row(), 0)
					->child(index.row(), index.column())->text();
	}
}

QModelIndex ChanList::getServerIndex(QString server) {
	return model->findItems(server, Qt::MatchExactly, 0)[0]->index();
}

QModelIndex ChanList::getChanIndex(QString server, QString chan) {
	QStandardItem *serverItem = serverHash->find(server).value();
	QStandardItem *childItem = NULL;
	for (int row = 0; row < serverItem->rowCount(); row++) {
		childItem = serverItem->child(row, 0);
		if (childItem->text() == chan) { // On a trouvé le chan
			return childItem->index();
		}
	}
	return QModelIndex();
}

QHashIterator<QString, AbstractCentralWidget*>* ChanList::chanIterator(void) {
	return new QHashIterator<QString, AbstractCentralWidget*>(*centralWidHash);
}
