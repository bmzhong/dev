/*
 * 文件描述：
 *	       CPlusNode类的定义。
 *         加法类。
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
class CPlusNode : public CBinaryOpNode
{
public:
    ~CPlusNode() = default;

    CPlusNode(Lexer::t_token _mToken,
              basic_node *_mLeftChild = nullptr, basic_node *_mRightChild = nullptr)
        : CBinaryOpNode(_mToken, _mLeftChild, _mRightChild) {}

    CPlusNode() = default;

    virtual double eval() const;

    virtual std::string typeName() const;
};