/*
 * 文件描述：
 *	       CUnaryMinusNode类成员函数的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
#include "CUnaryMinusNode.hpp"
double CUnaryMinusNode::eval() const
{
    return - this->mChild->eval();
}

std::string CUnaryMinusNode::typeName() const
{
    return "CUnaryMinusNode";
}