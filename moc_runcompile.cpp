/****************************************************************************
** Meta object code from reading C++ file 'runcompile.h'
**
** Created: Wed May 22 11:23:07 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "runcompile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'runcompile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_RunCompile[] = {

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
      12,   11,   11,   11, 0x0a,
      27,   11,   11,   11, 0x0a,
      79,   45,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_RunCompile[] = {
    "RunCompile\0\0compileClear()\0compilePrograms()\0"
    "getCompiler,getWorkingDir,getArgs\0"
    "configChanged(QString,QString,QStringList)\0"
};

const QMetaObject RunCompile::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_RunCompile,
      qt_meta_data_RunCompile, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &RunCompile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *RunCompile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *RunCompile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_RunCompile))
        return static_cast<void*>(const_cast< RunCompile*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int RunCompile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: compileClear(); break;
        case 1: compilePrograms(); break;
        case 2: configChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
