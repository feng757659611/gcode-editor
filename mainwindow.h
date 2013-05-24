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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "centerwidget.h"//MainWindow ���Ŀؼ�ͷ�ļ�
#include "functionlistarea.h"//�����۵��ؼ�ͷ�ļ�
#include "findreplacearea.h"//�滻�ؼ�ͷ�ļ�
#include "statusbar.h"//״̬��ͷ�ļ�
#include "recomposedialog.h"//���Ű�Ի���
#include "cpadpalette.h" //��ɫ��
#include "autocomple.h"//�Զ���ȫ
#include "runcompile.h"//����
#include "compileconfig.h" //��������Ϣ

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
        Q_OBJECT
    public:
        MainWindow(QWidget *parent = 0);
        void openArgvFile(char *file);//����Ϊ�����������ļ�

    protected:
        void closeEvent(QCloseEvent *event);//�ر��¼�����
        void dragEnterEvent(QDragEnterEvent *event);//�Ͻ��¼�
        void dropEvent(QDropEvent *event);//�����¼�

    signals:
        void currentFileChanged(QString currentFile);//��ǰ�ļ��ı��ź�
        void currentDirChanged(QString currentDir);//��ǰĿ¼�ı��ź�
        void colorThemeChanged(int num);//���͵�ǰ������ɫ

    private slots:
        void newFile();//�½��ļ�����
        void openFile();//���ļ�����
        bool saveFile();//�����ļ�����
        bool saveAsFile();//���Ϊ�ļ�����
        void aboutDialog();//���ڶԻ�����
        void documentWasModified();//�жϱ༭���Ƿ��б��޸� �ڱ������� * ����ʾ
        void openRecentFile();//������ļ�
        void cleanRecentFile();//���������ļ�
        void statusBarVisible(bool visible);//������ʾ״̬��
        void menuBarVisible(bool visible);//������ʾ�˵���
        void fileToolVisible(bool visible);//�����ļ�����������
        void editToolVisible(bool visible);//���ñ༭����������
        void toolToolVisible(bool visible);//���ù��ܹ���������
        void openColorTheme();//��������ɫ
        void preCompile();//����ǰ��׼������
        bool preCompileSaveFile();
        void openCompileconfig();
        void compileButtonChecked();
        void switchAutoIndent(bool ok);//�Զ������Ŀ���
        void openHelp();
        void insertGcode();

    private:
        void createActions();//�������в˵����
        void createMenus();//�������в˵�����
        void createToolBars();//��������������
        void createStatusBar();//����״̬������
        void generalSetting();//�������һ������
        void readSettings();//���������趨�Ķ�ȡ
        void writeSettings();//���������趨��д��
        bool mayBeSave();//�жϱ༭�������Ƿ���Ҫ����
        void loadFileContent(const QString &fileName);//��ȡ�ļ�����
        bool saveFileContent(const QString &fileName);//д���ļ�����
        void setCurrentFile(const QString &fileName);//���õ�ǰ�ļ���
        void setCurrentDir(const QString &fileName);//���õ�ǰ·��
        void updateRecentFile();//��������ļ��˵���
        QString strippedName(const QString &fullFileName);//ȡ�ļ���
        void transTabToSpace(QString &codeString);//������ tab ��ո�

        QString currentFile;//��ǰ�ļ���
        QString currentDir;//��ǰ·��

        QMenu *fileMenu;//�ļ��˵�
        QAction *newAction;//�½��˵���
        QAction *openAction;//�򿪲˵���
        QAction *saveAction;//����˵���
        QAction *saveAsAction;//���Ϊ�˵���
        QMenu   *recentFileMenu;//����ļ��Ӳ˵�
        enum { MaxRecentFiles = 50 };//����ļ������Ŀ
        QAction *recentFileActions[MaxRecentFiles];//����ļ��˵���
        QAction *cleanRecentFileAction;//���������ļ�
        QAction *exitAction;//�˳��˵���

        QMenu *editMenu;//�༭�˵�
        QAction *undoAction;//�����˵���
        QAction *redoAction;//�����˵���
        QAction *cutAction;//���в˵���
        QAction *copyAction;//���Ʋ˵���
        QAction *pasteAction;//ճ���˵���
        QAction *selectAllAction;//ȫѡ�˵���
        QAction *deleteAction;//ɾ���˵���
        QAction *findAction;//���Ҳ˵���
        QAction *replaceAction;//�滻�˵���
        QAction *insertAction;

        QMenu *visualMenu;//��ͼ�˵�
        QAction *statusBarAction;//״̬��������
        QAction *fileToolAction;//�ļ�������
        QAction *editToolAction;//�༭������
        QAction *toolToolAction;//���ܹ�����
        QMenu *colorThemeMenu;//������ɫ
        enum { MaxColorThemes = 6 };//������ɫ����
        QAction *colorThemeActions[MaxColorThemes];//��ɫ�Ӳ˵�
        QActionGroup *colorThemeGroup;//������ɫ��
        
        QMenu *formatMenu;//��ʽ�˵�
        QAction *wrapAction;//�Զ����в˵���
        QAction *fontSettingAction;//����˵���

        QMenu *toolMenu;//����
        QAction *compileAction;//����˵���
        QAction *compileAndRunAction;//���벢����
        QAction *compileConfigAction;//��������
        QAction *syntaxHighlightAction;//�����˵���
        QAction *highlightLineAction;//�кŲ˵���
        QAction *recomposeAction;//���Ű�˵���
        QAction *functionListAction;//�����б�˵���
        QAction *functionCommentAction;//����ע�Ͳ˵���
        QAction *autoIndentAction;//�Զ������˵����
        QAction *autoCompleAction;//�Զ���ȫ�˵���
        QAction *quickCommentAction;//����ע�ͷ�ע�Ͳ˵���


        QMenu *helpMenu;//�����˵�
        QAction *helpAction;//�����˵���
        QAction *aboutAction;//���ڲ˵���

        QToolBar *fileToolBar;//�ļ�������
        QToolBar *editToolBar;//�༭������
        QToolBar *toolToolBar;//���߹�����

        CenterWidget *centerWidget;//���Ŀؼ�
        FunctionListArea *functionListArea;//�����۵�����ؼ�
        FindReplaceArea *findReplaceArea;//�����滻����ؼ�
        CodeEditor *codeEditor;//�༭���ؼ�
        QLineEdit  *lineEditor;
        StatusBar *statusBar;//״̬��
        RecomposeDialog *recomposeDialog;//���Ű�Ի���
        CpadPalette * cpadPalette;
        AutoComple *autoComple;//�Զ���ȫ
        RunCompile *runCompile;//����
        CompileConfig *compileConfig;
};

#endif // MAINWINDOW_H
