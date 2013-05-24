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
#include <QtGui>
#include "centerwidget.h"
#include <QFont>

CenterWidget::CenterWidget(QWidget *parent):
    QWidget(parent)
{
    codeEditor = new CodeEditor(this);
    centerLayout = new QGridLayout(this);

    lineEditor = new QLineEdit;
    QPalette palette(lineEditor->palette());
    palette.setBrush(QPalette::Active, QPalette::Highlight, palette.highlight());
    palette.setBrush(QPalette::Inactive, QPalette::Highlight, palette.highlight());
    palette.setColor(QPalette::Base, QColor(0  ,0  ,0  ));
    palette.setColor(QPalette::Text, QColor(Qt::red) );
    QFont font("Courier New", 30);
    //font.setWeight(QFont::DemiBold);
    lineEditor->setFont(font);
    lineEditor->setPalette(palette);
//    QString str;
//    cin >> str;
//    lineEditor->insert(str);
    //syntaxHighlighter = new SyntaxHighlighter(codeEditor->document());
    syntaxHighlighter = new Highlighter(codeEditor->document());
    centerLayout->addWidget( codeEditor, 0, 0, 1, 1 );
    centerLayout->addWidget(lineEditor,1,0,1,1);
    centerLayout->setSpacing(0);
    centerLayout->setContentsMargins( 0, 0, 0, 0 );

    setLayout(centerLayout);

    codeEditor->setFocus();
    lineEditkeyboard = new Keyboard();
    connect(lineEditor,SIGNAL(selectionChanged()),this ,SLOT(open_keyboard_lineEdit()));
    connect(codeEditor,SIGNAL(selectionChanged()),this,SLOT(syntaxHighlighter->rehighlight()));
    //connect(codeEditor,SIGNAL(selectionChanged()),this ,SLOT(open_keyboard_lineEdit()));
}
void CenterWidget::open_keyboard_lineEdit()
{
    QLineEdit *line=(QLineEdit *)sender();
    lineEditkeyboard->setLineEdit(line);
    lineEditkeyboard->show();
 //   codeEditor->insertPlainText(lineEditkeyboard->outputLineEdit->displayText());
}
void CenterWidget::hide_key_board()
{
    lineEditkeyboard->hide();
}
