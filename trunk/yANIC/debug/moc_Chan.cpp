/****************************************************************************
** Meta object code from reading C++ file 'Chan.h'
**
** Created: Wed Sep 16 15:52:06 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui/Chan.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Chan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Chan[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
       6,    5,    5,    5, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Chan[] = {
    "Chan\0\0topicChanged()\0"
};

const QMetaObject Chan::staticMetaObject = {
    { &AbstractCentralWidget::staticMetaObject, qt_meta_stringdata_Chan,
      qt_meta_data_Chan, 0 }
};

const QMetaObject *Chan::metaObject() const
{
    return &staticMetaObject;
}

void *Chan::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Chan))
        return static_cast<void*>(const_cast< Chan*>(this));
    return AbstractCentralWidget::qt_metacast(_clname);
}

int Chan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractCentralWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: topicChanged(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void Chan::topicChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
