/*
 * 文件描述：
 *	       CPlusNode类成员函数的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */

#include "CPlusNode.hpp"
double CPlusNode::eval() const
{
    return this->mLeftChild->eval() + this->mRightChild->eval();
}

std::string CPlusNode::typeName() const
{
    return "CPlusNode";
}