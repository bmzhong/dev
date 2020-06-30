/*
 * 文件描述：
 *		   Parser.hpp相关函数接口。
 *         Parser模块用于构建语法树：将字符串转换成后缀表达式，储存后缀表达式的类型和变量为
 *         std::vector<Lexer::t_token> suffix,建立一个Lexer::t_token类型的栈，然后从前往
 *         后扫描后缀表达式，如果是数字则直接建立叶子节点并且入栈，如果是操作符，建立一个节点
 *         parent，从栈中取出两个元素，先出栈的创建为parent的右子树，后出栈的创建为parent的
 *         左子树，然后将parent入栈；直到扫描完后缀表达式。最后栈中还剩整棵树的根节点，返回根
 *         节点给Expr模块，整个过程与后缀表达式的计算类似。
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
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

    basic_node *constructTree(const char *str); //构造语法树

private:
    void dispatch(Lexer &lexer); //读取第一个操作数或操作符并调用makeSuffix

    void to_stack(Lexer &lexer, Lexer::t_token, int prior1); //操作符入栈出栈

    void makeSuffix(Lexer &lexer); //构造后缀表达式

private:
    std::stack<Lexer::t_token> temp_stack; //将中缀表达式转换为后缀表达式用的临时栈
    std::vector<Lexer::t_token> suffix;    //储存后缀表达式用的向量
    std::map<std::string, int> m;          //储存操作符及其优先级的对应关系
};