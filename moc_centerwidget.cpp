/****************************************************************************
** Meta object code from reading C++ file 'centerwidget.h'
**
** Created: Thu May 23 11:24:28 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "centerwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'centerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CenterWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      39,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CenterWidget[] = {
    "CenterWidget\0\0open_keyboard_lineEdit()\0"
    "hide_key_board()\0"
};

const QMetaObject CenterWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CenterWidget,
      qt_meta_data_CenterWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CenterWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CenterWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CenterWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CenterWidget))
        return static_cast<void*>(const_cast< CenterWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CenterWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: open_keyboard_lineEdit(); break;
        case 1: hide_key_board(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
