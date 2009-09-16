/****************************************************************************
** Meta object code from reading C++ file 'Dcc.h'
**
** Created: Tue Jun 23 01:45:00 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/Dcc.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Dcc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Dcc[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      13,    4,    5,    4, 0x0a,
      46,   35,   31,    4, 0x0a,
      66,    4,    4,    4, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Dcc[] = {
    "Dcc\0\0QString\0getReplyToStart()\0int\0"
    "dccSendReq\0setSendReq(QString)\0"
    "connectToDist()\0"
};

const QMetaObject Dcc::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_Dcc,
      qt_meta_data_Dcc, 0 }
};

const QMetaObject *Dcc::metaObject() const
{
    return &staticMetaObject;
}

void *Dcc::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Dcc))
        return static_cast<void*>(const_cast< Dcc*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int Dcc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { QString _r = getReplyToStart();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 1: { int _r = setSendReq((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 2: connectToDist(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
