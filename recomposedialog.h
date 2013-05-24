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
#ifndef RECOMPOSEDIALOG_H
#define RECOMPOSEDIALOG_H

#include <QDialog>
#include "codeeditor.h"

QT_BEGIN_NAMESPACE
class QGridLayout;
class QGroupBox;
class QPushButton;
class QCheckBox;
class QLabel;
QT_END_NAMESPACE

class RecomposeDialog : public QDialog
{
        Q_OBJECT
    public:
        RecomposeDialog(QWidget *parent, CodeEditor *editor);

    signals:
        void recomposeCode(int code);

    private slots:
        void showDialog();
        void generalSetting();
        void readToRecompose();
        void closeDialog();

    private:
        void createWidget(); //�����ռ� ��λ��
        QGroupBox *groupBox;
        QCheckBox *b1, //ǿ�������������
                  *b2, //ǿ���ں���������
                  *b3, //������ŵ���һ��
                  *b4, //�ֺš�����ǰ�ӿո� 
                  *b5, //�����ڲ�ӿո�
                  *b6; //��������ӿո�
        QGridLayout *mainLayout, *inLayout;
        QPushButton *yes, *no;
        QLabel *label;
        CodeEditor *codeEditor;
};

#endif // RECOMPOSEDIALOG_H
