/*
 * 文件描述：
 *	       CBinaryOpNode类的定义。
 *         二元操作符类。
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

class CBinaryOpNode : public COpNode
{
protected:
    basic_node *mLeftChild;
    basic_node *mRightChild;

public:
    ~CBinaryOpNode() = default;

    virtual std::string generateInfix() const;

    virtual std::string generatePreFix() const;

    virtual std::string generatePostFix() const;

    virtual void printTree() const;

    virtual void deleteNode();

protected:
    CBinaryOpNode(Lexer::t_token _mToken,
                  basic_node *_mLeftChild = nullptr, basic_node *_mRightChild = nullptr)
        : COpNode(_mToken), mLeftChild(_mLeftChild), mRightChild(_mRightChild) {}

    CBinaryOpNode() = default;
};