/*
 * �ļ�������
 *	   Exprģ�����غ����ӿ�
 *
 *     Exprģ�飺���캯������Parseģ�����غ��������﷨�����������������﷨������Ա����
 *     printMid��printPre��printPost��GetValue����Nodeģ�����غ����õ���Ӧ���ַ�����
 *     �����ַ����ṩ���û���
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/23
 *
 */


#ifndef _THIS_IS_EXPR_
#define _THIS_IS_EXPR_
#include "Parser.hpp"
#include "Node.hpp"
#include <iostream>
class Expr
{
public:
    Expr(const char *str);//�����﷨��

    ~Expr();//�����﷨��

    double getValue() const;//�õ����ʽ��ֵ

    void printMid() const;//��ӡ��׺���ʽ

    void printPre() const;//��ӡǰ׺���ʽ

    void printPost() const;//��ӡ��׺���ʽ

private:
    Node *root; // ָ����ʽ���������
};
#endif
