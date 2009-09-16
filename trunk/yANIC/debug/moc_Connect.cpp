/****************************************************************************
** Meta object code from reading C++ file 'Connect.h'
**
** Created: Mon Aug 31 18:49:07 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui/Connect.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Connect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Connect[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      12,    9,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,    8,    8,    8, 0x0a,
      57,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Connect[] = {
    "Connect\0\0,,\0okPressed(QString&,int,QString&)\0"
    "connectMe()\0reconnect()\0"
};

const QMetaObject Connect::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Connect,
      qt_meta_data_Connect, 0 }
};

const QMetaObject *Connect::metaObject() const
{
    return &staticMetaObject;
}

void *Connect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Connect))
        return static_cast<void*>(const_cast< Connect*>(this));
    return QWidget::qt_metacast(_clname);
}

int Connect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: okPressed((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: connectMe(); break;
        case 2: reconnect(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void Connect::okPressed(QString & _t1, int _t2, QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
