/*
 * 文件描述：
 *	       CMinusNode类的定义
 *         减法类
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
#pragma once
#include "CBinaryOpNode.hpp"
#include "Lexer.hpp"
class CMinusNode : public CBinaryOpNode
{
public:
    ~CMinusNode() = default;

    CMinusNode(Lexer::t_token _mToken,
               basic_node *_mLeftChild = nullptr, basic_node *_mRightChild = nullptr)
        : CBinaryOpNode(_mToken, _mLeftChild, _mRightChild) {}

    CMinusNode() = default;

    virtual double eval() const;

    virtual std::string typeName() const;
};