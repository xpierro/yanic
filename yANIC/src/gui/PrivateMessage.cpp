#include "PrivateMessage.h"

PrivateMessage::PrivateMessage(const QString& name, QWidget *parent = 0)
											: AbstractCentralWidget(parent) {
	this->name = name;
}

QString PrivateMessage::getName() {
	return name;
}
