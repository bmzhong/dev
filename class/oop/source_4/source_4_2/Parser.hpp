/*
 * �ļ�������
 *		   Parser.hpp��غ����ӿڡ�
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/23
 *
 */

#ifndef _THIS_IS_PARSER_
#define _THIS_IS_PARSER_

#include <stack>
#include <vector>
#include <map>
#include "Lexer.hpp"
#include <algorithm>
#include "Node.hpp"
#include <iostream>

class Parser
{
public:
    Parser();

    Node *constructTree(const char *str);//�����﷨��

private:
    void dispatch(Lexer &lexer);//��ȡ��һ���������������������makeSuffix

    void to_stack(Lexer &lexer, char ch, int prior1);//��������ջ��ջ

    void makeSuffix(Lexer &lexer);//�����׺���ʽ

private:
    std::stack<char> temp_stack; //����׺���ʽת��Ϊ��׺���ʽ�õ���ʱջ
    std::vector<std::pair<double, char>> suffix; //�����׺���ʽ�õ�����
    std::map<char, int> m;                       //����������������ȼ��Ķ�Ӧ��ϵ
};
#endif