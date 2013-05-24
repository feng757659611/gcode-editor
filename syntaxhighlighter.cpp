///*
//    This file is part of cPad Project.

//    cPad is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    cPad is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with cPad.  If not, see <http://www.gnu.org/licenses/>.
//*/
//#include "syntaxhighlighter.h"
//#include "cpadpalette.h"
//#include "memorycenter.h"
//#include <QDebug>

//SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent):
//    QSyntaxHighlighter(parent)
//{

//    dataTypeList << "auto" << "double" << "const" << "in" << "long" << "enum" << "float" << "char"
//        << "register" << "short" << "signed" << "static" << "union" << "extern"
//        << "unsigned" << "void" << "volatile" << "struct";

//    otherKeywordList << "break" << "case" << "continue" << "default"
//        << "do" << "else" << "for" << "goto" << "if" << "return"
//        << "sizeof" << "struct" << "switch" << "typedef" << "while"
//        << "#include" << "#define" << "#ifndef" << "#ifdef" << "#endif";

//    setSyntaxFormat();

//}

//void SyntaxHighlighter::setSyntaxFormat()
//{
////[0 comment, constant, datatype, 3 othertype, macro, 5 transfer; background, numberarea; 8 alert]
//    CpadPalette cpadPalette;

//    commentFormat.setForeground(cpadPalette.defaultGroup[0]);
//    //commentFormat.setFontWeight(QFont::Bold);
//    constFormat.setForeground(cpadPalette.defaultGroup[1]);
//    //constFormat.setFontWeight(QFont::Bold);
//    dataTypeFormat.setForeground(cpadPalette.defaultGroup[2]);
//    dataTypeFormat.setFontWeight(QFont::Bold);

//    otherFormat.setForeground(cpadPalette.defaultGroup[3]);
//    otherFormat.setFontWeight(QFont::Bold);
//    macroFormat.setForeground(cpadPalette.defaultGroup[4]);
//    //macroFormat.setFontWeight(QFont::Bold);
//    transferFormat.setForeground(cpadPalette.defaultGroup[5]);
//    //transferFormat.setFontWeight(QFont::Bold);
//    alertFormat.setForeground(cpadPalette.defaultGroup[8]);
//    alertFormat.setFontWeight(QFont::Bold);
//}

//void SyntaxHighlighter::changeColorGroup(QList<QColor> group)
//{
//    commentFormat.setForeground(group[0]);
//    //commentFormat.setFontWeight(QFont::Bold);
//    constFormat.setForeground(group[1]);
//    //constFormat.setFontWeight(QFont::Bold);
//    dataTypeFormat.setForeground(group[2]);
//    dataTypeFormat.setFontWeight(QFont::Bold);
//    otherFormat.setForeground(group[3]);
//    otherFormat.setFontWeight(QFont::Bold);
//    macroFormat.setForeground(group[4]);
//    //macroFormat.setFontWeight(QFont::Bold);
//    transferFormat.setForeground(group[5]);
//    //transferFormat.setFontWeight(QFont::Bold);
//    alertFormat.setForeground(group[8]);
//    alertFormat.setFontWeight(QFont::Bold);

//    rehighlight();
//}

//void SyntaxHighlighter::turnOnSyntaxHighlight(bool turn)
//{
//    turnOn = turn;
//    rehighlight();
//}

//QTextCharFormat SyntaxHighlighter::categoryFormat(int category)
//{
//    //[0 comment, constant, datatype, 3 othertype, macro, 5 transfer;

//    QTextCharFormat plain;

//    if ( (category >= 50 && category <= 53) || category == 10 ) //4 macro
//        return macroFormat;
//    else if ( category >= 54 && category <= 70 ) //3 othertype
//        return otherFormat;
//    else if ( category >= 71 && category <= 89 ) //2 datatype
//        return dataTypeFormat;
//    else if ( category >= 90 && category <= 91 ) // 0 comment
//        return commentFormat;
//    else if ( category == 1 || category == 8 || category == 9 ) //1 constant
//        return constFormat;

//    return plain;
//}

//void SyntaxHighlighter::getPositionInfo(const QString &text)
//{
///*
//    highlightDataType(text);
//    highlightOtherkeyword(text);
//    highlightSingleQuote(text);
//    highlightQuote(text);
//    //��ʾת�����
//    highlightTransfer(text);

//    highlightComments(text);*/

//    ////////////
//    MemoryCenter memoryCenter;
//    QString lineText = text;
//    memoryCenter.analysisMain(lineText);

//    struct LineHeadPointer * head;

//    head = memoryCenter.getLineHead();
//    head = head->nextLine;
//    while ( head != NULL )
//    {
//        struct LexicalAnalysis *word = head->firstWord;
//        while ( word != NULL )
//        {
//            QTextCharFormat format = categoryFormat(word->wordCategory);
//            pushFormat(word->wordPosition, word->wordLength, format);
//            word = word->nextWord;
//        }
//        head = head->nextLine;
//    }
//    //��ʾת�����

//    highlightTransfer(text);
//    highlightComments(text);
//    highlightParentheses(text);
//    return;
//}

///*
// * highlightBlock �������ı����ݸı��ʱ���Զ����á�
// * text �ǹ�굱ǰ�е��������ݣ��������������ʵ�ָ�����
// * �������������͡��ؼ��ʡ�ע�� ������ɫ
// */
//void SyntaxHighlighter::highlightBlock(const QString &text)
//{
//    if ( turnOn == false )
//    {
//        return;
//    }
//    getPositionInfo(text);
//    //  ��ʼ����
//    foreach (const PositionInfo &position, formatPosition){
//        setFormat(position.start, position.count, position.format);
//    }
//    //��Ϊ�û����ܰ��Ѿ��������Ĵ�ɾ���������������֮��Ѽ�¼�Ÿ���λ�õ� QList ��գ�Ϊ�´���׼��
//    formatPosition.clear();
//}

//void SyntaxHighlighter::pushFormat(int start, int count, QTextCharFormat format)
//{
//    PositionInfo positionInfo;

//    positionInfo.start = start;
//    positionInfo.count = count;
//    positionInfo.format = format;
//    formatPosition.append(positionInfo);
//}

///*
// * �õ�������Ϣ������Ϣ�浽 formatPosition ��
// * �������������е�����
// */
//void SyntaxHighlighter::highlightDataType(const QString &text)
//{
//    int start = -1;
//    int pos = start;  //��ǰ����λ��

//    for (int i = 0; i < dataTypeList.size(); i++)
//    {
//        while(true)
//        {
//            pos = text.indexOf(dataTypeList[i], start + 1);
//            if ( pos != -1 )
//            {   //�ҵ��Ӵ�
//                int keywordLength = dataTypeList[i].length();
//                if ( text.length() < keywordLength )
//                    break;

//                // bug ����������ı�Ϊ int������Ϊ3�ҽ�Ϊ3��
//                //�����ͼ����text[pos+dataTypeList[i].length()]ȥ��int�����޵��ʻ���ĸ��
//                //�൱�ڵ����� text[3]����Ч�ڴ������ˡ�
//                if ( pos+keywordLength == text.length() )
//                {  //Ҳ����Ҫ�����Ĺؼ��ֳ����������˸�ĵط���
//                    if ( pos != 0 && text[pos-1].isLetterOrNumber() )
//                        break;
//                    else
//                    {
//                        pushFormat(pos, keywordLength, dataTypeFormat);
//                        break;
//                    }
//                }
//                //������Ѿ������ܳ��� pos + keywordLength Խ��������
//                if ( pos == 0 && text[pos + keywordLength].isLetterOrNumber())
//                {  //����Ӵ����ǹؼ��� ���� ints, int1
//                    start = pos;
//                    continue;
//                }
//                if ( pos != 0 &&  // ����Ӵ����ǹؼ��� ���� sint, 12int, int5
//                        (text[pos-1].isLetterOrNumber() ||
//                         text[pos+keywordLength].isLetterOrNumber()))
//                {
//                    start = pos;
//                    continue;
//                }
//                // ������˵���ǹؼ���
//                start = pos;
//                pushFormat(pos, keywordLength, dataTypeFormat);
//            } // end: if ( pos != -1 )
//            else
//            {  //û���ҵ��Ӵ�
//                start = -1; //Ϊ֮���������ؼ�����׼��
//                break;
//            }
//        }  // end while(true)
//    }
//}

//void SyntaxHighlighter::highlightOtherkeyword(const QString &text)
//{
//    int start = -1;
//    int pos = start;  //��ǰ����λ��

//    for (int i = 0; i < otherKeywordList.size(); i++)
//    {
//        while(true)
//        {
//            pos = text.indexOf(otherKeywordList[i], start + 1);
//            if ( pos != -1 )
//            {   //�ҵ��Ӵ�
//                int keywordLength = otherKeywordList[i].length();
//                if ( text.length() < keywordLength )
//                    break;

//                // bug ����������ı�Ϊ int������Ϊ3�ҽ�Ϊ3...�����溯�������һ��
//                if ( pos+keywordLength == text.length() )
//                {  //Ҳ����Ҫ�����Ĺؼ��ֳ����������˸�ĵط���
//                    if ( pos+keywordLength == text.length() )
//                    {  //Ҳ����Ҫ�����Ĺؼ��ֳ����������˸�ĵط���
//                        if ( pos != 0 && text[pos-1].isLetterOrNumber() )
//                            break;
//                        else
//                        {
//                            pushFormat(pos, keywordLength, otherFormat);
//                            break;
//                        }
//                    }
//                }
//                //������Ѿ������ܳ��� pos + keywordLength Խ��������
//                if ( pos == 0 && text[pos + keywordLength].isLetterOrNumber())
//                {  //����Ӵ����ǹؼ��� ���� ints, int1
//                    start = pos;
//                    continue;
//                }
//                if ( pos != 0 &&  // ����Ӵ����ǹؼ��� ���� sint, 12int, int5
//                        (text[pos-1].isLetterOrNumber() ||
//                         text[pos+keywordLength].isLetterOrNumber()))
//                {
//                    start = pos;
//                    continue;
//                }
//                // ������˵���ǹؼ���
//                start = pos;
//                pushFormat(pos, keywordLength, otherFormat);
//            } // end: if ( pos != -1 )
//            else
//            {  //û���ҵ��Ӵ�
//                start = -1; //Ϊ֮���������ؼ�����׼��
//                break;
//            }
//        }  // end while(true)
//    }
//}

//void SyntaxHighlighter::highlightComments(const QString &text)
//{
//    if ( previousBlockState() == commentNotFinish )
//        setCurrentBlockState(commentNotFinish);
//    else
//        setCurrentBlockState(commentFinished);

//    int textLength = text.length();

//    for ( int i = 0; i < textLength; i++ )
//    {
//        if ( currentBlockState() == commentNotFinish )
//        { //����ע������������
//            int tmp = text.indexOf("*/");
//            if ( tmp == -1 )
//            {
//                setCurrentBlockState(commentNotFinish);
//                pushFormat(0, textLength, commentFormat);
//                break;
//            }
//            else  // �ҵ���ձ�־
//            {
//                setCurrentBlockState(commentFinished);
//                pushFormat(0, tmp + 2, commentFormat );
//                i = tmp + 1;
//                continue;
//            }
//        }

//        if ( text.mid(i, 2) == "//" )
//        {
//            pushFormat(i, textLength - i, commentFormat );
//            break;
//        }

//        if ( text.mid(i, 2) == "/*" )
//        {
//            int endIndex = text.indexOf("*/", i);
//            if ( endIndex == -1 ) //û���ҵ�������־
//            {
//                setCurrentBlockState(commentNotFinish);
//                pushFormat(i, textLength - i, commentFormat );
//                break;
//            }
//            else
//            { //�ҵ�������־
//                setCurrentBlockState(commentFinished);
//                pushFormat(i, endIndex - i + 2, commentFormat);
//                i = endIndex+1;
//                continue;
//            }
//        }

//        if ( text.at(i) == '\"' )
//        {
//            int position = i;
//            while (true)
//            {
//                position = text.indexOf("\"", position + 1);
//                if ( position == -1)  //û���ҵ�˫����
//                    break;
//                else  //�ҵ�˫����
//                {
//                    if ( text.at(position-1) == '\\' ) //ע������ position-1 һ���Ϸ�
//                    {  //���ð��ǰ�������ת�Ʒ���
//                        position++;
//                        continue;
//                    }
//                    else
//                        break;
//                }
//            }
//            if ( position == -1 )
//                break;
//            else
//                i = position;
//        }

//        if ( text.mid(i, 2) == "*/" )
//        {
//            if ( currentBlockState() == commentFinished )
//            {
//                pushFormat(i,2,alertFormat);
//                i++;
//            }
//        }
//    }
//}

//void SyntaxHighlighter::printList(QList<PositionInfo> &formatPosition)
//{
//    qDebug() << "printList:";
//    for (int i = 0; i < formatPosition.size(); i++){
//        PositionInfo test;
//        test = formatPosition[i];
//        qDebug() << "(" << test.start <<", " << test.count <<", "<<test.format<<")";
//    }
//    qDebug() << "printList end";
//}
//void SyntaxHighlighter::highlightQuote(const QString &text)
//{
//    int startIndex = 0;
//    int endIndex = 0;

//    startIndex = text.indexOf("\"");
//    endIndex = startIndex;

//    while (startIndex >= 0){
//        endIndex = text.indexOf("\"", startIndex + 1);

//        if ( endIndex != -1 && endIndex != 0 && text[endIndex - 1] == '\\' )
//        {   //����ҵ�������ǰ����ת���ַ�
//            pushFormat(startIndex, endIndex-startIndex+1, constFormat);
//            startIndex = endIndex;
//            continue;
//        }

//        int quoteLength;

//        if ( endIndex == -1 ) //û���ҵ�
//            quoteLength = text.length() - startIndex;
//        else
//            quoteLength = endIndex - startIndex + 1;
//        pushFormat(startIndex, quoteLength, constFormat);
//        startIndex = text.indexOf("\"", startIndex + quoteLength); //��������
//    }
//}


//void SyntaxHighlighter::highlightSingleQuote(const QString &text)
//{
//    int startIndex = text.indexOf("\'");
//    int highlightLength = 0;

//    while ( startIndex >= 0 )
//    {
//        int transferIndex = text.indexOf("\\", startIndex);
//        if ( transferIndex - startIndex == 1 ) //�����ź��������ת���
//        {
//            if ( text.length() - startIndex >= 4 )
//                highlightLength = 4;
//            else
//                highlightLength = text.length() - startIndex;
//        }
//        else
//        {
//            if ( text.length() - startIndex >= 3 )
//                highlightLength = 3;
//            else
//                highlightLength = text.length() - startIndex;
//        }

//        pushFormat(startIndex, highlightLength, constFormat);
//        startIndex = text.indexOf("\'", startIndex + highlightLength );
//    }

//}
//void SyntaxHighlighter::highlightTransfer(const QString &text)
//{
//    int startIndex = text.indexOf("\\");
//    PositionInfo positionInfo;

//    while( startIndex >= 0 )
//    {
//        positionInfo.start = startIndex;
//        positionInfo.count = 2;
//        positionInfo.format = alertFormat;
//        formatPosition.append(positionInfo);
//        int next = startIndex+1;
//        if ( next < text.length() && text[next] == '\\')
//            next++;
//        startIndex = text.indexOf("\\", next);
//    }
//}

//// �������ֻ����ע�ͷ��Ż᲻��������֮��
//bool SyntaxHighlighter::inQuote(const QString &text, int pos)
//{


//    if ( pos >= text.size() || pos < 0)
//        return false;

//    // quotePosition ��� [4, 8, 18, 40] ������
//    QList<int> quotePosition;
//    int quote = text.indexOf("\"");
//    if ( quote == -1 ) //û������
//        return false;
//    while ( quote >= 0 )
//    {
//        quotePosition << quote;
//        quote = text.indexOf("\"", quote+1);
//    }

//    int i = 0;
//    while ( true )
//    {
//        if ( i >= quotePosition.size() )
//            break;
//        if ( quotePosition.at(i) < pos )
//        {
//            i++;
//            continue;
//        }
//        else
//            break;
//    }
//    // ������ pos = 15, quotePosition = [ 4, 8, 13 ]
//    // 1. ��� i >= quotePosition.size()
//    // 1.1 quotePosition.size() ��������˵������������
//    // 1.2 quotePosition.size() ��ż����˵��������������
//    // 2. ��� i ��ż����˵��������������
//    // 3. ��� i ��������˵������������

//    if ( i>= quotePosition.size() )
//    {
//        if ( quotePosition.size() % 2 == 0 )
//            return false;
//        else
//            return true;
//    }

//    if ( i % 2 == 0 )
//        return false;
//    else
//        return true;


//}

///* ����ƥ����� */
//void SyntaxHighlighter::highlightParentheses(const QString &text)
//{
//    TextBlockData *data = new TextBlockData;

//    //int leftPos = text.indexOf('(');
//    int leftPos = findNextAvailableChar(text, '(');
//    while (leftPos != -1) {
//        ParenthesisInfo *info = new ParenthesisInfo;
//        info->character = '(';
//        info->position = leftPos;

//        data->insert(info);
//        //leftPos = text.indexOf('(', leftPos + 1);
//        leftPos = findNextAvailableChar(text, '(', leftPos + 1);
//    }

//    //int rightPos = text.indexOf(')');
//    int rightPos = findNextAvailableChar(text, ')');
//    while (rightPos != -1) {
//        ParenthesisInfo *info = new ParenthesisInfo;
//        info->character = ')';
//        info->position = rightPos;
//        data->insert(info);

//        //rightPos = text.indexOf(')', rightPos +1);
//        rightPos = findNextAvailableChar(text, ')', rightPos + 1);
//    }
//    /////////
//    //leftPos = text.indexOf('[');
//    leftPos = findNextAvailableChar(text, '[');
//    while (leftPos != -1) {
//        ParenthesisInfo *info = new ParenthesisInfo;
//        info->character = '[';
//        info->position = leftPos;

//        data->insert(info);
//        //leftPos = text.indexOf('[', leftPos + 1);
//        leftPos = findNextAvailableChar(text, '[', leftPos + 1);
//    }

//    //rightPos = text.indexOf(']');
//    rightPos = findNextAvailableChar(text, ']');
//    while (rightPos != -1) {
//        ParenthesisInfo *info = new ParenthesisInfo;
//        info->character = ']';
//        info->position = rightPos;
//        data->insert(info);

//        //rightPos = text.indexOf(']', rightPos +1);
//        rightPos = findNextAvailableChar(text, ']', rightPos + 1);
//    }
//    ////////////
//    //leftPos = text.indexOf('{');
//    leftPos = findNextAvailableChar(text, '{');
//    while (leftPos != -1) {
//        ParenthesisInfo *info = new ParenthesisInfo;
//        info->character = '{';
//        info->position = leftPos;

//        data->insert(info);
//        //leftPos = text.indexOf('{', leftPos + 1);
//        leftPos = findNextAvailableChar(text, '{', leftPos + 1);
//    }

//    //rightPos = text.indexOf('}');
//    rightPos = findNextAvailableChar(text, '}');
//    while (rightPos != -1) {
//        ParenthesisInfo *info = new ParenthesisInfo;
//        info->character = '}';
//        info->position = rightPos;
//        data->insert(info);

//        //rightPos = text.indexOf('}', rightPos +1);
//        rightPos = findNextAvailableChar(text, '}', rightPos + 1);
//    }

//    /*for ( int i = 0; i < data->parentheses().size(); i++)
//    {
//        qDebug() << i <<"  < " << data->parentheses()[i]->character << "  " << data->parentheses()[i]->position << ">";
//    }
//    qDebug() << "=============";*/
//    setCurrentBlockUserData(data);
//}

///* ����һ��������������� ch��������λ�ã�δ�ҵ����� -1*/
//int SyntaxHighlighter::findNextAvailableChar(const QString &text, char ch, int pos)
//{
//    int length = text.length();
//    if ( pos >= length )
//        return -1;

//    bool comment1Flag = false; // ���ڼ�⵱ǰ�Ƿ����ڵ���������
//    bool comment2Flag = false; // ���ڼ�⵱ǰ�Ƿ�����˫��������
//    int i = pos;
//    while ( i < length )
//    {
//        if ( text[i] == '\'' && comment2Flag == false) //�����Ų���˫������
//        {
//            if ( i == 0 || (i != 0 && text[i] != '\\'))
//            {
//                if ( comment1Flag == false)
//                    comment1Flag = true;
//                else
//                    comment1Flag = false;
//                i++;
//                continue;
//            }
//        }

//        if ( text[i] == '"' && comment1Flag == false) //˫���Ų��ڵ�������
//        {
//            if ( i == 0 || (i != 0 && text[i] != '\\'))
//            {
//                if ( comment2Flag == false)
//                    comment2Flag = true;
//                else
//                    comment2Flag = false;
//                i++;
//                continue;
//            }
//        }

//        if ( comment1Flag == true || comment2Flag == true )
//        {//����������������棬�������ж���
//            i++;
//            continue;
//        }
//        else //����˫��������
//        {
//            if ( text[i] == ch )
//            {
//                break;
//            }
//            else
//            {
//                i++;
//            }
//        }
//    }
//    if ( i == length)
//    {
//        return -1;
//    }
//    else
//    {
//        return i;
//    }
//}
/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>

#include "syntaxhighlighter.h"
#include <QPlainTextEdit>
//! [0]
Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
    keywordFormat.setForeground(Qt::blue);
   // keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "G" << "X" << "Y"
                    << "Z" << "U" << "V"
                    << "W" << "A" << "B"
                    << "C" << "F" << "S"
                    <<"I"<<"J"<<"K"<<"R"
                   <<"M"<<"P"<<"O";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    keywordFormat.setForeground(Qt::green);
    //keywordFormat.setFontWeight(QFont::Bold);
   // foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegExp("[0123456789.-#]");
        rule.format = keywordFormat;
        highlightingRules.append(rule);
   // }
//! [1]
    //! [2]
        classFormat.setFontWeight(QFont::Bold);
        classFormat.setForeground(Qt::darkMagenta);
        rule.pattern = QRegExp("\\bQ[A-Za-z]+\\b");
        rule.format = classFormat;
        highlightingRules.append(rule);
    //! [2]

    //! [3]
        singleLineCommentFormat.setForeground(Qt::gray);
        rule.pattern = QRegExp(";[^\n]*");
        rule.format = singleLineCommentFormat;
        highlightingRules.append(rule);

        multiLineCommentFormat.setForeground(Qt::red);
    //! [3]

    //! [4]
        quotationFormat.setForeground(Qt::darkGreen);
        rule.pattern = QRegExp("\".*\"");
        rule.format = quotationFormat;
        highlightingRules.append(rule);
    //! [4]

    //! [5]
        functionFormat.setFontItalic(true);
        functionFormat.setForeground(Qt::yellow);
        rule.pattern = QRegExp("^[0-9]");
        rule.format = functionFormat;
        highlightingRules.append(rule);
    //! [5]

    //! [6]
        commentStartExpression = QRegExp("/\\*");
        commentEndExpression = QRegExp("\\*/");


}
//! [6]

//! [7]
void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
//! [7] //! [8]
    setCurrentBlockState(0);
//! [8]

//! [9]
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

//! [9] //! [10]
    while (startIndex >= 0) {
//! [10] //! [11]
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}
//! [11]
//void Highlighter::highlightCurrentLine()
//{
//    QList<QTextEdit::ExtraSelection> extraSelections;

//    //if (!isReadOnly())
//    {
//        QTextEdit::ExtraSelection selection;

//        QColor lineColor = QColor(Qt::yellow).lighter(160);

//        selection.format.setBackground(lineColor);
//        selection.format.setProperty(QTextFormat::FullWidthSelection, true);
//       // selection.cursor = textCursor();
//        selection.cursor.clearSelection();
//        extraSelections.append(selection);
//    }

//    //setExtraSelections(extraSelections);
//}
