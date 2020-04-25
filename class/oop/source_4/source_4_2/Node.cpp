/*
 * �ļ�������
 *		   Node.hpp��ʵ�֡�
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
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

Node *Node::getLeftChild() const { return left; }//�������Ӻ���

Node *Node::getRightChild() const { return right; }//�������Ӻ���

std::string Node::getText_mid() const//�õ���׺���ʽ,�ṩ��Exprģ��
{
    std::string text;
    midRecursion(text, this);//���ñ����˽�г�Ա�����õ���׺���ʽ
    return text;
}

std::string Node::getText_pre() const//�õ�ǰ׺���ʽ,�ṩ��Exprģ��
{
    std::string text;
    preRecursion(text, this);//���ñ����˽�г�Ա�����õ�ǰ׺���ʽ
    return text;
}

std::string Node::getText_post() const//�õ���׺���ʽ,�ṩ��Exprģ��
{
    std::string text;
    postRecursion(text, this);//���ñ����˽�г�Ա�����õ���׺���ʽ
    return text;
}

double Node::getValue() const
{
    return caculateByPost(this);//���ñ����˽�г�Ա�����õ����ʽ��ֵ

}
//�����˽�г�Ա����,�õ���׺���ʽ
void Node::midRecursion(std::string &text, const Node *node) const
{
    if (node == nullptr)
        return;
    //           �������ı��ʽ���������ı��ʽ�����ڵ�Ĳ�������������õ����ַ���
    std::string subExprssion1, subExprssion2, thisNodeExpression;
    midRecursion(subExprssion1, node->left);//�õ��������ı��ʽ
    char temp[350];
    std::stringstream ss;
    switch (node->token)
    {
    case Lexer::NUMBER:
        ss << node->value;
        ss >> temp;//��������ת�����ַ���
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
    midRecursion(subExprssion2, node->right);//�õ��������ı��ʽ
    if (node->token == Lexer::NUMBER)
        text += thisNodeExpression;
    else//����ǲ��������������
        text += "(" + subExprssion1 + thisNodeExpression + subExprssion2 + ")";
}
//�õ�ǰ׺���ʽ
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
        ss >> temp;//��������ת�����ַ���
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
    text += " ";//�ӿո񷽱�����
    preRecursion(text, node->left);//�õ��������ı��ʽ
    preRecursion(text, node->right);//�õ��������ı��ʽ
}
//�õ���׺���ʽ
void Node::postRecursion(std::string &text, const Node *node) const
{
    if (node == nullptr)
        return;
    postRecursion(text, node->left);//�õ��������ı��ʽ
    postRecursion(text, node->right);//�õ��������ı��ʽ
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
    text += " ";//�ӿո񷽱�����
}
//������ʽ��ֵ
double Node::caculateByPost(const Node *node) const
{
    if (node == nullptr)
        return 0;
    double res1 = caculateByPost(node->left);//�õ����������ʽ��ֵ
    double res2 = caculateByPost(node->right);//�õ����������ʽ��ֵ
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
            throw "�������";//�������׳�
        return res1 / res2;
    default:
        break;
    }
    return 0;
}

void Node::deleteNode(Node *node)//ɾ�������
{
    if (node == nullptr)
        return;
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}