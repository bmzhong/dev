/*
 * 文件描述：
 *		   Parser.hpp相关函数接口。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
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

    Node *constructTree(const char *str);//构造语法树

private:
    void dispatch(Lexer &lexer);//读取第一个操作数或操作符并调用makeSuffix

    void to_stack(Lexer &lexer, char ch, int prior1);//操作符入栈出栈

    void makeSuffix(Lexer &lexer);//构造后缀表达式

private:
    std::stack<char> temp_stack; //将中缀表达式转换为后缀表达式用的临时栈
    std::vector<std::pair<double, char>> suffix; //储存后缀表达式用的向量
    std::map<char, int> m;                       //储存操作符及其优先级的对应关系
};
#endif