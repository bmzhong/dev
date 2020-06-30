/*
 * �ļ�������
 *		   Expr.hpp���Ա������ʵ��
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/06/23
 *
 */
#include "Expr.hpp"

Expr::Expr(const char *str)
{
    Parser parser;
    root = parser.constructTree(str); //�����﷨��
}

Expr::~Expr()
{
    this->root->deleteNode(); //�����﷨��
}

double Expr::getValue() const
{
    return root->eval(); //���ر��ʽ��ֵ
}

void Expr::printMid() const //��ӡ��׺���ʽ
{
    std::string text;
    text = root->generateInfix();
    std::cout << text << std::endl;
}

void Expr::printPre() const //��ӡǰ׺���ʽ
{
    std::string text;
    text = root->generatePreFix();
    std::cout << text << std::endl;
}

void Expr::printPost() const //��ӡ��׺���ʽ
{
    std::string text;
    text = root->generatePostFix();
    std::cout << text << std::endl;
}
