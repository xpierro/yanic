#ifndef EXCEPTIONS
#define EXCEPTIONS

#include <stdexcept>
#include <iostream>
#include <stdlib.h>
using namespace std;

#include <QString>

/*!
 * \class IllegalArgumentException
 * Exception décrivant un mauvais argument.
 */
class IllegalArgumentException : public exception {
public:
	/*!
	 * Constructeur de la classe.
	 * \param desc Déscription succinte.
	 */
	IllegalArgumentException(QString desc) {
		this->desc = (char*) malloc(desc.length() * sizeof(char));
		strcpy(this->desc, desc.toUtf8().constData());
		qDebug("%s", this->desc);
	}

	/*!
	 * Que faire en cas de catch ?
	 */
	const char* what() {
		qDebug("%s", desc);
		return desc;
	}

private :
	char* desc;

};
#endif
