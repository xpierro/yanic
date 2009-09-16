/****************************************************************************
** Meta object code from reading C++ file 'ServerList.h'
**
** Created: Wed Sep 16 15:51:46 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui/ui/ServerList.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ServerList.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ServerList[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      52,   11,   11,   11, 0x0a,
      64,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_ServerList[] = {
    "ServerList\0\0,,\0connectSignal(QString&,int,QString&)\0"
    "connectMe()\0reconnect()\0"
};

const QMetaObject ServerList::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ServerList,
      qt_meta_data_ServerList, 0 }
};

const QMetaObject *ServerList::metaObject() const
{
    return &staticMetaObject;
}

void *ServerList::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ServerList))
        return static_cast<void*>(const_cast< ServerList*>(this));
    return QWidget::qt_metacast(_clname);
}

int ServerList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connectSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: connectMe(); break;
        case 2: reconnect(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ServerList::connectSignal(QString & _t1, int _t2, QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
