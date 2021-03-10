/*
 * 文件描述：
 *	       CUnaryPlusNode类的定义。
 *         一元加法类
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
class CUnaryPlusNode : public CUnaryOpNode
{
public:
    ~CUnaryPlusNode() = default;

    CUnaryPlusNode(Lexer::t_token _mToken, basic_node *_mChild = nullptr)
        : CUnaryOpNode(_mToken, _mChild) {} // 结点中存放的数值

    CUnaryPlusNode() = default;

    virtual double eval() const;

    virtual std::string typeName() const;
};