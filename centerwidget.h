/*
    This file is part of cPad Project.

    cPad is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    cPad is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with cPad.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>
#include "codeeditor.h"
#include "syntaxhighlighter.h"
#include <QLineEdit>
#include "keyboard/keyboard.h"
QT_BEGIN_NAMESPACE
class QGridLayout;
QT_END_NAMESPACE

class CenterWidget : public QWidget
{
        Q_OBJECT
    public:
        CenterWidget(QWidget *parent = 0);
        CodeEditor *codeEditor;
        QGridLayout *centerLayout;
        Highlighter *syntaxHighlighter;
        QLineEdit   *lineEditor;
        Keyboard *lineEditkeyboard;
    private slots:
        void open_keyboard_lineEdit();
        void hide_key_board();
        //SyntaxHighlighter *syntaxHighlighter;
};


#endif // CENTERWIDGET_H
