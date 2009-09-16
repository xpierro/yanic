/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created: Wed Sep 16 23:26:07 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui/MainWindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      29,   12,   11,   11, 0x05,
      60,   11,   11,   11, 0x05,
      83,   75,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     109,   11,   11,   11, 0x0a,
     129,  124,   11,   11, 0x0a,
     154,  149,   11,   11, 0x0a,
     187,  172,   11,   11, 0x0a,
     226,  220,   11,   11, 0x0a,
     260,   11,   11,   11, 0x0a,
     274,   75,   11,   11, 0x0a,
     304,  294,   11,   11, 0x0a,
     328,  294,   11,   11, 0x0a,
     367,  362,  354,   11, 0x0a,
     383,  362,  354,   11, 0x0a,
     412,  407,   11,   11, 0x0a,
     432,  362,   11,   11, 0x0a,
     487,  407,  464,   11, 0x0a,
     510,  149,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0server,port,nick\0"
    "connectMe(QString,int,QString)\0"
    "connectError()\0message\0sendASCIIMessage(QString)\0"
    "getInputLine()\0bulk\0readServer(QString)\0"
    "line\0readLine(QString)\0serv,port,nick\0"
    "connexion(QString&,int,QString&)\0index\0"
    "displayCentralWidget(QModelIndex)\0"
    "changeTopic()\0sendServer(QString)\0"
    "dest,mess\0sendPv(QString,QString)\0"
    "sendCTCP(QString,QString)\0QString\0"
    "mess\0findIp(QString)\0findIpUserHost(QString)\0"
    "name\0deleteChan(QString)\0"
    "displayToCurrentWidget(QString)\0"
    "AbstractCentralWidget*\0createAcwHash(QString)\0"
    "autoCompletion(QString)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: connectMe((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 1: connectError(); break;
        case 2: sendASCIIMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: getInputLine(); break;
        case 4: readServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: readLine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: connexion((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 7: displayCentralWidget((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: changeTopic(); break;
        case 9: sendServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: sendPv((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: sendCTCP((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: { QString _r = findIp((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 13: { QString _r = findIpUserHost((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 14: deleteChan((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: displayToCurrentWidget((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: { AbstractCentralWidget* _r = createAcwHash((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< AbstractCentralWidget**>(_a[0]) = _r; }  break;
        case 17: autoCompletion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::connectMe(const QString & _t1, int _t2, const QString & _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::connectError()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::sendASCIIMessage(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
