/*
 * 文件描述：
 *	       COpNode类的定义。
 *         操作符的父类。
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
#pragma once
#include "basic_node.hpp"
#include "Lexer.hpp"
class COpNode : public basic_node
{
public:
    ~COpNode() = default;

protected:
    COpNode(Lexer::t_token _mToken) : basic_node(_mToken) {} // 结点中存放的数值

    COpNode() = default;
};