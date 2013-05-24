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
#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QPlainTextEdit>
#include "textblockdata.h"
#include "memorycenter.h"
#include "cpadpalette.h"

QT_BEGIN_NAMESPACE
class QWidget;
class QListWidget;
QT_END_NAMESPACE

class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT
    public:
        CodeEditor(QWidget *parent = 0);
        ~CodeEditor();

        void lineNumberAreaPaintEvent(QPaintEvent *event);//�Զ����к�����ͼ����
        void functionFoldAreaPaintEvent(QPaintEvent *event);//�Զ��庯���۵�����ͼ����
        int lineNumberAreaWidth();//�����к������
        //��ȡ����Ķ����͵ײ�block��
        void getTopAndBottom(int mouseY,int& topBlockNum,int& bottomBlockNum,bool& isNeededPaint);
        QPoint mousePosition;//�������뺯���۵���ʱ�����λ��
        QWidget *lineNumberArea;//�����б�����
        QWidget *functionFoldArea;//���庯���۵�����
        void functionFold(int y);//�����۵�
        void functionUnfold(int y);//������
        QTextBlock getMousePositionBlock(int mouseY);//��ȡ�������block
        void keyPressEvent(QKeyEvent *event);//���̰����¼�
        QPoint getCompleXY();//�õ�blockY

    signals:
        void needAutoComple(int);//��Ҫ��ʾ�Զ���ȫ
        void fontChanged(QFont f);//�ı������
        
    protected:
        void contextMenuEvent(QContextMenuEvent *event);//�Ҽ��˵� 
        void resizeEvent(QResizeEvent *event);//Ϊ�����ڵĿؼ����·����С
        //void keyPressEvent(QKeyEvent *event);//���̰����¼�
        void paintEvent(QPaintEvent *event);

    private slots:
        void updateLineNumberAreaWidth(int newBlockCount);//�����к����Ŀ��
        void highlightCurrentLine();//������ǰ��
        void updateLineNumberArea(const QRect &, int);//�����к���
        //����ƶ�ʱ��ƥ������
        void matchParentheses();
        void setWrapMode(bool isWraped);//�����Ƿ��Զ�����
        void fontSettings();//���ñ༭������
        void deleteSelectedText();//ɾ��ѡ�����������
        void myUpdate();
        void recomposeContent(int code);//���Ű�
        void changeColorGroup(QList<QColor> group);
        void autoIndentAnalysis();//�Զ���������
        void turnOnHighlightCurrentLine(bool);
        void doAutoIndent();//���Զ�����
        void functionComment();//������׼ע��
        void quickComment();//����ע�ͷ�ע��

    private:
        void generalSetting();//��������   
        void readSettings();
        void writeSettings();
        // ����ƥ�亯��
        bool matchLeftParenthesis(QTextBlock currentBlock, int index, int numRightParentheses, char symbolLeft, char symbolRight);
        bool matchRightParenthesis(QTextBlock currentBlock, int index, int numLeftParentheses, char symbolLeft, char symbolRight);
        void createParenthesisSelection(int pos);
        int getInvisibleBlockNum(int blockNum);//��ȡĳblock֮ǰ�Ĳ��ɼ�block����
        MemoryCenter *memoryCenter;//��������
        CpadPalette cpadPalette; //color theme
        bool matchForFolding(QTextBlock currentBlock, QTextBlock &leftBlock, QTextBlock &rightBlock);
        bool judgeLeftBracket(QTextBlock);
        bool switchOfHighlightCurrentLine;
        QAction *undoAction;//�����˵���
        QAction *redoAction;//�����˵���
        QAction *cutAction;//���в˵���
        QAction *copyAction;//���Ʋ˵���
        QAction *pasteAction;//ճ���˵���
        QAction *selectAllAction;//ȫѡ�˵���
        QAction *deleteAction;//ɾ���˵���
        QMenu *contextMenu;//�Ҽ������˵�
        bool needPaint;
};

#endif // CODEEDITOR_H
