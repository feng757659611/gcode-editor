/****************************************************************************
** Meta object code from reading C++ file 'functionlistarea.h'
**
** Created: Wed May 22 11:22:51 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "functionlistarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'functionlistarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FunctionListBox[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_FunctionListBox[] = {
    "FunctionListBox\0\0updateFunctionList()\0"
};

const QMetaObject FunctionListBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_FunctionListBox,
      qt_meta_data_FunctionListBox, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FunctionListBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FunctionListBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FunctionListBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FunctionListBox))
        return static_cast<void*>(const_cast< FunctionListBox*>(this));
    return QComboBox::qt_metacast(_clname);
}

int FunctionListBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateFunctionList(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void FunctionListBox::updateFunctionList()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
static const uint qt_meta_data_FunctionListArea[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   18,   17,   17, 0x08,
      47,   40,   17,   17, 0x08,
      64,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FunctionListArea[] = {
    "FunctionListArea\0\0index\0cursorMove(int)\0"
    "enable\0enableArea(bool)\0createFunctionList()\0"
};

const QMetaObject FunctionListArea::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_FunctionListArea,
      qt_meta_data_FunctionListArea, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FunctionListArea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FunctionListArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FunctionListArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FunctionListArea))
        return static_cast<void*>(const_cast< FunctionListArea*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int FunctionListArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: cursorMove((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: enableArea((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: createFunctionList(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
