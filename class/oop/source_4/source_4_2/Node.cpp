/*
 * 文件描述：
 *		   Node.hpp的实现。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/23
 *
 */
#include "Node.hpp"
Node::Node(Lexer::Token_type tokenType,
           Node *leftChild,
           Node *rightChild, 
           double value1)
{
    left = leftChild;
    right = rightChild;
    token = tokenType;
    value = value1;
}

Node::~Node() {}

Node *Node::getLeftChild() const { return left; }//返回左子孩子

Node *Node::getRightChild() const { return right; }//返回右子孩子

std::string Node::getText_mid() const//得到中缀表达式,提供给Expr模块
{
    std::string text;
    midRecursion(text, this);//调用本类的私有成员函数得到中缀表达式
    return text;
}

std::string Node::getText_pre() const//得到前缀表达式,提供给Expr模块
{
    std::string text;
    preRecursion(text, this);//调用本类的私有成员函数得到前缀表达式
    return text;
}

std::string Node::getText_post() const//得到后缀表达式,提供给Expr模块
{
    std::string text;
    postRecursion(text, this);//调用本类的私有成员函数得到后缀表达式
    return text;
}

double Node::getValue() const
{
    return caculateByPost(this);//调用本类的私有成员函数得到表达式的值

}
//本类的私有成员函数,得到中缀表达式
void Node::midRecursion(std::string &text, const Node *node) const
{
    if (node == nullptr)
        return;
    //           左子树的表达式，右子树的表达式，本节点的操作数或操作符得到的字符串
    std::string subExprssion1, subExprssion2, thisNodeExpression;
    midRecursion(subExprssion1, node->left);//得到左子树的表达式
    char temp[350];
    std::stringstream ss;
    switch (node->token)
    {
    case Lexer::NUMBER:
        ss << node->value;
        ss >> temp;//将操作数转换成字符串
        ss.clear();
        thisNodeExpression = temp;
        break;
    case Lexer::PLUS:
        thisNodeExpression = "+";
        break;
    case Lexer::MINUS:
        thisNodeExpression = "-";
        break;
    case Lexer::MUL:
        thisNodeExpression += "*";
        break;
    case Lexer::DIV:
        thisNodeExpression = "/";
        break;
    default:
        break;
    }
    midRecursion(subExprssion2, node->right);//得到右子树的表达式
    if (node->token == Lexer::NUMBER)
        text += thisNodeExpression;
    else//如果是操作符，则加括号
        text += "(" + subExprssion1 + thisNodeExpression + subExprssion2 + ")";
}
//得到前缀表达式
void Node::preRecursion(std::string &text, const Node *node) const
{
    if (node == nullptr)
        return;
    char temp[350];
    std::stringstream ss;
    switch (node->token)
    {
    case Lexer::NUMBER:
        ss << node->value;
        ss >> temp;//将操作数转换成字符串
        ss.clear();
        text += temp;
        break;
    case Lexer::PLUS:
        text += "+";
        break;
    case Lexer::MINUS:
        text += "-";
        break;
    case Lexer::MUL:
        text += "*";
        break;
    case Lexer::DIV:
        text += "/";
        break;
    default:
        break;
    }
    text += " ";//加空格方便区分
    preRecursion(text, node->left);//得到左子树的表达式
    preRecursion(text, node->right);//得到右子树的表达式
}
//得到后缀表达式
void Node::postRecursion(std::string &text, const Node *node) const
{
    if (node == nullptr)
        return;
    postRecursion(text, node->left);//得到左子树的表达式
    postRecursion(text, node->right);//得到右子树的表达式
    char temp[350];
    std::stringstream ss;
    switch (node->token)
    {
    case Lexer::NUMBER:
        ss << node->value;
        ss >> temp;
        ss.clear();
        text += temp;
        break;
    case Lexer::PLUS:
        text += "+";
        break;
    case Lexer::MINUS:
        text += "-";
        break;
    case Lexer::MUL:
        text += "*";
        break;
    case Lexer::DIV:
        text += "/";
        break;
    default:
        break;
    }
    text += " ";//加空格方便区分
}
//计算表达式的值
double Node::caculateByPost(const Node *node) const
{
    if (node == nullptr)
        return 0;
    double res1 = caculateByPost(node->left);//得到左子树表达式的值
    double res2 = caculateByPost(node->right);//得到右子树表达式的值
    switch (node->token)
    {
    case Lexer::NUMBER:
        return res1 + res2 + node->value;
    case Lexer::PLUS:
        return res1 + res2;
    case Lexer::MINUS:
        return res1 - res2;
    case Lexer::MUL:
        return res1 * res2;
    case Lexer::DIV:
        if (res2 == 0)
            throw "除零错误";//将错误抛出
        return res1 / res2;
    default:
        break;
    }
    return 0;
}

void Node::deleteNode(Node *node)//删除这棵树
{
    if (node == nullptr)
        return;
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}