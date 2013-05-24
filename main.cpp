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
#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QTextCodec>
#include <QSplashScreen>
#include <QDesktopWidget>
#include <QDebug>
//#include "terminal.h"
int main(int argc, char *argv[])
{
    QApplication cpad(argc, argv);

    //����translation����Ϊwindows���ر���
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    //�������������ͼƬ
    QPixmap pixmap(":/resources/splash.png");

    //������������
    QSplashScreen splash(pixmap);
    //for(qint64 i=5555555*9;i>0;i--)
    //    splash.show();

    //���ó������֯����
    cpad.setOrganizationName("5-up");
    //���ó��������
    cpad.setApplicationName("cPad");
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    //�����岢��ʾ
    MainWindow mainWindow;
    mainWindow.move(0,0);
    mainWindow.resize(400,480);
    mainWindow.showMaximized();
    //mainWindow.showFullScreen();
    //mainWindow.setWindowFlags(Qt::FramelessWindowHint);
    //mainWindow.show();
    //�����������
    splash.finish(&mainWindow);

//terminal w;
//w.show();
    //������ļ���Ϊ���� ���ļ�
    if (argc > 1) {
        mainWindow.openArgvFile(argv[1]);
    }
//    QTextStream cin(stdin, QIODevice::ReadOnly);
//    QTextStream cout(stdout, QIODevice::WriteOnly);

//cout << "the string is "<< str << endl;
//qDebug() << "Qt types " << QRect(0,0,10,10) << endl;
    //����ִ�� �ȴ���Ӧ
    //mainWindow.close();
//    mainWindow.hide();
//    mainWindow.show();
   // cpad.exit(0);
    QPoint coursePoint;
    coursePoint = QCursor::pos();//��ȡ��ǰ����λ��
    qDebug()<<coursePoint.x();
    qDebug()<<coursePoint.y();

    return cpad.exec();
}
