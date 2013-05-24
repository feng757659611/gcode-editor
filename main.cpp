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

    //设置translation编码为windows本地编码
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

    //加载启动画面的图片
    QPixmap pixmap(":/resources/splash.png");

    //程序启动画面
    QSplashScreen splash(pixmap);
    //for(qint64 i=5555555*9;i>0;i--)
    //    splash.show();

    //设置程序的组织名称
    cpad.setOrganizationName("5-up");
    //设置程序的名称
    cpad.setApplicationName("cPad");
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("GBK"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    //主窗体并显示
    MainWindow mainWindow;
    mainWindow.move(0,0);
    mainWindow.resize(400,480);
    mainWindow.showMaximized();
    //mainWindow.showFullScreen();
    //mainWindow.setWindowFlags(Qt::FramelessWindowHint);
    //mainWindow.show();
    //启动画面结束
    splash.finish(&mainWindow);

//terminal w;
//w.show();
    //如果有文件作为参数 打开文件
    if (argc > 1) {
        mainWindow.openArgvFile(argv[1]);
    }
//    QTextStream cin(stdin, QIODevice::ReadOnly);
//    QTextStream cout(stdout, QIODevice::WriteOnly);

//cout << "the string is "<< str << endl;
//qDebug() << "Qt types " << QRect(0,0,10,10) << endl;
    //程序执行 等待响应
    //mainWindow.close();
//    mainWindow.hide();
//    mainWindow.show();
   // cpad.exit(0);
    QPoint coursePoint;
    coursePoint = QCursor::pos();//获取当前光标的位置
    qDebug()<<coursePoint.x();
    qDebug()<<coursePoint.y();

    return cpad.exec();
}
