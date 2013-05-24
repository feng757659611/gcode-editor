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
#include "findreplacearea.h"
#include "cpadpalette.h"

FindReplaceArea::FindReplaceArea(QWidget *parent, CodeEditor *editor,QLineEdit *lineEdit,
        QAction *find, QAction *replace):
    QDockWidget(parent)
{
    codeEditor = editor;
    findAction = find;
    replaceAction = replace;
    lineedit=lineEdit;
    //findLineEdit =lineEdit;
    //findLineEdit->insert(line->displayText());
    createWidget();
    generalSetting();
    lineEditkeyboard = new Keyboard();
    findFlag = 0;  // for the check box;

}

void FindReplaceArea::closeEvent(QCloseEvent *event)
{
    replaceAction->setChecked(false);
    findAction->setChecked(false);
    event->accept();
}

void FindReplaceArea::createWidget()
{
    //����ؼ��Ͳ��ֿؼ�
    findWidget = new QWidget();
    replaceWidget = new QWidget();
    findLayout = new QGridLayout();
    findWidget->setLayout(findLayout);
    replaceLayout = new QGridLayout();
    replaceWidget->setLayout(replaceLayout);
    findLabel = new QLabel(tr("find(&S):"));
    replaceLabel = new QLabel(tr("replace with(&P):"));
    findLineEdit = new QLineEdit();
    replaceLineEdit = new QLineEdit();
    previousButton = new QPushButton(QIcon(":/resources/previous.png"), 
                        tr("up(&U)"));
    nextButton     = new QPushButton(QIcon(":/resources/next.png"), 
                        tr("down(&D)"));
    closeButton    = new QPushButton(tr("close(&X)"));
    replaceButton  = new QPushButton(tr("replace(&R)"));
    replaceAllButton = new QPushButton(tr("replace all(&A)"));
    caseSensitive   = new QCheckBox(tr("match case(&C)"));
    consistentMatch = new QCheckBox(tr("match whole word(&W)"));
    highLightResult = new QCheckBox(tr("hightlight results(&L)"));
    highLightResult->setChecked(true);

}

void FindReplaceArea::transLayout(bool topLevel)
{
    if (topLevel) {
        floatingLayout();
    }
    else {
        dockedLayout();
    }
//    findLineEdit->clear();
//    findLineEdit->insert(lineedit->displayText());
    //runtimeSearch(lineedit->displayText());
}

void FindReplaceArea::openFindArea(bool open)
{
    if (open) {
        replaceAction->setChecked(false);
        findAction->setChecked(true);
        currentMode = FindMode;
        transLayout(isFloating());
        show();
    }
    else {
        close();
        clearAll();
    }
    findLineEdit->setFocus();

}

void FindReplaceArea::openReplaceArea(bool open)
{
    if (open) {
        findAction->setChecked(false);
        replaceAction->setChecked(true);
        currentMode = ReplaceMode;
        transLayout(isFloating());
        show();
    }
    else {
        close();
        clearAll();
    }
    findLineEdit->setFocus();
}

void FindReplaceArea::floatingLayout()
{
    if (currentMode == FindMode) {
        setWidget(findWidget);//��������Ϊ����

        setWindowTitle(tr("����"));

        findLineEdit->setFixedSize(195, 22);

        findLayout->addWidget(findLabel, 0, 0);
        findLayout->addWidget(findLineEdit, 0, 1, 1, 2);
        findLayout->addWidget(previousButton, 0, 3);
        findLayout->addWidget(nextButton, 0, 4);
        findLayout->addWidget(caseSensitive, 1, 1);
        findLayout->addWidget(consistentMatch, 1, 2);
        findLayout->addWidget(highLightResult, 1, 3);
        findLayout->addWidget(closeButton, 1, 4);
        findLayout->setContentsMargins(11, 2, 11, 0);

        //���ù̶���С
        setFixedSize(480, 80);
    }
    else {
        setWidget(replaceWidget);//��������Ϊ�滻
        setWindowTitle(tr("�滻"));

        findLineEdit->setFixedSize(195, 22);
        replaceLineEdit->setFixedSize(195, 22);

        replaceLayout->addWidget(findLabel, 0, 0);
        replaceLayout->addWidget(findLineEdit, 0, 1, 1, 2);
        replaceLayout->addWidget(previousButton, 0, 3);
        replaceLayout->addWidget(nextButton, 0, 4);
        replaceLayout->addWidget(replaceLabel, 1, 0);
        replaceLayout->addWidget(replaceLineEdit, 1, 1, 1, 2);
        replaceLayout->addWidget(replaceButton, 1, 3);
        replaceLayout->addWidget(replaceAllButton, 1, 4);
        replaceLayout->addWidget(caseSensitive, 2, 1);
        replaceLayout->addWidget(consistentMatch, 2, 2);
        replaceLayout->addWidget(highLightResult, 2, 3);
        replaceLayout->addWidget(closeButton, 2, 4);
        replaceLayout->setContentsMargins(11, 2, 11, 0);
        //���ù̶���С
        setFixedSize(480, 105);
    }
}

void FindReplaceArea::dockedLayout()
{
    setWindowTitle(tr(""));//����ʱ���ñ���
    
    if (currentMode == FindMode) {
        setWidget(findWidget);//��������Ϊ����
        findLineEdit->setFixedSize(150, 22);

        findLayout->addWidget(findLabel, 0, 0);
        findLayout->addWidget(findLineEdit, 0, 1);
        findLayout->addWidget(previousButton, 0, 2);
        findLayout->addWidget(nextButton, 0, 3);
        findLayout->addWidget(caseSensitive, 0, 5);
        findLayout->addWidget(consistentMatch, 0, 4);
        findLayout->addWidget(highLightResult, 1, 4);
        findLayout->setContentsMargins(7, 2, 11, 7);
        findLayout->setRowMinimumHeight(1, 23);
        findLayout->addWidget(closeButton, 1, 5);
        //���ù̶���С
        setFixedSize(650, 65);
    }
    else {
        setWidget(replaceWidget);//��������Ϊ�滻
        findLineEdit->setFixedSize(150, 22);
        replaceLineEdit->setFixedSize(150, 22);

        replaceLayout->addWidget(findLabel, 0, 0);
        replaceLayout->addWidget(findLineEdit, 0, 1);
        replaceLayout->addWidget(previousButton, 0, 2);
        replaceLayout->addWidget(nextButton, 0, 3);
        replaceLayout->addWidget(replaceLabel, 1, 0);
        replaceLayout->addWidget(replaceLineEdit, 1, 1, 1, 2);
        replaceLayout->addWidget(replaceButton, 1, 2);
        replaceLayout->addWidget(replaceAllButton, 1, 3);
        replaceLayout->addWidget(caseSensitive, 0, 5);
        replaceLayout->addWidget(consistentMatch, 0, 4);
        replaceLayout->addWidget(highLightResult, 1, 4);
        replaceLayout->setContentsMargins(7, 2, 11, 7);
        replaceLayout->addWidget(closeButton, 1, 5);
        //���ù̶���С
        setFixedSize(650, 65);
    }
}
    
void FindReplaceArea::generalSetting()
{
    //���� Dock ���ƶ�����Ϊ����
    setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);
    //������ �ɹ� ���� �ɸ��� �������
    setFeatures(QDockWidget::DockWidgetClosable | 
                QDockWidget::DockWidgetMovable |
                QDockWidget::DockWidgetFloatable |
                QDockWidget::DockWidgetVerticalTitleBar
                );
    //Dock[ Widget[ Layout[ ... ] ] ] 
    //��������ؼ�
    //����label�Ļ��(Buddy),���ã�
    //������label��ݼ�ʱ��findLineEdit����ȡ������
    findLabel->setBuddy(findLineEdit);
    replaceLabel->setBuddy(replaceLineEdit);
    setWindowTitle(tr("���Һ��滻"));//����ʱ���ñ���
    //���⸶����ֵ
    currentMode = FindMode;
    QMainWindow *main = qobject_cast<QMainWindow *>(parent());
    main->addDockWidget(Qt::BottomDockWidgetArea, this);
    hide();

    connect(findAction, SIGNAL(toggled(bool)), 
            this, SLOT(openFindArea(bool)));
    connect(replaceAction, SIGNAL(toggled(bool)), 
            this, SLOT(openReplaceArea(bool)));

    connect(this, SIGNAL(topLevelChanged(bool)), 
            this, SLOT(transLayout(bool)));
    connect(closeButton, SIGNAL(clicked()),
            this, SLOT(close()));

    //ʵʱ����
    connect(findLineEdit, SIGNAL(textChanged(QString)),
            this, SLOT(runtimeSearchToggled(QString)));
    //�����һ������һ��ʱ���õĺ���
    connect(nextButton, SIGNAL(clicked()),
            this, SLOT(searchNext()));
    connect(previousButton, SIGNAL(clicked()),
            this, SLOT(searchPrevious()));
    //��ѡ���ִ�Сд��ȫ��ƥ��
    connect(caseSensitive, SIGNAL(stateChanged(int)),
            this, SLOT(checkButtonToggled(int)));
    connect(consistentMatch, SIGNAL(stateChanged(int)),
            this, SLOT(checkButtonToggled(int)));
    //ȫ���滻
    connect(replaceAllButton, SIGNAL(clicked()),
            this, SLOT(replaceAll()));
    //�滻
    connect(replaceButton, SIGNAL(clicked()),
            this, SLOT(replace()));
    //����
    connect(highLightResult, SIGNAL(stateChanged(int)),
            this, SLOT(highlightResultChecked(int)));
    //user change text
    connect(codeEditor, SIGNAL(textChanged()),
            this, SLOT(userChangedText()));
    connect(findLineEdit,SIGNAL(selectionChanged()),this,SLOT(setLineEdit()));

connect(replaceLineEdit,SIGNAL(selectionChanged()),this,SLOT(setLineEdit()));}

/* �����������У���ʱ����� cursor.isNull ��ʱ����� cursor.atEnd
 * isNull Ϊ�������ǣ����λ�õ��ĵ�ĩβ��������Ҫ�ҵ��ַ�����֮ǰ�Ƿ��ҵ����ؼ����޹ء�
 * atEnd ���ǹ��λ���ĵ�ĩβ
 */
/* always search from the start */
void FindReplaceArea::runtimeSearch(QString text)
{
    QString searchString = text;
    if ( searchString == "" )
    {
        codeEditor->setTextCursor(QTextCursor(codeEditor->document()));
        return;
    }

    QTextDocument::FindFlags findFlag(0);  // init to 0, this is important

    if ( consistentMatch->isChecked() && caseSensitive->isChecked() )
        findFlag = QTextDocument::FindCaseSensitively | QTextDocument::FindWholeWords;
    else if ( consistentMatch->isChecked() && !caseSensitive->isChecked() )
        findFlag = QTextDocument::FindWholeWords;
    else if ( ! consistentMatch->isChecked() && caseSensitive->isChecked() )
        findFlag = QTextDocument::FindCaseSensitively;


    QTextDocument *document = codeEditor->document();

    //�����ʼ�� cursor����ʼ����λ�ö����ĵ�ǰ��
    QTextCursor highlightCursor(document);
    // �ƶ����ȥ��
    highlightCursor = document->find(searchString, highlightCursor, findFlag);

    if (!highlightCursor.isNull() )
    {
        codeEditor->setTextCursor(highlightCursor);
    }
    else if ( highlightCursor.isNull() )
    {
        codeEditor->setTextCursor(QTextCursor(codeEditor->document()));
    }

    highlightCursor.clearSelection();
}

/* �ı����ֵ�ʱ�������������ѡ�˸������ٸ���һ�� */
void FindReplaceArea::runtimeSearchToggled(QString text)
{
    runtimeSearch(text);
    if ( highLightResult->isChecked() )
        clearAndHighlightAll(text);


}

//������һ����Ӧ�ĺ���
void FindReplaceArea::searchNext()
{
    QString searchString = findLineEdit->text();
    if ( searchString == "" )
        return;

    QTextDocument::FindFlags findFlag(0);  // init to 0, this is important

    if ( consistentMatch->isChecked() && caseSensitive->isChecked() )
        findFlag = QTextDocument::FindCaseSensitively | QTextDocument::FindWholeWords;
    else if ( consistentMatch->isChecked() && !caseSensitive->isChecked() )
        findFlag = QTextDocument::FindWholeWords;
    else if ( ! consistentMatch->isChecked() && caseSensitive->isChecked() )
        findFlag = QTextDocument::FindCaseSensitively;

    QTextDocument *document = codeEditor->document();

    //�����ʼ������ cursor����ʼ����λ�ö����ĵ�ǰ��
    QTextCursor highlightCursor(codeEditor->textCursor());

    // �ƶ����ȥ��
    highlightCursor = document->find(searchString, highlightCursor, findFlag);

    if (!highlightCursor.isNull() )
    {
        codeEditor->setTextCursor(highlightCursor);
    }
    else if ( highlightCursor.isNull() ) //���û���ҵ������ĵ���ʼλ�ÿ�ʼ����һ��
    {
        // find one more time
        highlightCursor = document->find(searchString, QTextCursor(document), findFlag);
        if (!highlightCursor.isNull() )
        {
            codeEditor->setTextCursor(highlightCursor);
        }
    }
    highlightCursor.clearSelection();
    highlightResultChecked(Qt::Checked);
}

//������һ����Ӧ�ĺ���
void FindReplaceArea::searchPrevious()
{

    QString searchString = findLineEdit->text();
    if ( searchString == "" )
        return;

    QTextDocument::FindFlags findFlag(QTextDocument::FindBackward);  // init to 0, this is important

    if ( consistentMatch->isChecked() && caseSensitive->isChecked() )
        findFlag = QTextDocument::FindCaseSensitively | QTextDocument::FindWholeWords | QTextDocument::FindBackward;
    else if ( consistentMatch->isChecked() && !caseSensitive->isChecked() )
        findFlag = QTextDocument::FindWholeWords | QTextDocument::FindBackward;
    else if ( ! consistentMatch->isChecked() && caseSensitive->isChecked() )
        findFlag = QTextDocument::FindCaseSensitively | QTextDocument::FindBackward;

    QTextDocument *document = codeEditor->document();
    QTextCursor highlightCursor(codeEditor->textCursor());

    highlightCursor = document->find(searchString, highlightCursor, findFlag);
    if ( !highlightCursor.isNull() ) //����ҵ���
    {
        codeEditor->setTextCursor(highlightCursor);
    }
    else if ( highlightCursor.isNull() )//���û���ҵ����ٴ��ĵ�ĩβ������һ��
    {

        QTextCursor end(document->lastBlock());
        end.setPosition(end.position()+document->lastBlock().text().length());

        // find one more time
        highlightCursor = document->find(searchString, end, findFlag);

        if (!highlightCursor.isNull() )
        {
            codeEditor->setTextCursor(highlightCursor);
        }
    }
    highlightCursor.clearSelection();
    highlightResultChecked(Qt::Checked);
}


//����ѡ����ȫ���İ�ťʱ�򣬵����������
void FindReplaceArea::highlightResultChecked(int state)
{
    if ( state == Qt::Checked )
    {
        clearAndHighlightAll( findLineEdit->text() );
    }
    else
    {
        clearAll();
    }
}

/*�ڲ��Ҹ���֮ǰ����Ҫ�����ǰ�ı���
 * text ����һ�β��ҵĴ�*/
void FindReplaceArea::clearAll()
{
    QList<QTextEdit::ExtraSelection> extraSelection;
    CpadPalette cpadPalette;
    QColor lineColor = cpadPalette.defaultGroup[6];

    if (!codeEditor->isReadOnly()) {
        QTextEdit::ExtraSelection selection;
        selection.format.setBackground(lineColor);
        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
        selection.cursor = codeEditor->textCursor();
        selection.cursor.clearSelection();
        extraSelection.append(selection);
    }

    codeEditor->setExtraSelections(extraSelection);
}

void FindReplaceArea::clearAndHighlightAll(QString text)
{
    QTextDocument *document = codeEditor->document();
    QTextCursor highlightCursor(document);
    QTextCursor cursor(document);
    CpadPalette cpadPalette;
    ////////////////////////
    clearAll();
    QList<QTextEdit::ExtraSelection> selections = codeEditor->extraSelections();

    QTextEdit::ExtraSelection selection;
    QTextCharFormat format = selection.format;
    format.setBackground(cpadPalette.highlightForSearch);
    selection.format = format;

    if ( consistentMatch->isChecked() && caseSensitive->isChecked() )
        findFlag = QTextDocument::FindCaseSensitively | QTextDocument::FindWholeWords;
    else if ( consistentMatch->isChecked() && !caseSensitive->isChecked() )
        findFlag = QTextDocument::FindWholeWords;
    else if ( ! consistentMatch->isChecked() && caseSensitive->isChecked() )
        findFlag = QTextDocument::FindCaseSensitively;
    else
        findFlag = 0;

    cursor.beginEditBlock();
    while ( !highlightCursor.isNull() && !highlightCursor.atEnd() )
    {
        highlightCursor = document->find(text, highlightCursor,findFlag);
        if (!highlightCursor.isNull())
        {
            QTextCursor cursor = highlightCursor;
            cursor.setPosition(highlightCursor.position()-text.length(),QTextCursor::MoveAnchor);
            cursor.setPosition(highlightCursor.position(), QTextCursor::KeepAnchor);
            selection.cursor = cursor;
            selections.append(selection);
        }
    }
    cursor.endEditBlock();
    codeEditor->setExtraSelections(selections);

}

//�����ִ�Сд��ȫ��ƥ�乴ѡ��ȡ����ѡ��ʱ�򣬵���������������
void FindReplaceArea::checkButtonToggled(int state)
{
    QString text = findLineEdit->text();
    if ( highLightResult->isChecked() == true )
        clearAndHighlightAll(text);
    runtimeSearch(text);
}

//�滻ȫ��
void FindReplaceArea::replaceAll()
{
    QString searchString = findLineEdit->text();
    if ( searchString == "" )
        return;
    QString replaceWith = replaceLineEdit->text();

    if ( consistentMatch->isChecked() && caseSensitive->isChecked() )
        findFlag = QTextDocument::FindCaseSensitively | QTextDocument::FindWholeWords;
    else if ( consistentMatch->isChecked() && !caseSensitive->isChecked() )
        findFlag = QTextDocument::FindWholeWords;
    else if ( ! consistentMatch->isChecked() && caseSensitive->isChecked() )
        findFlag = QTextDocument::FindCaseSensitively;

    QTextDocument *document = codeEditor->document();

    //�����ʼ������ cursor����ʼ����λ�ö����ĵ�ǰ��
    QTextCursor highlightCursor(document);
    QTextCursor cursor(document);

    cursor.beginEditBlock();

    // �ƶ����ȥ��
    while ( !highlightCursor.isNull() && !highlightCursor.atEnd() )
    {
        highlightCursor = document->find(searchString, highlightCursor, findFlag);
        if (!highlightCursor.isNull())
        {
            highlightCursor.removeSelectedText();
            highlightCursor.insertText(replaceWith);
        }
    }
    cursor.endEditBlock();
}

void FindReplaceArea::replace()
{
    QString replaceWith = replaceLineEdit->text();
    QTextCursor cursor = codeEditor->textCursor();

    if ( cursor.hasSelection() )
    {
        cursor.removeSelectedText();
        cursor.insertText(replaceWith);
    }
    //�滻֮���ٲ���һ��
    searchNext();
}

/*
 * �û������ı�ʱ������������
 * ���������û�����ʱ���ж������λ���Ƿ��в��ҵĸ������ڣ�����Ѹ���ȡ����
 */
void FindReplaceArea::userChangedText()
{
    QTextCursor cursor = codeEditor->textCursor();
    int listPosition = inExtraSelection(cursor.position());

    if ( listPosition == -1 )
        return;
    else
    {
        QList <QTextEdit::ExtraSelection> extraSelection = codeEditor->extraSelections();
        extraSelection.removeAt(listPosition);
        codeEditor->setExtraSelections(extraSelection);
    }

}

/*
 * ���Ҹ�������Ƿ������е� extraSelection �С� 
 */
int FindReplaceArea::inExtraSelection(int cursorPosition)
{
    QList <QTextEdit::ExtraSelection> extraSelection = codeEditor->extraSelections();
    int listLength = extraSelection.length();
    if ( listLength == 1 )  // �������ֻ���˵�ǰ���и���
        return -1;

    int searchLength = findLineEdit->text().length();

    for ( int i = 1; i < listLength; i++ )
    {
        int end = extraSelection[i].cursor.position();
        int start = end - searchLength;
        if ( cursorPosition < end && cursorPosition > start )
            return i;
    }

    return -1;
}

void FindReplaceArea::setLineEdit()
{
    QLineEdit *line=(QLineEdit *)sender();
    lineEditkeyboard->setLineEdit(line);
    lineEditkeyboard->show();
//    setFocus();
//    findLineEdit->clear();
//    findLineEdit->insert(lineedit->displayText());
//    qDebug()<<lineedit->displayText();
}
