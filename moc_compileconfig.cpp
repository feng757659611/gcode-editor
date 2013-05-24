/****************************************************************************
** Meta object code from reading C++ file 'compileconfig.h'
**
** Created: Tue May 21 16:42:09 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "compileconfig.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'compileconfig.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CompileConfig[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      49,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      92,   14,   14,   14, 0x0a,
     105,   14,   14,   14, 0x0a,
     119,   14,   14,   14, 0x0a,
     144,  138,   14,   14, 0x0a,
     171,   14,   14,   14, 0x0a,
     185,   14,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CompileConfig[] = {
    "CompileConfig\0\0getCompiler,getWorkingDir,getArgs\0"
    "configChanged(QString,QString,QStringList)\0"
    "showDialog()\0closeDialog()\0"
    "setCompileConfig()\0fPath\0"
    "openCompileConfig(QString)\0openExeFile()\0"
    "openDir()\0"
};

const QMetaObject CompileConfig::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CompileConfig,
      qt_meta_data_CompileConfig, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CompileConfig::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CompileConfig::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CompileConfig::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CompileConfig))
        return static_cast<void*>(const_cast< CompileConfig*>(this));
    return QDialog::qt_metacast(_clname);
}

int CompileConfig::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: configChanged((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3]))); break;
        case 1: showDialog(); break;
        case 2: closeDialog(); break;
        case 3: setCompileConfig(); break;
        case 4: openCompileConfig((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: openExeFile(); break;
        case 6: openDir(); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CompileConfig::configChanged(QString _t1, QString _t2, QStringList _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
