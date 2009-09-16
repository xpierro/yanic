#include "LineEdit.h"

LineEdit::LineEdit(const QString& contents, QWidget *parent = NULL) : QLineEdit(contents, parent) {
	historyStack = new QStack<QString>();
	stackPos = 0;
	connect(this, SIGNAL(returnPressed()), this, SLOT(updateHistoryWithCurrentText()));
}

bool LineEdit::event (QEvent *event) {
	switch (event->type()) {
	case QEvent::KeyPress :
		switch (dynamic_cast<QKeyEvent*>(event)->key()) {
		case Qt::Key_Tab :
			qDebug("tab pressed");
			emit(tabPressed(text()));
			return true;
			break;
		case Qt::Key_Up :
			qDebug("up pressed!");
			if (stackPos > 0) {
				setText(historyStack->at(stackPos - 1));
				stackPos -= 1;
			}
			emit(upPressed());
			return true;
			break;
		case Qt::Key_Down :
			qDebug("down pressed!");
			if (stackPos < historyStack->size() - 1) {
				setText(historyStack->at(stackPos + 1));
				stackPos +=1;
			} else {
				setText("");
				stackPos = historyStack->size();
			}
			emit(downPressed());
			return true;
			break;
		default :
			break;
		}
		break;
	default :
		break;

	}
	return QLineEdit::event(event);
}
void LineEdit::updateHistoryWithCurrentText() {
	qDebug("Enter pressed");
	historyStack->push(text());
	stackPos = historyStack->size();
	qDebug("stackPost == %d", stackPos);
}
