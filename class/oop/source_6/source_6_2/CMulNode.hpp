/*
 * 文件描述：
 *	       CMulNode类的定义。
 *         乘法类。
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
class CMulNode : public CBinaryOpNode
{
public:
    ~CMulNode() = default;

    CMulNode(Lexer::t_token _mToken,
             basic_node *_mLeftChild = nullptr, basic_node *_mRightChild = nullptr)
        : CBinaryOpNode(_mToken, _mLeftChild, _mRightChild) {} 

    CMulNode() = default;

    virtual double eval() const;

    virtual std::string typeName() const;
};
