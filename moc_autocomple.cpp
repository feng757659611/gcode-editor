/****************************************************************************
** Meta object code from reading C++ file 'autocomple.h'
**
** Created: Wed May 22 11:23:04 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "autocomple.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'autocomple.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_AutoComple[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   12,   11,   11, 0x08,
      35,   11,   11,   11, 0x28,
      55,   50,   11,   11, 0x08,
      88,   86,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_AutoComple[] = {
    "AutoComple\0\0mode\0doAutoComple(int)\0"
    "doAutoComple()\0item\0compleString(QListWidgetItem*)\0"
    "f\0fontSettings(QFont)\0"
};

const QMetaObject AutoComple::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_AutoComple,
      qt_meta_data_AutoComple, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &AutoComple::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *AutoComple::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *AutoComple::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AutoComple))
        return static_cast<void*>(const_cast< AutoComple*>(this));
    return QListWidget::qt_metacast(_clname);
}

int AutoComple::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: doAutoComple((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: doAutoComple(); break;
        case 2: compleString((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: fontSettings((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
