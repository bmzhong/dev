/*
 * 文件描述：
 *	       CNumberNode类成员函数的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
#include "CNumberNode.hpp"

double CNumberNode::eval() const
{
    return atof(this->mToken.tok_txt.c_str());
}

std::string CNumberNode::typeName() const
{
    return "CNumberNode";
}
void CNumberNode::deleteNode()
{
    delete this;
}

std::string CNumberNode::generateInfix() const
{
    return this->mToken.tok_txt;
}

std::string CNumberNode::generatePreFix() const
{
    return this->mToken.tok_txt;
}

std::string CNumberNode::generatePostFix() const
{
    return this->mToken.tok_txt;
}