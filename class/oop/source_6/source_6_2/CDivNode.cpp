/*
 * 文件描述：
 *	       CDivNode类成员函数的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
#include "CDivNode.hpp"
double CDivNode::eval() const
{
    return this->mLeftChild->eval() / this->mRightChild->eval();
}

std::string CDivNode::typeName() const
{
    return "CDivNode";
}