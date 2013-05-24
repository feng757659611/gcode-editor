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
#ifndef FUNCTIONFOLDAREA_H
#define FUNCTIONFOLDAREA_H

#include <QWidget>
#include "codeeditor.h"
QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class FunctionFoldArea : public QWidget
{
        Q_OBJECT
    public:
        FunctionFoldArea(CodeEditor *editor) : QWidget(editor) {
            codeEditor = editor;//��edit��ͨ��
            setMouseTracking(true);//��mouseMoveEvent�¼���Ϊ�ƶ����ʹ�����Ĭ��Ϊ����������ƶ��Ŵ�����
        }

        void mouseMoveEvent(QMouseEvent *event);//����ƶ��¼�

    protected:
        void paintEvent(QPaintEvent *event) {//�ؼ��ػ��¼�
            codeEditor->functionFoldAreaPaintEvent(event);
        }

        void leaveEvent(QEvent *event)//����뿪�ؼ��¼�
        {
            codeEditor->mousePosition.setX(-1);
            repaint();
        }

    private:
        CodeEditor *codeEditor;
        void mousePressEvent(QMouseEvent *event);//�������¼�
};

#endif // FUNCTIONFOLDAREA_H
