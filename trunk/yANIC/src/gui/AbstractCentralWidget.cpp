#include "AbstractCentralWidget.h"

AbstractCentralWidget::AbstractCentralWidget(QWidget *parent = 0)
														: QTextEdit(parent){
	colorAbstraction = AbstractMess::ircTools();

	setReadOnly(true);
	setWordWrapMode(QTextOption::WordWrap); //A corriger, &nbsp pose probleme

	/* Mettre la fenêtre en gris */
	QPalette palette = this->palette();
	palette.setColor(QPalette::Active, QPalette::Base, QColor("lightgrey"));
	palette.setColor(QPalette::Inactive, QPalette::Base, QColor("lightgrey"));
	setPalette(palette);
	setAutoFillBackground (true);

	/* Insatisfaisant, faire un attribut changeable, peut-etre dans irctools*/
	setFont(QFont("Courier New", 9)); //Monospace, Consolas :)
	setCurrentFont(QFont("Courier New", 9));

	formatStack = new QStack<textFormatCodes>();
}

void AbstractCentralWidget::write(QString message) {
	message.replace("&", "&amp;");
	message.replace("<", "&lt;");
	message.replace(">", "&gt;");
	/* Un peu bourrin mais seule solution */
	message.replace("   ", "&nbsp; &nbsp;");
	message.replace("  ", " &nbsp;");
	message.replace("-", "&#8209;");

	/* Le message qui sera affiché sur l'ecran en html */
	QString htmlMessage;

	formatStack->clear();
	ensureCursorVisible();
	moveCursor (QTextCursor::End);
	formatSet format;
	colorAbstraction->formatSetInit(format);

	int index = -1; // Position dans la chaine.

	while (index < message.length()) {
		index++;
		if (message[index] >= ' ') { //char normal
			htmlMessage += message[index];
			continue;
		}
		if (message[index] == QChar(0x001F)) {
			if (!format.underlined) {
				openBracket(UNDERLINE, htmlMessage);
				format.underlined = true;
			} else {
				closeBracketUntil(UNDERLINE, htmlMessage);
				format.underlined = false;
			}
			continue;
		}
		if (message[index] == QChar(0x003)) {
			if (format.frontColorSet) {
				closeBracketUntil(SPAN, htmlMessage);
				format.frontColorSet = false;
			}
			index++;
			format.frontCode = 0;
			while (message[index] >= '0' && message[index] <= '9') {
				format.frontCode = format.frontCode * 10 + message[index].digitValue();
				index++;
			}
			format.frontColorSet = true;
			currentOpenedSpan ="<span style=\"color:" +
					colorAbstraction->getColorByNum(format.frontCode) + ";";
				if (message[index] == ',') {
				format.backCode = 0;
				index++;
				while (message[index] >= '0' && message[index] <= '9') {
					format.backCode = format.backCode * 10 + message[index].digitValue();
					index++;
				}
				format.backColorSet = true;
			}
			if (format.backColorSet) {
				currentOpenedSpan +=
					"background-color: " +
					colorAbstraction->getColorByNum(format.backCode) +
					";";
			}
			currentOpenedSpan += "\">";
			openBracket(SPAN, htmlMessage);
			index--;
			continue;
		}

		if (message[index] == QChar(0x009)) {
			if (!format.italic) {
				openBracket(ITALIC, htmlMessage);
				format.italic = true;
			} else {
				closeBracketUntil(ITALIC, htmlMessage);
				format.italic = false;
			}
			continue;
		}

		if (message[index] == QChar(0x002)) {
			if (!format.bold) {
				openBracket(BOLD, htmlMessage);
				format.bold = true;
			} else {
				closeBracketUntil(BOLD, htmlMessage);
				format.bold = false;
			}
			continue;
		}
		if (message[index] == QChar(0x00F)) {
			closeAllBracket(htmlMessage);
			colorAbstraction->formatSetInit(format);
			continue;
		}
	}

	closeAllBracket(htmlMessage);
	insertHtml(htmlMessage + "<br>");
	ensureCursorVisible();
	qDebug(htmlMessage.toUtf8().constData());
}

void AbstractCentralWidget::closeBracketUntil(textFormatCodes formatCode,
											  QString& message) {
	qDebug("major poping");
	QStack<textFormatCodes> tempStack;
	while (!formatStack->empty() && formatStack->top() != formatCode) {
		qDebug("got in the loop");
		message += codeToHtmlClosedBracket(formatStack->top());
		tempStack.push(formatStack->pop());
	}
	if (!formatStack->empty()) formatStack->pop();
	message += codeToHtmlClosedBracket(formatCode);
	while (!tempStack.empty()) {
		message += codeToHtmlOpenedBracket(tempStack.top());
		formatStack->push(tempStack.pop());
	}
}

void AbstractCentralWidget::openBracket(textFormatCodes formatCode,
										QString& message) {
	message += codeToHtmlOpenedBracket(formatCode);
	qDebug("pushing stuff");
	formatStack->push(formatCode);
	if (!formatStack->empty()) {
		qDebug("push done");
	}
}

void AbstractCentralWidget::closeAllBracket(QString& message) {
	while (!(formatStack->empty())) {
		message += codeToHtmlClosedBracket(formatStack->pop());
	}
}

QString AbstractCentralWidget::codeToHtmlClosedBracket (textFormatCodes formatCode){
	switch(formatCode) {
	case ITALIC :
		return "</i>"; break;
	case BOLD :
		return "</b>"; break;
	case UNDERLINE :
		return "</u>"; break;
	case SPAN :
		return "</span>"; break;
	default :
		return "";
	}
}

QString AbstractCentralWidget::codeToHtmlOpenedBracket (textFormatCodes formatCode){
	switch (formatCode) {
	case ITALIC :
		return "<i>"; break;
	case BOLD :
		return "<b>"; break;
	case UNDERLINE :
		return "<u>"; break;
	case SPAN :
		return currentOpenedSpan; break;
	default :
		return "";
	}
}
