/*
 * 文件描述：
 *	       CBinaryOpNode类成员函数的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/06/23
 *
 */
#include "CBinaryOpNode.hpp"

std::string CBinaryOpNode::generateInfix() const
{
    std::string left = this->mLeftChild->generateInfix();
    std::string right = this->mRightChild->generateInfix();
    std::string thisText;
    switch (this->mToken.tok_kind)
    {
    case Lexer::PLUS:
        thisText = "+";
        break;
    case Lexer::MINUS:
        thisText = "-";
        break;
    case Lexer::MUL:
        thisText = "*";
        break;
    case Lexer::DIV:
        thisText = "/";
        break;
    default:
        break;
    }
    return "(" + left + thisText + right + ")";
}

std::string CBinaryOpNode::generatePreFix() const
{
    std::string left = this->mLeftChild->generatePreFix();
    std::string right = this->mRightChild->generatePreFix();
    std::string thisText;
    switch (this->mToken.tok_kind)
    {
    case Lexer::PLUS:
        thisText = "+";
        break;
    case Lexer::MINUS:
        thisText = "-";
        break;
    case Lexer::MUL:
        thisText = "*";
        break;
    case Lexer::DIV:
        thisText = "/";
        break;
    default:
        break;
    }
    return thisText + " " + left + " " + right + " ";
}

std::string CBinaryOpNode::generatePostFix() const
{
    std::string left = this->mLeftChild->generatePostFix();
    std::string right = this->mRightChild->generatePostFix();
    std::string thisText;
    switch (this->mToken.tok_kind)
    {
    case Lexer::PLUS:
        thisText = "+";
        break;
    case Lexer::MINUS:
        thisText = "-";
        break;
    case Lexer::MUL:
        thisText = "*";
        break;
    case Lexer::DIV:
        thisText = "/";
        break;
    default:
        break;
    }
    return left + " " + right + " " + thisText + " ";
}

void CBinaryOpNode::printTree() const
{
    std::cout << this->generateInfix() << std::endl;
}

void CBinaryOpNode::deleteNode()
{
    this->mLeftChild->deleteNode();
    this->mRightChild->deleteNode();
    delete this;
}