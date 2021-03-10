/*
 * �ļ�������
 *		   Parser.hpp��غ����ӿڡ�
 *         Parserģ�����ڹ����﷨�������ַ���ת���ɺ�׺���ʽ�������׺���ʽ�����ͺͱ���Ϊ
 *         std::vector<Lexer::t_token> suffix,����һ��Lexer::t_token���͵�ջ��Ȼ���ǰ��
 *         ��ɨ���׺���ʽ�������������ֱ�ӽ���Ҷ�ӽڵ㲢����ջ������ǲ�����������һ���ڵ�
 *         parent����ջ��ȡ������Ԫ�أ��ȳ�ջ�Ĵ���Ϊparent�������������ջ�Ĵ���Ϊparent��
 *         ��������Ȼ��parent��ջ��ֱ��ɨ�����׺���ʽ�����ջ�л�ʣ�������ĸ��ڵ㣬���ظ�
 *         �ڵ��Exprģ�飬�����������׺���ʽ�ļ������ơ�
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/06/23
 *
 */
#pragma once

#include <stack>
#include <vector>
#include <map>
#include <sstream>
#include "Lexer.hpp"
#include "basic_node.hpp"
#include "CNumberNode.hpp"
#include "CDivNode.hpp"
#include "CMinusNode.hpp"
#include "CMulNode.hpp"
#include "CPlusNode.hpp"
#include "CUnaryMinusNode.hpp"
#include "CUnaryPlusNode.hpp"

class Parser
{
public:
    Parser();

    basic_node *constructTree(const char *str); //�����﷨��

private:
    void dispatch(Lexer &lexer); //��ȡ��һ���������������������makeSuffix

    void to_stack(Lexer &lexer, Lexer::t_token, int prior1); //��������ջ��ջ

    void makeSuffix(Lexer &lexer); //�����׺���ʽ

private:
    std::stack<Lexer::t_token> temp_stack; //����׺���ʽת��Ϊ��׺���ʽ�õ���ʱջ
    std::vector<Lexer::t_token> suffix;    //�����׺���ʽ�õ�����
    std::map<std::string, int> m;          //����������������ȼ��Ķ�Ӧ��ϵ
};