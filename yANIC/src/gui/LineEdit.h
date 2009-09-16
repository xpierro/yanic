#ifndef LINE_EDIT_H
#define LINE_EDIT_H

#include <QLineEdit>
#include <QEvent>
#include <QKeyEvent>
#include <QStack>

class LineEdit : public QLineEdit {
	Q_OBJECT
private :
	QStack<QString> *historyStack;
	int stackPos;

public :
	LineEdit(const QString& contents, QWidget *parent);
	/*!
	 * Sudéfinition de la gestion des évènements.
	 * a) Touche TAB
	 * 		emet le signal correspondant.
	 * b) Touche UP
	 * 		emet le signal correspondant, et fait un undo.
	 * c) Touche DOWN
	 * 		emet le signal correspondant, et fait un redo.
	 * \param event L'évènement auquel réagir
	 * \returns Un booleen signalant que l'action a été accomplie.
	 */
	virtual bool event (QEvent *event);

public slots :
	/*!
	 * Rajoute le texte en cours à l'historique. Correspond à l'action de la
	 * touche ENTER.
	 */
	void updateHistoryWithCurrentText();

signals :
	/*!
	 * Signal émis lorsque la touche tab est pressée, avec la ligne en cours.
	 */
	void tabPressed(QString beginWith);
	/*!
	 * Signal émis lorsque la touche haut est pressée, ne sert à rien pour
	 * l'instant.
	 */
	void upPressed();
	/*!
	 * Même chose que pr upPressed().
	 */
	void downPressed();
};

#endif
