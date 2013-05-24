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
#ifndef RUNCOMPILE_H
#define RUNCOMPILE_H

#include <QDockWidget>
#include <QDir>
#include <QProcess>
#include "codeeditor.h"
#include "compileconfig.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QGridLayout;
class QString;
class QStringList;
class QPlainTextEdit;
class QPushButton;
QT_END_NAMESPACE

class RunCompile : public QDockWidget
{
    Q_OBJECT
public:
    RunCompile(QWidget *parent, CodeEditor *editor);
    void showCompileOnly(QString getCompiler, QString getWorkingDir, QStringList getArgs, QString fn);
    void showCompileAndRun(QString getCompiler, QString getWorkingDir, QStringList getArgs, QString fn);
    void setFileName(QString fn);
    QPushButton *clearCompile, *compileToRun;
public slots:
    void compileClear();
    void compilePrograms();
    void configChanged(QString getCompiler, QString getWorkingDir, QStringList getArgs);
private:
    void createWidget();
    void generalSetting();
    bool compileOnly();
    void compileAndRun();
    bool checkTcc();
    void getConfig(QString getCompiler, QString getWorkingDir, QStringList getArgs, QString fn);
    QProcess compile;  //����cmd����
    //===
    QString compilerAbsoluteFile; //tcc ����������·��
    //===
    QStringList args; //����Ĳ���
    QString workingDir; //��������� exe ���·��
    QString exeFile;
    //
    QString output;
    QString error;
    QString input;
    QTextCodec * codec;
    QString fName, fPath;
    QPlainTextEdit *compileEdit;
    QLabel *compileLable;
    QGridLayout *oneLayout, *twoLayout;
    QWidget *oneWidget, *twoWidget;
    CodeEditor *codeEditor;

};

#endif // RUNCOMPILE_H
