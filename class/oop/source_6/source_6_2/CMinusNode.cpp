/*
 * 文件描述：
 *	       CMinusNode类成员函数的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
#include "CMinusNode.hpp"
double CMinusNode::eval() const
{
    return this->mLeftChild->eval() - this->mRightChild->eval();
}

std::string CMinusNode::typeName() const
{
    return "CMinusNode";
}