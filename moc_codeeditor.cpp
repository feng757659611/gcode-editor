/****************************************************************************
** Meta object code from reading C++ file 'codeeditor.h'
**
** Created: Wed May 22 11:22:41 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "codeeditor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codeeditor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CodeEditor[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      34,   32,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      67,   53,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     123,  121,   11,   11, 0x08,
     155,   11,   11,   11, 0x08,
     183,  174,   11,   11, 0x08,
     201,   11,   11,   11, 0x08,
     216,   11,   11,   11, 0x08,
     237,   11,   11,   11, 0x08,
     253,  248,   11,   11, 0x08,
     281,  275,   11,   11, 0x08,
     313,   11,   11,   11, 0x08,
     334,   11,   11,   11, 0x08,
     367,   11,   11,   11, 0x08,
     382,   11,   11,   11, 0x08,
     400,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CodeEditor[] = {
    "CodeEditor\0\0needAutoComple(int)\0f\0"
    "fontChanged(QFont)\0newBlockCount\0"
    "updateLineNumberAreaWidth(int)\0"
    "highlightCurrentLine()\0,\0"
    "updateLineNumberArea(QRect,int)\0"
    "matchParentheses()\0isWraped\0"
    "setWrapMode(bool)\0fontSettings()\0"
    "deleteSelectedText()\0myUpdate()\0code\0"
    "recomposeContent(int)\0group\0"
    "changeColorGroup(QList<QColor>)\0"
    "autoIndentAnalysis()\0"
    "turnOnHighlightCurrentLine(bool)\0"
    "doAutoIndent()\0functionComment()\0"
    "quickComment()\0"
};

const QMetaObject CodeEditor::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_CodeEditor,
      qt_meta_data_CodeEditor, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CodeEditor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CodeEditor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CodeEditor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodeEditor))
        return static_cast<void*>(const_cast< CodeEditor*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int CodeEditor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: needAutoComple((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: fontChanged((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 2: updateLineNumberAreaWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: highlightCurrentLine(); break;
        case 4: updateLineNumberArea((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: matchParentheses(); break;
        case 6: setWrapMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: fontSettings(); break;
        case 8: deleteSelectedText(); break;
        case 9: myUpdate(); break;
        case 10: recomposeContent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: changeColorGroup((*reinterpret_cast< QList<QColor>(*)>(_a[1]))); break;
        case 12: autoIndentAnalysis(); break;
        case 13: turnOnHighlightCurrentLine((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: doAutoIndent(); break;
        case 15: functionComment(); break;
        case 16: quickComment(); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void CodeEditor::needAutoComple(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CodeEditor::fontChanged(QFont _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
