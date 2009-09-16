/****************************************************************************
** Meta object code from reading C++ file 'DccGet.h'
**
** Created: Wed Sep 16 15:52:03 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/tools/DccGet.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DccGet.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DccGet[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      10,    8,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      63,   36,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_DccGet[] = {
    "DccGet\0\0,\0sendCTCP(QString,QString)\0"
    "orig,mess,progressBar,myIP\0"
    "download(QString,QString,QProgressBar*,QString)\0"
};

const QMetaObject DccGet::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DccGet,
      qt_meta_data_DccGet, 0 }
};

const QMetaObject *DccGet::metaObject() const
{
    return &staticMetaObject;
}

void *DccGet::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DccGet))
        return static_cast<void*>(const_cast< DccGet*>(this));
    return QObject::qt_metacast(_clname);
}

int DccGet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendCTCP((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: download((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QProgressBar*(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DccGet::sendCTCP(QString _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
