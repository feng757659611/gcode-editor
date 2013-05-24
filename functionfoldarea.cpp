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
#include "functionfoldarea.h"

/*
    ����ƶ��¼���
        ��������뱾����ʱ���������¼���ʵʱ��¼�µ�ǰ����λ�ã�����repaint()����ǿ�ƴ���PaintEvent�¼�
*/
void FunctionFoldArea::mouseMoveEvent(QMouseEvent *event)
{
    codeEditor->mousePosition.setX(event->x());
    codeEditor->mousePosition.setY(event->y());

    repaint();
}

void FunctionFoldArea::mousePressEvent(QMouseEvent *event)
{
    QTextBlock block = codeEditor->getMousePositionBlock(event->y());
    if(block.isValid())
    {
        while(block.isVisible() == false && block.blockNumber() != -1)
        {
            block = block.next();
        }
        if(block.blockNumber() == -1) return;

        if(block.next().isVisible()) codeEditor->functionFold(event->y());
        else codeEditor->functionUnfold(event->y());
    }
}
