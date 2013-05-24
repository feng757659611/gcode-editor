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
#include "runcompile.h"

#include <QDebug>

RunCompile::RunCompile(QWidget *parent, CodeEditor *editor):
    QDockWidget(parent)
{
    codeEditor = editor;
    createWidget();
    generalSetting();
}

void RunCompile::compileClear()
{
    compileEdit->clear();
}

void RunCompile::compilePrograms()
{
    compileAndRun();
}

void RunCompile::createWidget()
{
    compileEdit = new QPlainTextEdit();
    compileEdit->setReadOnly(true);
    
    compileLable = new QLabel(tr("������"));

    oneLayout = new QGridLayout();
    twoLayout = new QGridLayout();
    oneWidget = new QWidget();
    twoWidget = new QWidget();
    clearCompile = new QPushButton(tr("���"));
    compileToRun = new QPushButton(tr("���벢����"));
}

void RunCompile::generalSetting()
{
    //���� Dock ���ƶ�����Ϊ����
    setAllowedAreas(Qt::BottomDockWidgetArea);
    //������ �ɹ� ���� �ɸ��� �������
    setFeatures(QDockWidget::DockWidgetClosable | 
                QDockWidget::DockWidgetFloatable |
                QDockWidget::DockWidgetMovable
                );
    setWindowTitle(tr("����"));//����ʱ���ñ���
    clearCompile->setFixedWidth(80);
    compileToRun->setFixedWidth(80);
    QMainWindow *main = qobject_cast<QMainWindow *>(parent());
    main->addDockWidget(Qt::BottomDockWidgetArea, this);
    hide();

    connect(clearCompile, SIGNAL(clicked()),
            this, SLOT(compileClear()));
/*    connect(compileToRun, SIGNAL(clicked()),
            this, SLOT(compilePrograms()));*/

}

bool RunCompile::checkTcc()
{
    QFile compiler(compilerAbsoluteFile);

    if ( ! compiler.exists() )
    {
        QMessageBox::critical(this, tr("����"),
                      tr("δ���ֱ�����"),
                tr("ȷ��"), 0, 0);
        return false;
    }
    else
        return true;
}

/* �˺������򿪱���ִ�н���  */
void RunCompile::showCompileAndRun(QString getCompiler, QString getWorkingDir, QStringList getArgs, QString fn)
{
    getConfig(getCompiler, getWorkingDir, getArgs, fn);
    compileAndRun();
    twoLayout->addWidget(compileLable, 0, 0);
    twoLayout->addWidget(compileToRun, 0, 1);
    twoLayout->addWidget(clearCompile, 0, 2);
    twoLayout->addWidget(compileEdit, 1, 0, 1, 3);
    twoWidget->setLayout(twoLayout);
    this->setWidget(twoWidget);

    setWindowTitle(tr("���벢����"));
    setMinimumHeight(150);
    show();
}

void RunCompile::showCompileOnly(QString getCompiler, QString getWorkingDir, QStringList getArgs, QString fn)
{
    getConfig(getCompiler, getWorkingDir, getArgs, fn);
    compileOnly();  //�������
    //====�����ǿؼ��Ű�
    oneLayout->addWidget(compileLable, 0, 0);
    oneLayout->addWidget(clearCompile, 0, 1);
    oneLayout->addWidget(compileEdit, 1, 0, 1, 2);
    oneWidget->setLayout(oneLayout);
    this->setWidget(oneWidget);

    setWindowTitle(tr("����"));
    setMinimumHeight(150);
    show();
}
void RunCompile::compileAndRun()
{
    bool ret = compileOnly(); //�ȱ���
    if ( ret == false )
        return;

    compileEdit->appendPlainText("Starting " + exeFile + "...");

#ifdef Q_WS_WIN32
    compile.start("cmd", QStringList() << "/C" << "start"  << "cmd" << "/K" << exeFile);
#else
    compile.start("xterm",QStringList() << "-hold" <<"-e" << exeFile);
#endif

    if ( ! compile.waitForFinished(5000) )
    {    //Ĭ�ϸ�5�룬�������ʱ�䣬���߳���û�������򷵻�
        return;
    }

}


bool RunCompile::compileOnly()
{
    if ( ! checkTcc() )
    {
        return false;
    }
    compile.setWorkingDirectory(workingDir);

    QStringList arg;
    int exit;
    arg << "-o" << exeFile << fName;

    compile.start(compilerAbsoluteFile, arg);

    if ( ! compile.waitForFinished(5000) ) //important
    {
        return false;
    }
    exit = compile.exitCode();
    error = compile.readAllStandardError();
    if ( error == "" )
        error = "Compiled " + exeFile + " successfully!";
    else
    {
        //codec = QTextCodec::codecForName("gbk");
        codec = QTextCodec::codecForLocale();
        error = codec->toUnicode(error.toLatin1().data());
    }

    compileEdit->appendPlainText(error);
    if ( exit == 1 )
        return false;
    return true;
}

void RunCompile::getConfig(QString getCompiler, QString getWorkingDir, QStringList getArgs, QString fn)
{
    fName = fn;
    compilerAbsoluteFile = getCompiler;
    workingDir = getWorkingDir;
    args = getArgs;
    QFileInfo f(fName);

    exeFile = QDir(workingDir).absoluteFilePath(f.baseName()+".exe");
}

/* slots */
void RunCompile::configChanged(QString getCompiler, QString getWorkingDir, QStringList getArgs)
{
    compilerAbsoluteFile = getCompiler;
    workingDir = getWorkingDir;
    args = getArgs;
    QFileInfo f(fName);
    exeFile = QDir(workingDir).absoluteFilePath(f.baseName()+".exe");
}

void RunCompile::setFileName(QString fn)
{
    fName = fn;
}

