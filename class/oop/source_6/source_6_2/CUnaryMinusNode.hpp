/*
 * 文件描述：
 *	       CUnaryMinusNode类的定义。
 *         一元减法类
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
#pragma once
#include "CUnaryOpNode.hpp"
#include "Lexer.hpp"
class CUnaryMinusNode : public CUnaryOpNode
{
public:
    ~CUnaryMinusNode() = default;

    CUnaryMinusNode(Lexer::t_token _mToken, basic_node *_mChild = nullptr)
        : CUnaryOpNode(_mToken, _mChild) {} // 结点中存放的数值

    CUnaryMinusNode() = default;

    virtual double eval() const;

    virtual std::string typeName() const;
};