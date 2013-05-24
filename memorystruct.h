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
#include <QString>

//�﷨����ָ��ṹ����
struct LineHeadPointer
{
    int logicLevel;//��Ÿ����߼��ȼ�
    int linePosition;//��Ÿ�����ԭ���е�λ��
    struct LineHeadPointer *previousLine;//�����һ�﷨��
    struct LineHeadPointer *nextLine;//�����һ�﷨��
    struct LexicalAnalysis *firstWord;//��ű��﷨���׵���
};

//�ʷ������ṹ����
struct LexicalAnalysis
{
    QString wordContent;//��Ÿô�����
    int wordLength;//���ԭ�ʳ���
    int wordCategory;//���ԭ������
    int wordPosition;//���ԭ����ԭ����λ��
    struct LineHeadPointer *whichLine;//��Ÿô�������
    struct LexicalAnalysis *previousWord;//�����һ�﷨��
    struct LexicalAnalysis *nextWord;//�����һ�﷨��
};

//�����б�ṹ����
struct FunctionList
{
    QString functionName;//��ź�������
    int functionNameLength;//��ź������Ƴ���
    QString functionCategory;//��ź�������
    int functionCategoryLength;//��ź������ͳ���
    int parameterNumber;//��Ų�������
    int functionPosition;//��ź�����ԭ���е�λ��
    int functionLine;//��ź�����ԭ����������
    QString functionOutput;//��ź����б������ʽ
    struct ParameterList *firstParameter;//��Ų������׸�����
    struct FunctionList *previousFunction;//�����һ������
    struct FunctionList *nextFunction;//�����һ������
};

//������ṹ����
struct ParameterList
{
    QString parameterName;//��Ų�������
    int parameterNameLength;//��Ų������Ƴ���
    QString parameterCategory;//��Ų�������
    int parameterCategoryLength;//��Ų������ͳ���
    QString parameterTail;//��Ų���β��
    int parameterTailLength;//��Ų���β������
    struct FunctionList *whichFunction;//��Ÿò������ں���
    struct ParameterList *previousParameter;//�����һ����
    struct ParameterList *nextParameter;//�����һ����
};

//�кű�ṹ����
struct LineNumberList
{
    int lineNumber;//����к�
    int linePosition;//��ŵ�ǰ����ԭ�ĵ�λ��
    struct LineNumberList *nextLineNumber;//�����һ�к�
};

//��ȫ��ṹ����
struct CompleList
{
    QString compleName;//��ű�������
    int compleNameLength;//��ű������Ƴ���
    struct CompleList *previousComple;//�����һ����
    struct CompleList *nextComple;//�����һ����
};
