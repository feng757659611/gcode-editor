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
#include "mainwindow.h"
#include  <QTextCursor>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent)
{
    //�������Ŀؼ�
    centerWidget = new CenterWidget(this);
        //�������Ŀؼ�
    setCentralWidget(centerWidget);

    //�������Ŀؼ��еı༭���ؼ���ַ
    codeEditor = centerWidget->codeEditor;
    codeEditor->setFocus();
    lineEditor = centerWidget->lineEditor;

    //���뺯���б�����
    functionListArea = new FunctionListArea(this, codeEditor);

    //����״̬��
    statusBar = new StatusBar(this);
        //״̬���õı༭��
    statusBar->setCodeEditor(codeEditor);

    recomposeDialog = new RecomposeDialog(this, codeEditor); 
    autoComple = new AutoComple(codeEditor);
    runCompile = new RunCompile(this, codeEditor);
    compileConfig = new CompileConfig(this);

    cpadPalette = new CpadPalette;

    createActions();//�������в˵���
    createMenus();//�����˵�
    createToolBars();//����������
    createStatusBar();//����״̬��

    //��������滻���� ���ݱ༭�� �˵���
    findReplaceArea = new FindReplaceArea(
            this, codeEditor,lineEditor,
            findAction, replaceAction);
   // findReplaceArea->codeEditor->insertPlainText("G00");
    generalSetting();//������һ������
    readSettings();//��ȡ���򱣴�����ò��Գ����������
    if(!recentFileActions[0]->data().toString().isEmpty())
    {
        loadFileContent(recentFileActions[0]->data().toString());
    }
//    QTextCursor tc=textCursor();
//         int position=this->findBlockByLineNumber(0).position();
//         tc.setPosition(position,QTextCursor::MoveAnchor);
//         setTextCursor(tc);
    setCursor(Qt::CrossCursor);

}

void MainWindow::openRecentFile()
{
    if (mayBeSave()) {
        QAction *action = qobject_cast<QAction *>(sender());
        if (action)
            loadFileContent(action->data().toString());
    }
}

void MainWindow::openColorTheme()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
        emit colorThemeChanged(action->data().toInt());
}

bool MainWindow::mayBeSave()
{
    if (codeEditor->document()->isModified()) {
        //�����Ի���ѯ���Ƿ���Ҫ����
        int ret = QMessageBox::warning(this, tr("warning"),
                     tr("file has been modified\n"
                        "do you want to save��"),
                     tr("save"),
                     tr("discard"),
                     tr("cancel"),
                     0, 2);
        if (ret == 0)//�����ļ�
            return saveFile();
        else if (ret == 2)//ȡ������
            return false;
    }
    return true;
}

void MainWindow::newFile()
{
    if (mayBeSave()) {
        codeEditor->clear();//��ձ༭��������
        setCurrentFile("");//���ļ� ������
    }
}
         
void MainWindow::openFile()
{
    if (mayBeSave()) {
        //��չ��
        QString fileSuffix = "C Source File (*.cnc);;"
                     "C Header File (*.h);;"
                     "Text File (*.txt);;"
                     "All Files (*.*)";
        QString fileName = QFileDialog::getOpenFileName(
                    this, 
                    tr("open file"),
                    currentDir,
                    fileSuffix,
                    &fileSuffix//��չ��
                    );//�����Ի��� ѡ���ļ�
        if (! fileName.isEmpty())//�ǿ��ļ��� �����ļ�����
            loadFileContent(fileName);
    }
}

bool MainWindow::saveFile()
{
    if (currentFile.isEmpty())//��ǰ�ļ�û������(�½����ļ�) ��Ҫ����
        return saveAsFile();
    else
        return saveFileContent(currentFile);
}

bool MainWindow::saveAsFile()
{
    //��չ��
    QString fileSuffix = "C Source File (*.c);;"
                         "C Header File (*.h);;"
                         "Text File (*.txt);;"
                         "All Files (*.*)";
    QString fileName = QFileDialog::getSaveFileName(
                    this,
                    tr("save file"),
                    currentDir + currentFile,
                    fileSuffix,
                    &fileSuffix
                    );//�����Ի��򱣴��ļ�
    if (fileName.isEmpty())
        return false;
    
    return saveFileContent(fileName);//д���ļ�����
}

void MainWindow::aboutDialog()
{   //�������ڶԻ���
    QMessageBox::about(this, tr("about cPad"),
            tr("cPad -Ccompile Version 1.0\n"
                   "Five-UP ��Ŀ������\n"
                   "cPad ���� GPL Э�鷢��"));
}

void MainWindow::documentWasModified()
{
    //�����ǰ�ļ����޸� �������� * �ű��
    setWindowModified(codeEditor->document()->isModified());
}

void MainWindow::transTabToSpace(QString &codeString)
{
    int codeLength , codePosition , codePositionLine;
    codeLength = codeString . length ( );
    for ( codePosition = codePositionLine = 0 ; codePosition < codeLength ; codePosition ++ )
    {
        if ( codeString [ codePosition ] == 9 )
        {
            codeString . remove ( codePosition , 1 );
            if ( codePositionLine % 4 == 0 )
                codeString . insert ( codePosition , "    " );
            else if ( codePositionLine % 4 == 1 )
                codeString . insert ( codePosition , "   " );
            else if ( codePositionLine % 4 == 2 )
                codeString . insert ( codePosition , "  " );
            else if ( codePositionLine % 4 == 3 )
                codeString . insert ( codePosition , " " );
            codeLength = codeString . length ( );
            codePositionLine ++;
        }
        else if ( codeString [ codePosition ] == '\n' )
            codePositionLine = 0;
        else
            codePositionLine ++;
    }

}

void MainWindow::loadFileContent(const QString &fileName)
{
    QFile file(fileName);
    //��ȡ�ı��ļ�ʧ��
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("cPad"),
                             tr("can't load file %1:\n%2")
                             .arg(fileName)
                             .arg(file.errorString()));
        return;
    }

    QTextStream in(&file);
    //in.setAutoDetectUnicode(true);
    //in.setCodec("UTF-8");
    //---------------------------------
    //qDebug() << in.codec()->name() << endl;
    //qDebug() << in.codec()->codecForLocale() << endl;
    //qDebug() << in.locale() << endl;
    //---------------------------------
#ifndef QT_NO_CURSOR//���仯
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif

    //QByteArray ba=str.
//    QTextCodec *mycodec=QTextCodec::codecForName("GBK");
//    in.setCodec(mycodec);
    QString str(in.readAll());;//(in.readAll());
    transTabToSpace(str);
    str.replace(" ","");
//    QTextCodec *tc = QTextCodec::codecForName("GBK");

//    QByteArray ba = file.readAll();

//    str = tc->toUnicode(ba);

    codeEditor->setPlainText(str);
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    setCurrentDir(fileName);
    compileConfig->autoSetWorkingDir(currentDir, fileName);//�����ļ���ͬʱ������������ʱ�ļ���Ϊ�գ����õ�ǰĿ¼Ϊ��ʱ�ļ���
    runCompile->setFileName(fileName);
    //statusBar()->showMessage(tr("�ļ�������"), 2000);//2000ms = 2s ��ʾʱ��
    statusBar->showMessage(tr("file has been load"), 2000);//2000ms = 2s ��ʾʱ��
}

bool MainWindow::saveFileContent(const QString &fileName)
{
    QFile file(fileName);
    //д���ı��ļ�ʧ��
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("cPad"),
                             tr("do not write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    //out.setAutoDetectUnicode(true);
    out.setCodec(QTextCodec::codecForLocale());
#ifndef QT_NO_CURSOR//���仯
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    out << codeEditor->toPlainText();
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    setCurrentDir(fileName);
    statusBar->showMessage(tr("file has been saved"), 2000);
    return true;
}

void MainWindow::setCurrentFile(const QString &fileName)
{
    currentFile = fileName;
    codeEditor->document()->setModified(false);//���ļ�����δ�޸�
    setWindowModified(false);

    QString shownName = currentFile;
    if (currentFile.isEmpty()) {//�Կ��ļ������� untitled.c ��ʾ
        shownName = "untitled.c";
        emit currentFileChanged(strippedName(shownName));//�½��ļ���ʾ shownName
    }
    else {
        emit currentFileChanged(strippedName(currentFile));//�����ļ���ʾ currentFile

        QSettings settings("5-up", "cPad");
        QStringList files = settings.value("recentFileList").toStringList();
        files.removeAll(fileName);
        files.prepend(fileName);
        while (files.size() > MaxRecentFiles)
            files.removeLast();

        settings.setValue("recentFileList", files);
    }
    updateRecentFile();
    setWindowFilePath(shownName);//��ʾ����
}

void MainWindow::setCurrentDir(const QString &fileName)
{
    currentDir = QFileInfo(fileName).dir().path();
    emit currentDirChanged(currentDir);
}

void MainWindow::updateRecentFile()
{
    QSettings settings("5-up", "cPad");
    QStringList files = settings.value("recentFileList").toStringList();

    int numRecentFiles = qMin(files.size(), (int)MaxRecentFiles);

    recentFileMenu->setEnabled(numRecentFiles > 0);

    for (int i = 0; i < numRecentFiles; ++i) {
        QString text = tr("&%1 %2").arg(i + 1).arg(strippedName(files[i]));
        recentFileActions[i]->setText(text);
        recentFileActions[i]->setData(files[i]);
        recentFileActions[i]->setVisible(true);
    }
    for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
        recentFileActions[j]->setVisible(false);
}

void MainWindow::cleanRecentFile()
{
    QSettings settings("5-up", "cPad");
    QStringList files = settings.value("recentFileList").toStringList();
    files.clear();
    settings.setValue("recentFileList", files);
    updateRecentFile();
}

QString MainWindow::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

void MainWindow::generalSetting()
{
    //���� Modified �޸��źŵ�����
    connect(codeEditor->document(), SIGNAL(contentsChanged()),
            this, SLOT(documentWasModified()));
    setCurrentFile("");//ֱ�Ӵ򿪳���ʱ����Ϊ�½��ļ�
    setWindowIcon(QIcon(":/resources/donkey32.png"));//�������Ͻ�ͼ��
    setContextMenuPolicy(Qt::NoContextMenu);//ȥ���Ҽ��˵�
    setAcceptDrops(true);

    connect(this, SIGNAL(colorThemeChanged(int)),
            cpadPalette, SLOT(myFavorate(int)));
    connect(cpadPalette, SIGNAL(groupChanged(QList<QColor>)),
            codeEditor, SLOT(changeColorGroup(QList<QColor>)));
    connect(cpadPalette, SIGNAL(groupChanged(QList<QColor>)),
            centerWidget->syntaxHighlighter, SLOT(changeColorGroup(QList<QColor>)));
    connect(codeEditor, SIGNAL(needAutoComple(int)),
            autoComple, SLOT(doAutoComple(int)));
    connect(codeEditor, SIGNAL(fontChanged(QFont)),
            autoComple, SLOT(fontSettings(QFont)));
    connect(runCompile->compileToRun, SIGNAL(clicked()),
            this, SLOT(compileButtonChecked()));
}

void MainWindow::createActions()
{
    newAction = new QAction(QIcon(":/resources/new.png"), tr("new(&N)"), this);
    newAction->setShortcut(QKeySequence::New);
    newAction->setStatusTip(tr("new file"));
    connect(newAction, SIGNAL(triggered()), this, SLOT(newFile()));

    openAction = new QAction(QIcon(":/resources/open.png"), tr("open(&O)..."), this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("open file"));
    connect(openAction, SIGNAL(triggered()), this, SLOT(openFile()));

    saveAction = new QAction(QIcon(":/resources/save.png"), tr("save(&S)"), this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("save file"));
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));

    saveAsAction = new QAction(QIcon(":/resources/saveas.png"), tr("save as(&A)..."), this);
    saveAsAction->setShortcut(QKeySequence::SaveAs);
    saveAsAction->setStatusTip(tr("save as"));
    connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAsFile()));

    for (int i = 0; i < MaxRecentFiles; ++i) {
        recentFileActions[i] = new QAction(this);
        recentFileActions[i]->setVisible(false);
        connect(recentFileActions[i], SIGNAL(triggered()),
                this, SLOT(openRecentFile()));
    }

    cleanRecentFileAction = new QAction(tr("delete all"), this);
    cleanRecentFileAction->setStatusTip(tr("clear recent file"));
    connect(cleanRecentFileAction, SIGNAL(triggered()),
            this, SLOT(cleanRecentFile()));

    exitAction = new QAction(tr("quit(&X)"), this);
    exitAction->setShortcut(QKeySequence::Quit);
    exitAction->setStatusTip(tr("quit application"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    
    undoAction = new QAction(QIcon(":/resources/undo.png"), tr("undo(&U)"), this);
    undoAction->setShortcut(QKeySequence::Undo);
    undoAction->setStatusTip(tr("undo last operation"));
    //Ĭ�����ò�����
    undoAction->setEnabled(false);
    connect(undoAction, SIGNAL(triggered()), codeEditor, SLOT(undo()));
    //�༭���ɳ����ź���˵��������������
    connect(codeEditor, SIGNAL(undoAvailable(bool)),
            undoAction, SLOT(setEnabled(bool)));

    redoAction = new QAction(QIcon(":/resources/redo.png"), tr("redo(&R)"), this);
    redoAction->setShortcut(QKeySequence::Redo);
    redoAction->setStatusTip(tr("redo last operation"));
    //Ĭ�����ò�����
    redoAction->setEnabled(false);
    connect(redoAction, SIGNAL(triggered()), codeEditor, SLOT(redo()));
    //�༭���������ź���˵��������������
    connect(codeEditor, SIGNAL(redoAvailable(bool)),
            redoAction, SLOT(setEnabled(bool)));

    cutAction = new QAction(QIcon(":/resources/cut.png"), tr("cut(&T)"), this);
    cutAction->setShortcut(QKeySequence::Cut);
    cutAction->setStatusTip(tr("cut select to clipboard"));
    //Ĭ�����ò�����
    cutAction->setEnabled(false);
    connect(cutAction, SIGNAL(triggered()), codeEditor, SLOT(cut()));
    //�༭���ɸ����ź���˵��������������
    connect(codeEditor, SIGNAL(copyAvailable(bool)),
            cutAction, SLOT(setEnabled(bool)));

    copyAction = new QAction(QIcon(":/resources/copy.png"), tr("copy(&C)"), this);
    copyAction->setShortcut(QKeySequence::Copy);
    copyAction->setStatusTip(tr("copy select to clipboard"));
    //Ĭ�����ò�����
    copyAction->setEnabled(false);
    connect(copyAction, SIGNAL(triggered()), codeEditor, SLOT(copy()));
    //�༭���ɸ����ź���˵��������������
    connect(codeEditor, SIGNAL(copyAvailable(bool)),
            copyAction, SLOT(setEnabled(bool)));

    pasteAction = new QAction(QIcon(":/resources/paste.png"), tr("paste(&P)"), this);
    pasteAction->setShortcut(QKeySequence::Paste);
    pasteAction->setStatusTip(tr("paste clipboard to current place"));
    connect(pasteAction, SIGNAL(triggered()), codeEditor, SLOT(paste()));

    selectAllAction = new QAction(QIcon(":/resources/selectall.png"), tr("select all(&A)"), this);
    selectAllAction->setShortcut(QKeySequence::SelectAll);
    selectAllAction->setStatusTip(tr("select all"));
    connect(selectAllAction, SIGNAL(triggered()), codeEditor, SLOT(selectAll()));

    insertAction= new QAction(QIcon(":/resources/paste.png"), tr("insert(&I)"), this);
    insertAction->setShortcut(QKeySequence::Paste);
    insertAction->setStatusTip(tr("insert"));
    connect(insertAction,SIGNAL(triggered()),this,SLOT(insertGcode()));
    deleteAction = new QAction(QIcon(":/resources/delete.png"), tr("delete(&L)"), this);
    deleteAction->setShortcut(QKeySequence::Delete);
    deleteAction->setStatusTip(tr("delete all"));
    //Ĭ�����ò�����
    deleteAction->setEnabled(false);
    connect(deleteAction, SIGNAL(triggered()),
            codeEditor, SLOT(deleteSelectedText()));
    //�༭���ɸ����ź���˵��������������
    connect(codeEditor, SIGNAL(copyAvailable(bool)),
            deleteAction, SLOT(setEnabled(bool)));

    //findAction = findArea->toggleViewAction();//ʹ�� FindArea �ṩ�Ĳ˵���
    findAction = new QAction(this);
    findAction->setText(tr("find(&F)"));
    findAction->setIcon(QIcon(":/resources/find.png"));
    findAction->setShortcut(QKeySequence::Find);
    findAction->setStatusTip(tr("find string"));
    findAction->setCheckable(true);

    //replaceAction = replaceArea->toggleViewAction();//ʹ�� ReplaceArea �ṩ�Ĳ˵��� 
    replaceAction = new QAction(this);
    replaceAction->setText(tr("replace(&R)"));
    replaceAction->setIcon(QIcon(":/resources/replace.png"));
    replaceAction->setShortcut(QKeySequence::Replace);
    replaceAction->setStatusTip(tr("replace string"));
    replaceAction->setCheckable(true);
    
    statusBarAction = new QAction(tr("status bar"), this);
    statusBarAction->setShortcut(Qt::Key_F9);
    statusBarAction->setStatusTip(tr("show status bar or not"));
    statusBarAction->setCheckable(true);
    connect(statusBarAction, SIGNAL(toggled(bool)), 
            this, SLOT(statusBarVisible(bool)));

    fileToolAction = new QAction(tr("file bar(&F)"), this);
    fileToolAction->setStatusTip(tr("show file bar or not"));
    fileToolAction->setCheckable(true);
    fileToolAction->setChecked(true);
    connect(fileToolAction, SIGNAL(toggled(bool)), 
            this, SLOT(fileToolVisible(bool)));

    editToolAction = new QAction(tr("edit bar(&E)"), this);
    editToolAction->setStatusTip(tr("show edit bar or not"));
    editToolAction->setCheckable(true);
    editToolAction->setChecked(true);
    connect(editToolAction, SIGNAL(toggled(bool)), 
            this, SLOT(editToolVisible(bool)));

    toolToolAction = new QAction(tr("tool bar(&U)"), this);
    toolToolAction->setStatusTip(tr("show tool bar or not "));
    toolToolAction->setCheckable(true);
    toolToolAction->setChecked(true);
    connect(toolToolAction, SIGNAL(toggled(bool)), 
            this, SLOT(toolToolVisible(bool)));

    syntaxHighlightAction = new QAction(tr("highlight syntax"), this);
    syntaxHighlightAction->setStatusTip(tr("show syntax highlight"));
    syntaxHighlightAction->setCheckable(true);
    connect(syntaxHighlightAction, SIGNAL(toggled(bool)),
            centerWidget->syntaxHighlighter, SLOT(turnOnSyntaxHighlight(bool)));

    highlightLineAction = new QAction(tr("highlight cursor line"), this);
    highlightLineAction->setStatusTip(tr("highlight cursor line"));
    highlightLineAction->setCheckable(true);
    connect(highlightLineAction, SIGNAL(toggled(bool)),
            codeEditor, SLOT(turnOnHighlightCurrentLine(bool)));
    
    colorThemeActions[0] = new QAction(tr("Desert"), this);
    colorThemeActions[1] = new QAction(tr("Koehler"), this);
    colorThemeActions[2] = new QAction(tr("Morning"), this);
    colorThemeActions[3] = new QAction(tr("Ron"), this);
    colorThemeActions[4] = new QAction(tr("Sample"), this);
    colorThemeActions[5] = new QAction(tr("Dark"), this);

    colorThemeGroup = new QActionGroup(this);
    for ( int i = 0; i < MaxColorThemes; i++ ) {
        colorThemeActions[i]->setData(i);
        colorThemeActions[i]->setCheckable(true);
        colorThemeGroup->addAction(colorThemeActions[i]);
        connect(colorThemeActions[i], SIGNAL(triggered()),
                this, SLOT(openColorTheme()));
    }

    wrapAction = new QAction(tr("auto wrap(&W)"), this);
    wrapAction->setStatusTip(tr("auto wrap"));
    wrapAction->setCheckable(true);//���ô˲˵���Ϊ��ѡ��(���ƿ���)
    //����״̬���ӱ༭�������ÿ��ص� SLOT ����
    connect(wrapAction, SIGNAL(toggled(bool)), codeEditor, 
            SLOT(setWrapMode(bool)));

    fontSettingAction = new QAction(QIcon(":/resources/font.png"), tr("select font(&F)..."), this);
    fontSettingAction->setStatusTip(tr("set font"));
    //�������庯��
    connect(fontSettingAction, SIGNAL(triggered()), codeEditor, 
            SLOT(fontSettings()));

    compileAction = new QAction(QIcon(":resources/build.png"), tr("compile"), this);
    compileAction->setShortcut(Qt::Key_F5);
    compileAction->setStatusTip(tr("compile this file"));
    compileAction->setData(0);
    connect(compileAction, SIGNAL(triggered()), 
            this, SLOT(preCompile()));

    compileAndRunAction = new QAction(QIcon(":resources/run.png"), tr("compile and run"), this);
    compileAndRunAction->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_F5));
    compileAndRunAction->setStatusTip(tr("compile and run this app"));
    compileAndRunAction->setData(1);
    connect(compileAndRunAction, SIGNAL(triggered()), 
            this, SLOT(preCompile()));

    recomposeAction = new QAction(QIcon(":/resources/recompose.png"), tr("rewrap(&R)"), this);
    recomposeAction->setShortcut(Qt::Key_F6);
    recomposeAction->setStatusTip(tr("rewrap "));
    connect(recomposeAction, SIGNAL(triggered()),
            recomposeDialog, SLOT(open()));

    compileConfigAction = new QAction(tr("compile settings"), this);
    //compileConfigAction->setShortcut(Qt::Key_F10);
    compileConfigAction->setStatusTip(tr("compile settings"));
    connect(compileConfigAction, SIGNAL(triggered()),
            this, SLOT(openCompileconfig()));
    //�����ȷ��ʱ������"���벢ִ��"�Ի��򣬲��������Ѿ�������
    connect( compileConfig, SIGNAL(configChanged(QString,QString,QStringList)),
             runCompile, SLOT(configChanged(QString,QString,QStringList)));

    functionListAction = new QAction(QIcon(":/resources/functionlist.png"), tr("function list(&F)"), this);
    functionListAction->setShortcut(Qt::Key_F7);
    functionListAction->setStatusTip(tr("show function list"));
    functionListAction->setCheckable(true);
    connect(functionListAction, SIGNAL(toggled(bool)),
            functionListArea, SLOT(enableArea(bool)));

    functionCommentAction = new QAction(QIcon(":/resources/functioncomment.png"), tr("create comment(&C)"), this);
    functionCommentAction->setShortcut(Qt::Key_F8);
    functionCommentAction->setStatusTip(tr("if cursor is at start of function, then creat comment"));
    connect(functionCommentAction, SIGNAL(triggered()),
            codeEditor, SLOT(functionComment()));

    autoIndentAction = new QAction(tr("auto indent"), this);
    autoIndentAction->setStatusTip(tr("open indention or not"));
    autoIndentAction->setCheckable(true);
    connect(autoIndentAction, SIGNAL(toggled(bool)),
            this, SLOT(switchAutoIndent(bool)));

    autoCompleAction = new QAction(QIcon(":/resources/autocomple.png"), tr("auto compelte"), this);
    autoCompleAction->setShortcut(QKeySequence(Qt::ALT+Qt::Key_N));
    autoCompleAction->setStatusTip(tr("do auto complete find"));
    connect(autoCompleAction, SIGNAL(triggered()),
            autoComple, SLOT(doAutoComple()));

    quickCommentAction = new QAction(QIcon(":/resources/quickcomment.png"), tr("fast comment or not"), this);
    quickCommentAction->setShortcut(QKeySequence(Qt::ALT+Qt::Key_M));
    quickCommentAction->setStatusTip(tr("fast comment or not current line"));
    connect(quickCommentAction, SIGNAL(triggered()),
            codeEditor, SLOT(quickComment()));

    helpAction = new QAction(QIcon(":/resources/help.png"), tr("see help(&H)"), this);
    helpAction->setShortcut(QKeySequence(Qt::Key_F1));
    helpAction->setStatusTip(tr("look help"));
    connect(helpAction, SIGNAL(triggered()),
            this, SLOT(openHelp()));

    aboutAction = new QAction(tr("about(&A)"), this);
    aboutAction->setStatusTip(tr("show about"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(aboutDialog()));

}

void MainWindow::readSettings()
{
    QSettings settings("5-up", "cPad");//��������

    //��ȡ WrapMode ��ö��
    QPlainTextEdit::LineWrapMode wrapMode =
        static_cast<QPlainTextEdit::LineWrapMode>(
                settings.value("WrapMode", QPlainTextEdit::WidgetWidth).toUInt());
        //��ȡ������ WrapMode
    codeEditor->setLineWrapMode(wrapMode);
    if (wrapMode == QPlainTextEdit::WidgetWidth)
        wrapAction->setChecked(true);
    else 
        wrapAction->setChecked(false);

    //��ȡ���ڴ�Сλ��
    QPoint pos = settings.value("MainWindowPos", QPoint(200, 50)).toPoint();
    QSize size = settings.value("MainWindowSize", QSize(800, 600)).toSize();
    bool maxOpen = settings.value("MainWindowMaxed", "false").toBool();
    if (maxOpen)
        this->showMaximized();
    else {
        resize(size);
        move(pos);
    }


    //��ȡ��������״̬������״̬
    bool visible;
    visible = settings.value("StatusBarVisible", "true").toBool();
    statusBarAction->setChecked(visible);
    statusBarVisible(visible);
    visible = settings.value("FileToolVisible", "true").toBool();
    fileToolAction->setChecked(visible);
    visible = settings.value("EditToolVisible", "true").toBool();
    editToolAction->setChecked(visible);
    visible = settings.value("ToolToolVisible", "true").toBool();
    toolToolAction->setChecked(visible);

    //��ȡ�﷨������������ǰ�С��Զ���������
    bool open;
    open = settings.value("syntaxHighlighterVisible", "true").toBool();
    syntaxHighlightAction->setChecked(open);
    open = settings.value("highlightLineVisible", "true").toBool();
    highlightLineAction->setChecked(open);
    open = settings.value("AutoIndentSwitch", "true").toBool();
    autoIndentAction->setChecked(open);

    //��ȡ��ǰĿ¼
    currentDir = settings.value("CurrentDir", QDir().homePath()).toString();
    currentDir += "/.";//Ϊ�˱��Ե�ĩβ
    setCurrentDir(currentDir);

    //��ȡ������ɫ
    int colorNum;
    colorNum = settings.value("ColorThemeNumber", 2).toInt();
    colorThemeActions[colorNum]->setChecked(true);
    emit colorThemeChanged(colorNum);
}

void MainWindow::writeSettings()
{
    QSettings settings("5-up", "cPad");//��������
    
    //д�� WrapMode ��ö��
    QPlainTextEdit::LineWrapMode wrapMode = codeEditor->lineWrapMode();
    settings.setValue("WrapMode", (uint)wrapMode);

    //��¼���ڴ�Сλ��
    if (!isMaximized()) {
        settings.setValue("MainWindowPos", pos());
        settings.setValue("MainWindowSize", size());
    }
    settings.setValue("MainWindowMaxed", this->isMaximized());

    //��¼��������״̬������״̬
    settings.setValue("StatusBarVisible", statusBarAction->isChecked());
    settings.setValue("FileToolVisible", fileToolAction->isChecked());
    settings.setValue("EditToolVisible", editToolAction->isChecked());
    settings.setValue("ToolToolVisible", toolToolAction->isChecked());

    //��¼�����С��﷨�������Զ���������״̬
    settings.setValue("syntaxHighlighterVisible", syntaxHighlightAction->isChecked());
    settings.setValue("highlightLineVisible", highlightLineAction->isChecked());
    settings.setValue("AutoIndentSwitch", autoIndentAction->isChecked());

    //���õ�ǰĿ¼
    settings.setValue("CurrentDir", currentDir);

    //������ɫ��
    for (int i = 0; i < MaxColorThemes; i++) {
        if (colorThemeActions[i]->isChecked())
            settings.setValue("ColorThemeNumber", i);
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (mayBeSave()) {
        writeSettings();//�ر�֮ǰд������
        event->accept();
    } 
    else//����ʧ��ȡ���ر�
        event->ignore();
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("file(&F)"));
    fileMenu->addAction(newAction);
    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAction);
    fileMenu->addAction(saveAsAction);
    recentFileMenu = fileMenu->addMenu(QIcon(":/resources/recentfile.png"), tr("recent file(&T)"));
    for (int i = 0; i < MaxRecentFiles; ++i)
        recentFileMenu->addAction(recentFileActions[i]);
    recentFileMenu->addSeparator();
    recentFileMenu->addAction(cleanRecentFileAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("edit(&E)"));
    editMenu->addAction(undoAction);
    editMenu->addAction(redoAction);
    editMenu->addSeparator();
    editMenu->addAction(cutAction);
    editMenu->addAction(copyAction);
    editMenu->addAction(pasteAction);
    editMenu->addAction(selectAllAction);
    editMenu->addAction(deleteAction);
    editMenu->addSeparator();
    editMenu->addAction(findAction);
    editMenu->addAction(replaceAction);
    editMenu->addAction(insertAction);

    //menuBar()->addSeparator();
    visualMenu = menuBar()->addMenu(tr("view(&V)"));
    //visualMenu->addAction(menuBarAction);
    visualMenu->addAction(statusBarAction);
    visualMenu->addAction(fileToolAction);
    visualMenu->addAction(editToolAction);
    visualMenu->addAction(toolToolAction);
    visualMenu->addSeparator();
    visualMenu->addAction(syntaxHighlightAction);
    visualMenu->addAction(highlightLineAction);
    visualMenu->addSeparator();
    colorThemeMenu = visualMenu->addMenu(QIcon(":/resources/color.png"), tr("theme color"));
    for (int i = 0; i < MaxColorThemes; i++ ) 
        colorThemeMenu->addAction(colorThemeActions[i]);

    formatMenu = menuBar()->addMenu(tr("format(&O)"));
    formatMenu->addAction(wrapAction);
    formatMenu->addAction(autoIndentAction);
    formatMenu->addSeparator();
    formatMenu->addAction(fontSettingAction);

    toolMenu = menuBar()->addMenu(tr("tool(&T)"));
    toolMenu->addAction(compileAction);
    toolMenu->addAction(compileAndRunAction);
    toolMenu->addAction(compileConfigAction);
    toolMenu->addSeparator();
    toolMenu->addAction(recomposeAction);
    toolMenu->addAction(functionListAction);
    toolMenu->addAction(functionCommentAction);
    toolMenu->addAction(quickCommentAction);
    toolMenu->addAction(autoCompleAction);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("help"));
    helpMenu->addAction(helpAction);
    helpMenu->addAction(aboutAction);
}


void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("file tool bar"));
    fileToolBar->setIconSize(QSize(26,26));
    fileToolBar->addAction(newAction);
    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAction);

    editToolBar = addToolBar(tr("edit tool bar"));
    editToolBar->setIconSize(QSize(26,26));
    editToolBar->addAction(undoAction);
    editToolBar->addAction(redoAction);
    editToolBar->addSeparator();
    editToolBar->addAction(cutAction);
    editToolBar->addAction(copyAction);
    editToolBar->addAction(pasteAction);
    editToolBar->addSeparator();
    editToolBar->addAction(findAction);
    editToolBar->addAction(replaceAction);
    editToolBar->addAction(insertAction);

    toolToolBar = addToolBar(tr("function tool bar"));
    toolToolBar->setIconSize(QSize(26,26));
    toolToolBar->addAction(compileAction);
    toolToolBar->addAction(compileAndRunAction);
    toolToolBar->addSeparator();
    toolToolBar->addAction(recomposeAction);
    toolToolBar->addAction(functionListAction);
    toolToolBar->addAction(functionCommentAction);
    toolToolBar->addAction(quickCommentAction);
    toolToolBar->addAction(autoCompleAction);
}

void MainWindow::createStatusBar()
{
    setStatusBar(statusBar);

    connect(codeEditor, SIGNAL(cursorPositionChanged()),
            statusBar, SLOT(updateTextCursorLabel()));

    connect(codeEditor, SIGNAL(blockCountChanged(int)),
            statusBar, SLOT(updateTextCursorLabel()));

    connect(this, SIGNAL(currentDirChanged(QString)),
            statusBar, SLOT(updateCurrentDirLabel(QString)));

    connect(this, SIGNAL(currentFileChanged(QString)),
            statusBar, SLOT(updateCurrentFileLabel(QString)));
}

void MainWindow::menuBarVisible(bool visible)
{
    menuBar()->setVisible(visible);
}

void MainWindow::statusBarVisible(bool visible)
{
    statusBar->setVisible(visible);
}

void MainWindow::fileToolVisible(bool visible)
{
    fileToolBar->setVisible(visible);
}

void MainWindow::editToolVisible(bool visible)
{
    editToolBar->setVisible(visible);
}

void MainWindow::toolToolVisible(bool visible)
{
    toolToolBar->setVisible(visible);
}

void MainWindow::openArgvFile(char *argv)
{
    if (mayBeSave()) {
        //����ת����Դ
        QTextCodec *codec = QTextCodec::codecForLocale();
        //ת�� Unicode
        QString str = codec->toUnicode(argv);
        loadFileContent(str);
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
        event->acceptProposedAction();
}

void MainWindow::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
    {
        return;
    }
    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty())
    {
        return;
    }
    //QString filePath = QFileInfo(fileName).canonicalFilePath();

    if (mayBeSave()) {
        loadFileContent(fileName);
    }
}

void MainWindow::preCompile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    int code = 0;
    if (action)
        code = action->data().toInt();
    //������ ��ʾ�Զ�����
    if ( ! preCompileSaveFile() )
        return;
    if (code)
        runCompile->showCompileAndRun(compileConfig->getCompilerDir(),
                                      compileConfig->getWorkingDir(),
                                      compileConfig->getArgs(),
                                      currentFile);
    else
        runCompile->showCompileOnly(compileConfig->getCompilerDir(),
                                    compileConfig->getWorkingDir(),
                                    compileConfig->getArgs(),
                                    currentFile);
}
bool MainWindow::preCompileSaveFile()
{
    //������ ��ʾ�Զ�����
    if (codeEditor->document()->isModified() || currentFile.isEmpty()) {
        //�����Ի���ѯ���Ƿ���Ҫ����
        int ret = QMessageBox::warning(this, tr("warning"),
                     tr("file has been modified\n"
                        "do you want to save "),
                     tr("save and compile"),
                     tr("cancel"),
                     0, 0);
        if (ret == 0) {//�����ļ�
            if (!saveFile())
                return false;
        }
        else if (ret == 1)//ȡ������
            return false;
    }
    return true;
}

void MainWindow::compileButtonChecked()
{
    if ( preCompileSaveFile() )
        runCompile->showCompileAndRun(compileConfig->getCompilerDir(),
                                      compileConfig->getWorkingDir(),
                                      compileConfig->getArgs(),
                                      currentFile);
    return;
}

void MainWindow::openCompileconfig()
{
    compileConfig->openCompileConfig(currentDir);
}

void MainWindow::switchAutoIndent(bool ok)
{
    QSettings settings("5-up", "cPad");

    settings.setValue("AutoIndentSwitch", ok);
}

void MainWindow::openHelp()
{
    QString helpFile = QDir("doc/").absoluteFilePath("help.html");
    QDesktopServices::openUrl(QUrl(helpFile, QUrl::TolerantMode));

}
void MainWindow::insertGcode()
{
    QString string=lineEditor->text();
    codeEditor->insertPlainText(string);
}
