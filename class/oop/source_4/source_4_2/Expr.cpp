/*
 * �ļ�������
 *		   Expr.hpp��غ�����ʵ��
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/23
 *
 */

#include "Expr.hpp"

Expr::Expr(const char *str)
{
    Parser parser;
    root = parser.constructTree(str);//�����﷨��
}

Expr::~Expr()
{
    this->root->deleteNode(this->root);//�����﷨��
}

double Expr::getValue() const
{
    return root->getValue();//���ر��ʽ��ֵ
}

void Expr::printMid() const//��ӡ��׺���ʽ
{
    std::string text;
    text = root->getText_mid();
    std::cout << text << std::endl;
}

void Expr::printPre() const//��ӡǰ׺���ʽ
{
    std::string text;
    text = root->getText_pre();
    std::cout << text << std::endl;
}

void Expr::printPost() const//��ӡ��׺���ʽ
{
    std::string text;
    text = root->getText_post();
    std::cout << text << std::endl;
}
