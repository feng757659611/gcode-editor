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
#ifndef CLASSDEFINE_H
#define CLASSDEFINE_H
#include "memorystruct.h"
#include <QString>
class MemoryCenter
{
    private:
        struct LineHeadPointer *memoryHead;//����﷨����ָ���ͷָ��
        struct FunctionList *functionHead;//��ź����б���ָ���ͷָ��
        struct CompleList *compleHead;//��Ų�ȫ���Ʊ���ָ���ͷָ��
        struct LineNumberList *lineNumberHead;//����кű���ָ���ͷָ��
        QString keyWordList [ 100 ];//���������͹ؼ��ʵı�
        void resetLine ( );//�����﷨�к���
        void resetFunctionList ( );//���º����б���
        void resetCompleList ( );//���±�������
        void resetLineNumberList ( );//�����кű���
        void buildKeyWordList ( );//�����ؼ��ʱ���
        void buildLineNumberList ( QString codeString );//�����кű���
        int judgeWordCategory ( const QString & thisWord , const int startFindPosition , const int endFindPosition );//�жϴ����ͺ���
        QString cutWord ( const QString & codeString , const int & codePosition , int & wordLength , int & wordKind );//�и�ʺ���
        struct LineHeadPointer *analysisBraces ( const QString & firstWord );//�����Ŵʷ���������
        struct LineHeadPointer *analysisMacro ( const QString codeString , const QString & firstWord , int & codePosition );//�궨��ʷ���������
        struct LineHeadPointer *analysisSemicolon ( const QString codeString , const QString & firstWord , int & codePosition );//�ֺŴʷ���������
        struct LineHeadPointer *analysisRemark ( const QString codeString , const QString & firstWord , int & codePosition );//ע�ʹʷ���������
        struct LineHeadPointer *analysisOther ( const QString codeString , const QString & firstWord , const int & firstWordKind , int & codePosition );//�����ǹؼ��ʴʷ���������
        struct LineHeadPointer *analysisKey ( const QString codeString , const QString & firstWord , int & codePosition );//�ؼ��ʴʷ���������
        void resetLogicLevel ( );//�����﷨���߼��ȼ�����
        void analysisLogicLevel ( );//�﷨���߼��ȼ���������
        QString relayoutStyle ( int styleNumber );//����Ҫ���ʽ���İ溯��
        QString relayoutRemark ( int logicLevel , QString remarkString );//���Ű����ע�ͺ���
        struct FunctionList *analysisFunction ( LineHeadPointer *memoryTemp );//���ɺ����ṹ����
    public:
        MemoryCenter ( );//���캯��
        ~MemoryCenter ( );//��������
        bool analysisMain ( QString & codeString );//�ʷ��������庯��
        struct LineHeadPointer * getLineHead ( );//��ȡ�﷨����ָ�뺯��
        bool makeFunctionList ( QString & codeString );//���ɺ����б���
        struct FunctionList * getFunctionList ( );//��ȡ�����б���
        bool makeCompleList ( );//���ɲ�ȫ����
        struct CompleList * findCompleList ( QString & wordString , int & matchNumber , int & matcheLength );//��ѯ��ȫ����
        QString relayout ( int styleNumber );//���Ű溯��
        int autoIndent ( QString & codeString , int codePosition );//�Զ���������
        int changeIndent ( QString & codeString , QString & lineString , int codePosition , int changeMode );//�����������
        QString makeFunctionRemark ( );//���ɺ�����׼ע�ͺ���
};

#endif
