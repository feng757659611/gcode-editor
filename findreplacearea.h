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
#ifndef FINDREPLACEAREA_H
#define FINDREPLACEAREA_H

#include <QDockWidget>
#include "codeeditor.h"
#include <QLineEdit>
#include "keyboard/keyboard.h"
QT_BEGIN_NAMESPACE
class QHBoxLayout;
class QLineEdit;
class QPushButton;
class QCheckBox;
class QLabel;
class QGridLayout;
class QAction;
QT_END_NAMESPACE

class FindReplaceArea : public QDockWidget
{
        Q_OBJECT
    public:
        FindReplaceArea(QWidget *parent, CodeEditor *editor,QLineEdit *lineEdit,
            QAction *find, QAction *replace);

    protected:
        void closeEvent(QCloseEvent *event);

    private slots:
        void transLayout(bool topLevel);//������ʱ�ı䲼��
        void openFindArea(bool open);//�򿪲���
        void openReplaceArea(bool open);//���滻
        //����������������
        void highlightResultChecked(int state);//��ѡ����ʱ����
        void checkButtonToggled(int);//��ѡƥ���Сд��ȫ��ƥ��ʱ����
        void runtimeSearchToggled(QString text); //��������� runtimeSearch ����ʵʱ���������
        void searchNext();
        void searchPrevious();
        void replaceAll();
        void replace();
        /////// ����ĺ�����connectʱ����õĺ��������������ǵĸ���������
        void clearAndHighlightAll(QString text);//�����õĸ�������
        void clearAll();
        void runtimeSearch(QString text); //ʵʱ���Һ���
        void userChangedText();//�û�����ʱ���жϺ���
        void setLineEdit();

    private:
   // public:
        void createWidget();//�����ؼ�
        void dockedLayout();//����ʱ����
        void floatingLayout();//����ʱ����
        void generalSetting();//һ������
        int inExtraSelection(int cursorPosition ); //�ж������Ĺ��λ���ڲ��� QList<QTextEdit::ExtraSelection> ����

        QWidget     *findWidget, *replaceWidget;//����ؼ�
        QLabel      *findLabel;//���ұ�ǩ
        QLabel      *replaceLabel;//�滻��ǩ
        QLineEdit   *findLineEdit;//����������
        QLineEdit   *replaceLineEdit;//�滻������
        QLineEdit   *lineedit;

        Keyboard *lineEditkeyboard;
        QPushButton *previousButton, *nextButton, *closeButton,
                    *replaceButton, *replaceAllButton;
                    //��ǰ����󡢹رա��滻��ť
        QCheckBox   *caseSensitive, *consistentMatch, 
                    *highLightResult;
                   //��Сд��ȫ��ƥ�䡢������ѡ
        QGridLayout *findLayout, *replaceLayout;//����ؼ�
        CodeEditor  *codeEditor; 
        QAction     *findAction, 
                    *replaceAction;//�˵���
        static const int FindMode = 0, ReplaceMode = 1;//ģʽѡ��
        int currentMode;//��ǰģʽ
QString str;
        QTextDocument::FindFlags findFlag;  //�����һ�β���ʱ�������

};

#endif // FINDREPLACEAREA_H
