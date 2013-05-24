/****************************************************************************
** Meta object code from reading C++ file 'findreplacearea.h'
**
** Created: Thu May 23 17:04:36 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "findreplacearea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'findreplacearea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_FindReplaceArea[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   17,   16,   16, 0x08,
      49,   44,   16,   16, 0x08,
      68,   44,   16,   16, 0x08,
      96,   90,   16,   16, 0x08,
     124,   16,   16,   16, 0x08,
     153,  148,   16,   16, 0x08,
     183,   16,   16,   16, 0x08,
     196,   16,   16,   16, 0x08,
     213,   16,   16,   16, 0x08,
     226,   16,   16,   16, 0x08,
     236,  148,   16,   16, 0x08,
     266,   16,   16,   16, 0x08,
     277,  148,   16,   16, 0x08,
     300,   16,   16,   16, 0x08,
     318,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_FindReplaceArea[] = {
    "FindReplaceArea\0\0topLevel\0transLayout(bool)\0"
    "open\0openFindArea(bool)\0openReplaceArea(bool)\0"
    "state\0highlightResultChecked(int)\0"
    "checkButtonToggled(int)\0text\0"
    "runtimeSearchToggled(QString)\0"
    "searchNext()\0searchPrevious()\0"
    "replaceAll()\0replace()\0"
    "clearAndHighlightAll(QString)\0clearAll()\0"
    "runtimeSearch(QString)\0userChangedText()\0"
    "setLineEdit()\0"
};

const QMetaObject FindReplaceArea::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_FindReplaceArea,
      qt_meta_data_FindReplaceArea, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &FindReplaceArea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *FindReplaceArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *FindReplaceArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_FindReplaceArea))
        return static_cast<void*>(const_cast< FindReplaceArea*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int FindReplaceArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: transLayout((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: openFindArea((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: openReplaceArea((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: highlightResultChecked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: checkButtonToggled((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: runtimeSearchToggled((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: searchNext(); break;
        case 7: searchPrevious(); break;
        case 8: replaceAll(); break;
        case 9: replace(); break;
        case 10: clearAndHighlightAll((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: clearAll(); break;
        case 12: runtimeSearch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: userChangedText(); break;
        case 14: setLineEdit(); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
