#ifndef ACWID_H
#define ACWID_H

#include <QString>
#include <QPalette>
#include <QTextEdit>
#include <QStack>
#include "src/tools/Exceptions.h"
#include "src/tools/AbstractMess.h"
#include "Nickname.h"

/*!
 * Classe regroupant les caracteristiques communes d'un widget central.
 */
class AbstractCentralWidget : public QTextEdit {
	Q_OBJECT
private :
	AbstractMess *colorAbstraction;
	QStack<textFormatCodes> *formatStack;
	QString currentOpenedSpan;

public :
	/*!
	 * Renvoie le nom du widget
	 * \returns Le nom du chan.
	 */
	virtual QString getName(void) = 0; // Permet la non instanciabilité.

	/*!
	 * Ecrit un message sur le widget. /!\ LIGNE OBLIGATOIRE /!\
	 * \param message Le message à ecrire.
	 */
	virtual void write(QString message);

protected :
	/*!
	 * Construit un widget central générique, non prévu
	 * pour être instanciable.
	 */
	AbstractCentralWidget(QWidget *parent);

private :
	void openBracket(textFormatCodes formatCode, QString& message);
	void closeBracketUntil(textFormatCodes formatCode, QString& message);
	void closeAllBracket(QString& message);
	QString codeToHtmlClosedBracket (textFormatCodes formatCode);
	QString codeToHtmlOpenedBracket (textFormatCodes formatCode);
};

#endif
