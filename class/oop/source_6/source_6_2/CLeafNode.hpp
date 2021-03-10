/*
 * 文件描述：
 *	       CLeafNode类的定义
 *         叶子节点类。
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
class CLeafNode : public basic_node
{
public:
    ~CLeafNode() = default;

protected:
    CLeafNode(Lexer::t_token _mToken) : basic_node(_mToken) {} 

    CLeafNode() = default;
};