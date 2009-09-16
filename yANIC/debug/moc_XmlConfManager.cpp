/****************************************************************************
** Meta object code from reading C++ file 'XmlConfManager.h'
**
** Created: Wed Sep 16 15:51:47 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/tools/XmlConfManager.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'XmlConfManager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_XmlConfManager[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      21,   16,   15,   15, 0x0a,
      55,   40,   15,   15, 0x0a,
      95,   83,   15,   15, 0x0a,
     136,  120,   15,   15, 0x0a,
     179,  167,   15,   15, 0x0a,
     229,  218,  210,   15, 0x0a,
     252,  218,  210,   15, 0x0a,
     287,   15,  275,   15, 0x0a,
     303,   15,   15,   15, 0x0a,
     310,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_XmlConfManager[] = {
    "XmlConfManager\0\0name\0addServer(QString)\0"
    "server,network\0addNetwork(QString,Network)\0"
    "server,user\0changeUser(QString,User)\0"
    "server,chanList\0changeFavChan(QString,QString)\0"
    "server,code\0changeCommand(QString,QString)\0"
    "QString\0serverName\0getHostByName(QString)\0"
    "getPortByName(QString)\0QStringList\0"
    "getServerList()\0read()\0save()\0"
};

const QMetaObject XmlConfManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_XmlConfManager,
      qt_meta_data_XmlConfManager, 0 }
};

const QMetaObject *XmlConfManager::metaObject() const
{
    return &staticMetaObject;
}

void *XmlConfManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_XmlConfManager))
        return static_cast<void*>(const_cast< XmlConfManager*>(this));
    return QObject::qt_metacast(_clname);
}

int XmlConfManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: addServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: addNetwork((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Network(*)>(_a[2]))); break;
        case 2: changeUser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< User(*)>(_a[2]))); break;
        case 3: changeFavChan((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: changeCommand((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: { QString _r = getHostByName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: { QString _r = getPortByName((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 7: { QStringList _r = getServerList();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = _r; }  break;
        case 8: read(); break;
        case 9: save(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
