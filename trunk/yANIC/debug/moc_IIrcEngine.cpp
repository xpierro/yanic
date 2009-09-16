/****************************************************************************
** Meta object code from reading C++ file 'IIrcEngine.h'
**
** Created: Wed Sep 16 15:51:51 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/engine/IIrcEngine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'IIrcEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_IIrcEngine[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      34,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      54,   49,   11,   11, 0x0a,
      93,   85,   80,   11, 0x0a,
     124,  114,   11,   11, 0x0a,
     151,   11,   80,   11, 0x0a,
     165,   11,   80,   11, 0x0a,
     194,  179,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_IIrcEngine[] = {
    "IIrcEngine\0\0lineReceived(QString)\0"
    "connectError()\0mess\0sendASCIIMessage(QString)\0"
    "bool\0lineStr\0returnLine(QString&)\0"
    "host,port\0connectToHost(QString,int)\0"
    "canReadLine()\0isConnected()\0host,port,nick\0"
    "initiateConnection(QString,int,QString)\0"
};

const QMetaObject IIrcEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_IIrcEngine,
      qt_meta_data_IIrcEngine, 0 }
};

const QMetaObject *IIrcEngine::metaObject() const
{
    return &staticMetaObject;
}

void *IIrcEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_IIrcEngine))
        return static_cast<void*>(const_cast< IIrcEngine*>(this));
    return QObject::qt_metacast(_clname);
}

int IIrcEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: lineReceived((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: connectError(); break;
        case 2: sendASCIIMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: { bool _r = returnLine((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: connectToHost((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: { bool _r = canReadLine();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = isConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: initiateConnection((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
