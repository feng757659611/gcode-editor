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
#include "recomposedialog.h"

RecomposeDialog::RecomposeDialog(QWidget *parent, CodeEditor *editor):
    QDialog(parent)
{
    codeEditor = editor;
    createWidget();
    generalSetting();
}

void RecomposeDialog::generalSetting()
{
    setWindowTitle(tr("recompose"));
    setFixedSize(430, 161);
    connect(yes, SIGNAL(clicked()),
            this, SLOT(readToRecompose()));
    connect(no, SIGNAL(clicked()),
            this, SLOT(closeDialog()));
    connect(this, SIGNAL(recomposeCode(int)),
            codeEditor, SLOT(recomposeContent(int)));
}

void RecomposeDialog::closeDialog()
{
    close();
}

void RecomposeDialog::readToRecompose()
{
    int code = 0;
    if (b1->isChecked())
        code += 1;
    if (b2->isChecked())
        code += 2;
    if (b3->isChecked())
        code += 4;
    if (b4->isChecked())
        code += 8;
    if (b5->isChecked())
        code += 16;
    if (b6->isChecked())
        code += 32;
    emit recomposeCode(code);
    close();
}

void RecomposeDialog::createWidget()
{
    groupBox = new QGroupBox(tr("how to recompose") ,this);

    b1 = new QCheckBox(tr("Forced linebreak after the announcement"), this);
    b1->setChecked(true);
    b2 = new QCheckBox(tr("Forced to break in the function body"), this);
    b2->setChecked(true);
    b3 = new QCheckBox(tr("Left brace on a separate line"), this);
    b4 = new QCheckBox(tr("Space before a comma, semicolon"), this);
    b5 = new QCheckBox(tr("Parentheses inner space"), this);
    b5->setChecked(true);
    b6 = new QCheckBox(tr("The name of the function, block keywords space"), this);
    b6->setChecked(true);
    
    inLayout = new QGridLayout(groupBox);
    
    inLayout->addWidget(b1, 0, 0);
    inLayout->addWidget(b2, 0, 1);
    inLayout->addWidget(b3, 1, 0);
    inLayout->addWidget(b4, 1, 1);
    inLayout->addWidget(b5, 2, 0);
    inLayout->addWidget(b6, 2, 1);

    groupBox->setLayout(inLayout);

    yes = new QPushButton(tr("ok"), this);
    no  = new QPushButton(tr("cancel"), this);

    mainLayout = new QGridLayout(this);

    mainLayout->addWidget(groupBox, 0, 0, 4, 4);
    mainLayout->addWidget(yes, 4, 2);
    mainLayout->addWidget( no, 4, 3);
}

void RecomposeDialog::showDialog()
{
    show();
}
