/****************************************************************************
** Meta object code from reading C++ file 'dcc.h'
**
** Created: Sun Jun 21 18:51:58 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/dcc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dcc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dcc[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,    4,    5,    4, 0x0a,
      31,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_dcc[] = {
    "dcc\0\0QString\0getReplyToStart()\0"
    "instanciateSocket()\0"
};

const QMetaObject dcc::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_dcc,
      qt_meta_data_dcc, 0 }
};

const QMetaObject *dcc::metaObject() const
{
    return &staticMetaObject;
}

void *dcc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dcc))
        return static_cast<void*>(const_cast< dcc*>(this));
    return QWidget::qt_metacast(_clname);
}

int dcc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = getReplyToStart();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: instanciateSocket(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
