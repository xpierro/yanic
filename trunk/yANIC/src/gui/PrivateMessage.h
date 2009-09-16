#ifndef PV_H
#define PV_H

#include "AbstractCentralWidget.h"

/*!
 * \class PrivateMessage
 * \brief Réprésente un message privé.
 */
class PrivateMessage : public AbstractCentralWidget {
	Q_OBJECT

private :
	QString name;
public :
	/*!
	 * Construit un nouveau message privé.
	 */
	PrivateMessage(const QString& name, QWidget *parent);

	QString getName(void);

};



#endif
