/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu May 23 17:04:41 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   12,   11,   11, 0x05,
      63,   52,   11,   11, 0x05,
      94,   90,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
     117,   11,   11,   11, 0x08,
     127,   11,   11,   11, 0x08,
     143,   11,  138,   11, 0x08,
     154,   11,  138,   11, 0x08,
     167,   11,   11,   11, 0x08,
     181,   11,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     220,   11,   11,   11, 0x08,
     246,  238,   11,   11, 0x08,
     269,  238,   11,   11, 0x08,
     290,  238,   11,   11, 0x08,
     312,  238,   11,   11, 0x08,
     334,  238,   11,   11, 0x08,
     356,   11,   11,   11, 0x08,
     373,   11,   11,   11, 0x08,
     386,   11,  138,   11, 0x08,
     407,   11,   11,   11, 0x08,
     427,   11,   11,   11, 0x08,
     453,  450,   11,   11, 0x08,
     476,   11,   11,   11, 0x08,
     487,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0currentFile\0"
    "currentFileChanged(QString)\0currentDir\0"
    "currentDirChanged(QString)\0num\0"
    "colorThemeChanged(int)\0newFile()\0"
    "openFile()\0bool\0saveFile()\0saveAsFile()\0"
    "aboutDialog()\0documentWasModified()\0"
    "openRecentFile()\0cleanRecentFile()\0"
    "visible\0statusBarVisible(bool)\0"
    "menuBarVisible(bool)\0fileToolVisible(bool)\0"
    "editToolVisible(bool)\0toolToolVisible(bool)\0"
    "openColorTheme()\0preCompile()\0"
    "preCompileSaveFile()\0openCompileconfig()\0"
    "compileButtonChecked()\0ok\0"
    "switchAutoIndent(bool)\0openHelp()\0"
    "insertGcode()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: currentFileChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: currentDirChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: colorThemeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: newFile(); break;
        case 4: openFile(); break;
        case 5: { bool _r = saveFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 6: { bool _r = saveAsFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: aboutDialog(); break;
        case 8: documentWasModified(); break;
        case 9: openRecentFile(); break;
        case 10: cleanRecentFile(); break;
        case 11: statusBarVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: menuBarVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: fileToolVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: editToolVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: toolToolVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: openColorTheme(); break;
        case 17: preCompile(); break;
        case 18: { bool _r = preCompileSaveFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: openCompileconfig(); break;
        case 20: compileButtonChecked(); break;
        case 21: switchAutoIndent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: openHelp(); break;
        case 23: insertGcode(); break;
        default: ;
        }
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::currentFileChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::currentDirChanged(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::colorThemeChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
