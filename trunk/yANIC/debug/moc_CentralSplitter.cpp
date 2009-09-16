/****************************************************************************
** Meta object code from reading C++ file 'CentralSplitter.h'
**
** Created: Thu Jul 30 05:38:26 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/gui/CentralSplitter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CentralSplitter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CentralSplitter[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x0a,
      48,   16,   37,   16, 0x0a,
      73,   63,   16,   16, 0x0a,
      95,   16,   16,   16, 0x0a,
     116,  110,   16,   16, 0x0a,
     177,  139,   16,   16, 0x0a,
     206,   16,  202,   16, 0x0a,
     221,   16,  202,   16, 0x0a,
     238,   16,  202,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CentralSplitter[] = {
    "CentralSplitter\0\0buildInitialSizes()\0"
    "QList<int>\0makeSizeList()\0pos,index\0"
    "refreshSizes(int,int)\0refreshSizes()\0"
    "event\0showEvent(QShowEvent*)\0"
    "topicSize,centralWidgetSize,inputSize\0"
    "setSizesInt(int,int,int)\0int\0"
    "getTopicSize()\0getCentralSize()\0"
    "getInputSize()\0"
};

const QMetaObject CentralSplitter::staticMetaObject = {
    { &QSplitter::staticMetaObject, qt_meta_stringdata_CentralSplitter,
      qt_meta_data_CentralSplitter, 0 }
};

const QMetaObject *CentralSplitter::metaObject() const
{
    return &staticMetaObject;
}

void *CentralSplitter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CentralSplitter))
        return static_cast<void*>(const_cast< CentralSplitter*>(this));
    return QSplitter::qt_metacast(_clname);
}

int CentralSplitter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSplitter::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: buildInitialSizes(); break;
        case 1: { QList<int> _r = makeSizeList();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = _r; }  break;
        case 2: refreshSizes((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: refreshSizes(); break;
        case 4: showEvent((*reinterpret_cast< QShowEvent*(*)>(_a[1]))); break;
        case 5: setSizesInt((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: { int _r = getTopicSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 7: { int _r = getCentralSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 8: { int _r = getInputSize();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
