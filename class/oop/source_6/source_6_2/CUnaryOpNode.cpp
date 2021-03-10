/*
 * 文件描述：
 *	       CUnaryOpNode类成员函数的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */

#include "CUnaryOpNode.hpp"
std::string CUnaryOpNode::generateInfix() const
{
    std::string child = this->mChild->generateInfix();
    std::string thisText;
    switch (this->mToken.tok_kind)
    {
    case Lexer::UnaryPlus:
        thisText = "+";
        break;
    case Lexer::UnartMinus:
        thisText = "-";
        break;
    default:
        break;
    }
    return "(" + child + thisText + ")";
}
std::string CUnaryOpNode::generatePreFix() const
{
    std::string child = this->mChild->generatePreFix();
    std::string thisText;
    switch (this->mToken.tok_kind)
    {
    case Lexer::UnaryPlus:
        thisText = "+";
        break;
    case Lexer::UnartMinus:
        thisText = "-";
        break;
    default:
        break;
    }
    return thisText + " " + child + " ";
}

std::string CUnaryOpNode::generatePostFix() const
{
    std::string child = this->mChild->generatePostFix();
    std::string thisText;
    switch (this->mToken.tok_kind)
    {
    case Lexer::UnaryPlus:
        thisText = "+";
        break;
    case Lexer::UnartMinus:
        thisText = "-";
        break;
    default:
        break;
    }
    return child + " " + thisText + " ";
}

void CUnaryOpNode::printTree() const
{
    std::cout << this->generateInfix() << std::endl;
}

void CUnaryOpNode::deleteNode()
{
    this->mChild->deleteNode();
    delete this;
}
