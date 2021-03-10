/*
 * 文件描述：
 *	       CUnaryPlusNode类成员函数的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */

#include "CUnaryPlusNode.hpp"
double CUnaryPlusNode::eval() const
{
    return +this->mChild->eval();
}

std::string CUnaryPlusNode::typeName() const
{
    return "CUnaryPlusNode";
}