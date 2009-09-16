/****************************************************************************
** Meta object code from reading C++ file 'NonNativeIrcEngine.h'
**
** Created: Wed Sep 16 15:51:50 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/engine/NonNativeIrcEngine.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NonNativeIrcEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NonNativeIrcEngine[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x05,
      42,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,   57,   19,   19, 0x0a,
     101,   93,   88,   19, 0x0a,
     132,  122,   19,   19, 0x0a,
     159,   19,   88,   19, 0x0a,
     173,   19,   88,   19, 0x0a,
     204,  187,   19,   19, 0x0a,
     244,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NonNativeIrcEngine[] = {
    "NonNativeIrcEngine\0\0lineReceived(QString)\0"
    "connectError()\0mess\0sendASCIIMessage(QString)\0"
    "bool\0lineStr\0returnLine(QString&)\0"
    "host,port\0connectToHost(QString,int)\0"
    "canReadLine()\0isConnected()\0"
    "server,port,nick\0"
    "initiateConnection(QString,int,QString)\0"
    "relayReadyRead()\0"
};

const QMetaObject NonNativeIrcEngine::staticMetaObject = {
    { &IIrcEngine::staticMetaObject, qt_meta_stringdata_NonNativeIrcEngine,
      qt_meta_data_NonNativeIrcEngine, 0 }
};

const QMetaObject *NonNativeIrcEngine::metaObject() const
{
    return &staticMetaObject;
}

void *NonNativeIrcEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NonNativeIrcEngine))
        return static_cast<void*>(const_cast< NonNativeIrcEngine*>(this));
    return IIrcEngine::qt_metacast(_clname);
}

int NonNativeIrcEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IIrcEngine::qt_metacall(_c, _id, _a);
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
        case 8: relayReadyRead(); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void NonNativeIrcEngine::lineReceived(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NonNativeIrcEngine::connectError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
