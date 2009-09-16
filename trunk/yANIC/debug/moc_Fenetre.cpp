/****************************************************************************
** Meta object code from reading C++ file 'Fenetre.h'
**
** Created: Thu Jun 11 20:53:11 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/Fenetre.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Fenetre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Fenetre[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x0a,
      26,    8,    8,    8, 0x0a,
      43,   40,    8,    8, 0x0a,
      81,    8,    8,    8, 0x0a,
     114,  112,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Fenetre[] = {
    "Fenetre\0\0capturerReturn()\0lireServeur()\0"
    ",,\0connexion(QString&,QString&,QString&)\0"
    "afficherChan(QListWidgetItem*)\0,\0"
    "creerChan(char*,bool)\0"
};

const QMetaObject Fenetre::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Fenetre,
      qt_meta_data_Fenetre, 0 }
};

const QMetaObject *Fenetre::metaObject() const
{
    return &staticMetaObject;
}

void *Fenetre::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Fenetre))
        return static_cast<void*>(const_cast< Fenetre*>(this));
    return QWidget::qt_metacast(_clname);
}

int Fenetre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: capturerReturn(); break;
        case 1: lireServeur(); break;
        case 2: connexion((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: afficherChan((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: creerChan((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
