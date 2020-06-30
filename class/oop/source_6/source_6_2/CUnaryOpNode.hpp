/*
 * 文件描述：
 *	       CUnaryOpNode类的定义。
 *         一元操作符类
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
#pragma once
#include "COpNode.hpp"
#include <iostream>
class CUnaryOpNode : public COpNode
{
protected:
    basic_node *mChild;

public:
    ~CUnaryOpNode() = default;

    virtual std::string generateInfix() const;

    virtual std::string generatePreFix() const;

    virtual std::string generatePostFix() const;

    virtual void printTree() const;

    virtual void deleteNode() = 0;

protected:
    CUnaryOpNode(Lexer::t_token _mToken, basic_node *_mChild = nullptr)
        : COpNode(_mToken), mChild(_mChild) {}

    CUnaryOpNode() = default;
};