/****************************************************************************
** Meta object code from reading C++ file 'recomposedialog.h'
**
** Created: Wed May 22 11:23:01 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "recomposedialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'recomposedialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RecomposeDialog[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   17,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
      41,   16,   16,   16, 0x08,
      54,   16,   16,   16, 0x08,
      71,   16,   16,   16, 0x08,
      89,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_RecomposeDialog[] = {
    "RecomposeDialog\0\0code\0recomposeCode(int)\0"
    "showDialog()\0generalSetting()\0"
    "readToRecompose()\0closeDialog()\0"
};

const QMetaObject RecomposeDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_RecomposeDialog,
      qt_meta_data_RecomposeDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RecomposeDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RecomposeDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RecomposeDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RecomposeDialog))
        return static_cast<void*>(const_cast< RecomposeDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int RecomposeDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: recomposeCode((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: showDialog(); break;
        case 2: generalSetting(); break;
        case 3: readToRecompose(); break;
        case 4: closeDialog(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RecomposeDialog::recomposeCode(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
