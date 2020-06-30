/*
 * 文件描述：
 *	       CNumberNode类的定义。
 *         数值类
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
#pragma once
#include "Lexer.hpp"
#include "CLeafNode.hpp"
#include <cstdio>
class CNumberNode : public CLeafNode
{
public:
    ~CNumberNode() = default;

    virtual double eval() const; // 计算并返回表达式的值

    virtual std::string typeName() const;

    CNumberNode(Lexer::t_token _mToken) : CLeafNode(_mToken) {} // 结点中存放的数值

    CNumberNode() = default;

    virtual void deleteNode();

    virtual std::string generateInfix() const ;

    virtual std::string generatePreFix() const ;

    virtual std::string generatePostFix() const ;
};