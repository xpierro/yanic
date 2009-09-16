#ifndef CHANLIST_H
#define CHANLIST_H

#include <QHeaderView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QString>
#include <QTreeView>
#include <QHash>

#include "AbstractCentralWidget.h"

/*!
 * \class ChanList
 * \brief Représente une liste de canaux, sous forme d'arbre.
 */
class ChanList : public QTreeView {
	Q_OBJECT
private :
	QStandardItemModel *model;
	QHash<QString, QStandardItem*> *serverHash;
	QHash<QString, AbstractCentralWidget *> *centralWidHash;
	static ChanList *chanList;

protected :
	/*!
	 * \brief Constructeur de la classe.
	 * \param parent Le widget parent de la liste.
	 */
	ChanList(QWidget *parent);

public :

	/*!
	 * \brief Acces au singleton
	 */
	static ChanList *chanListHandle();

	/*!
	 * \brief Ajoute un canal à la liste.
	 * \param server Serveur du canal.
	 * \param name Nom du canal.
	 */
	void addChan(QString server, QString name);

	/*!
	 * \brief Ajoute un serveur à la liste.
	 * \param name Nom du serveur.
	 */
	void addServer(QString name);

	/*!
	 * \brief Supprime un canal de la liste.
	 * \param server Serveur du canal.
	 * \param name Nom du canal.
	 */
	void deleteChan(QString server, QString name);

	/*!
	 * \brief Renvoie la nom de l'élément associé à un index dans le modèle.
	 * \param index L'index dont on veut le nom.
	 * \returns Le nom associé à l'index dans le modèle.
	 */
	QString getName(const QModelIndex& index);

	/*!
	 * \brief Renvoie l'index du serveur dans le modèle.
	 * \param server Le nom du serveur.
	 * \returns L'index du serveur dans le modèle.
	 */
	QModelIndex getServerIndex(QString server);

	/*!
	 * \brief Renvoie l'index du canal.
	 * \param server Le serveur du canal.
	 * \param chan Le nom du canal.
	 * \returns L'index du canal dans le modèle.
	 */
	QModelIndex getChanIndex(QString server, QString chan);

	void addCentralWidget(QString server, AbstractCentralWidget *acw);
	AbstractCentralWidget* getCenWidByName(QString name);
	void addServerWidget(AbstractCentralWidget *server, QString name);

	QHashIterator<QString, AbstractCentralWidget*>* chanIterator(void);
};

#endif
