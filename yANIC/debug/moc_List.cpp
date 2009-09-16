/****************************************************************************
** Meta object code from reading C++ file 'List.h'
**
** Created: Wed Sep 16 15:51:59 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui/List.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'List.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_List[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      14,    6,    5,    5, 0x0a,
      31,    5,    5,    5, 0x0a,
      53,    6,   44,    5, 0x0a,
      72,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_List[] = {
    "List\0\0rawDesc\0addChan(QString)\0"
    "sortByName()\0QString*\0parseChan(QString)\0"
    "clearAll()\0"
};

const QMetaObject List::staticMetaObject = {
    { &QTableView::staticMetaObject, qt_meta_stringdata_List,
      qt_meta_data_List, 0 }
};

const QMetaObject *List::metaObject() const
{
    return &staticMetaObject;
}

void *List::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_List))
        return static_cast<void*>(const_cast< List*>(this));
    return QTableView::qt_metacast(_clname);
}

int List::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addChan((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: sortByName(); break;
        case 2: { QString* _r = parseChan((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString**>(_a[0]) = _r; }  break;
        case 3: clearAll(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
