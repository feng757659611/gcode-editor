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
#include "compileconfig.h"
#include <QtGui>

CompileConfig::CompileConfig(QWidget *parent):
    QDialog(parent)
{

#ifdef Q_WS_WIN32
    compilerFile = QDir("tcc").absoluteFilePath("tcc.exe");
#else
    compilerFile = QDir("/usr/bin").absoluteFilePath("gcc");
#endif
    args << "-Wall";
    createWidget();
    generalSetting();
    readSettings();
}

CompileConfig::~CompileConfig()
{
    writeSettings();
}

void CompileConfig::generalSetting()
{
    setWindowTitle(trUtf8("����������"));
    setFixedSize(400, 150);

    connect( noButton, SIGNAL(clicked()),
             this, SLOT(closeDialog()));
    connect( yesButton, SIGNAL(clicked()),
            this, SLOT(setCompileConfig()));
    connect( browserFileButton, SIGNAL(clicked()),
             this, SLOT(openExeFile()));
    connect( browserDirButton, SIGNAL(clicked()),
             this, SLOT(openDir()));
}

void CompileConfig::createWidget()
{
    groupBox = new QGroupBox(trUtf8("������"), this);

    compilePositionLabel = new QLabel(trUtf8("������(.exe)"), this);
    tempPositionLabel = new QLabel(trUtf8("��ʱ�ļ�λ��"), this);
    compileArgsLabel = new QLabel(trUtf8("�������"), this);
    compilePositionEdit = new QLineEdit(this);
    tempPositionEdit = new QLineEdit(this);
    compileArgsEdit = new QLineEdit(this);
    browserFileButton = new QPushButton(trUtf8("���"), this);
    browserFileButton->setFixedWidth(40);
    browserDirButton = new QPushButton(trUtf8("���"), this);
    browserDirButton->setFixedWidth(40);

    inLayout = new QGridLayout(groupBox);
    
    inLayout->addWidget(compilePositionLabel, 0, 0);
    inLayout->addWidget(compilePositionEdit, 0, 1);
    inLayout->addWidget(browserFileButton, 0, 2);

    inLayout->addWidget(tempPositionLabel, 1, 0);
    inLayout->addWidget(tempPositionEdit, 1, 1);
    inLayout->addWidget(browserDirButton, 1, 2);

    inLayout->addWidget(compileArgsLabel, 2, 0);
    inLayout->addWidget(compileArgsEdit, 2, 1);

    groupBox->setLayout(inLayout);

    yesButton = new QPushButton(trUtf8("ȷ��"), this);
    noButton = new QPushButton(trUtf8("ȡ��"), this);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(groupBox, 0, 0, 4, 4);
    mainLayout->addWidget(yesButton, 4, 2);
    mainLayout->addWidget(noButton, 4, 3);
}

void CompileConfig::showDialog()
{
    compilePositionEdit->setText(compilerFile);
    compileArgsEdit->setText(args.join(" "));
    tempPositionEdit->setText(workingDir);
    show();
}

void CompileConfig::closeDialog()
{
    close();
}

/* �����������ð�ťʱ�򣬵����������*/
void CompileConfig::openCompileConfig(QString fPath)
{
    if ( workingDir.isEmpty() )
        workingDir = fPath;
    if ( compilerFile.isEmpty() )
    {
#ifdef Q_WS_WIN32
        compilerFile = QDir("tcc").absoluteFilePath("tcc.exe");
#else
        compilerFile = QDir("/usr/bin").absoluteFilePath("gcc");
#endif
    }
    showDialog();
}

QString CompileConfig::getCompilerDir()
{
    return compilerFile;
}
QStringList CompileConfig::getArgs()
{
    return args;
}
QString CompileConfig::getWorkingDir()
{
    return workingDir;

}

/*
 * �û����ȷ��֮�����õ�ǰ�Ĳ�������
 * �Ѹ��ĵĶ������͸� runcompile*/
void CompileConfig::setCompileConfig()
{
    compilerFile = compilePositionEdit->text();
    ////////////////
    QString tmp;
    tmp = compileArgsEdit->text();
    args = tmp.split(" ", QString::SkipEmptyParts);
    ////////////////
    workingDir = tempPositionEdit->text();
    closeDialog();
    emit configChanged(compilerFile, workingDir, args);
}

/* ���û���.c�ļ���ʱ���������Ŀ¼Ϊ�գ�
 * ��.c�ļ�Ŀ¼�ĳ�Ĭ��Ŀ¼  */
void CompileConfig::autoSetWorkingDir(QString wkDir, QString fn)
{
    if ( workingDir.isEmpty() )
        workingDir = wkDir;
}

void CompileConfig::openExeFile()
{
    QString fileSuffix = "EXE Source File (*.exe);;"
                 "All Files (*.*)";
    QString currentDir = workingDir;
    QString fileName = QFileDialog::getOpenFileName(
                this, 
                trUtf8("���ļ�"),
                currentDir,
                fileSuffix,
                &fileSuffix//��չ��
                );//�����Ի��� ѡ���ļ�
    if (! fileName.isEmpty())
    {//�ǿ��ļ���
        compilerFile = fileName;
        compilePositionEdit->setText(fileName);
    }

}

void CompileConfig::openDir()
{
    QString currentDir = workingDir;
    QString DirName = QFileDialog::getExistingDirectory(
                this,
                trUtf8("���ļ�"),
                currentDir,
                QFileDialog::ShowDirsOnly
              | QFileDialog::DontResolveSymlinks);//�����Ի���
    if (! DirName.isEmpty())
    {//�ǿ��ļ���
        workingDir = DirName;
        tempPositionEdit->setText(DirName);
    }
}

void CompileConfig::readSettings()
{
    QSettings settings("5-up", "cPad");//��������
#ifdef Q_WS_WIN32
    compilerFile = settings.value("CompilerPosition", QDir("tcc").absoluteFilePath("tcc.exe")).toString();
#else
    compilerFile = settings.value("CompilerPosition", QDir("/usr/bin").absoluteFilePath("gcc")).toString();
#endif
    args = settings.value("CompilerArgs", "-Wall").toStringList();
    workingDir = settings.value("WorkingPosition", "").toString();
}

void CompileConfig::writeSettings()
{
    QSettings settings("5-up", "cPad");//��������
    settings.setValue("CompilerPosition", compilerFile);
    settings.setValue("CompilerArgs", args);
    settings.setValue("WorkingPosition", workingDir);
}
