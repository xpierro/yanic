/****************************************************************************
** Meta object code from reading C++ file 'DccServer.h'
**
** Created: Wed Sep 16 15:52:02 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/tools/DccServer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DccServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DccServer[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      42,   11,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DccServer[] = {
    "DccServer\0\0dldedFile,fileSize,progressBar\0"
    "setNewConnection(QFile*,int,QProgressBar*)\0"
};

const QMetaObject DccServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_DccServer,
      qt_meta_data_DccServer, 0 }
};

const QMetaObject *DccServer::metaObject() const
{
    return &staticMetaObject;
}

void *DccServer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DccServer))
        return static_cast<void*>(const_cast< DccServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int DccServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: setNewConnection((*reinterpret_cast< QFile*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QProgressBar*(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
