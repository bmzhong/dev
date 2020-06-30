/*
 * �ļ�������
 *	   Exprģ�����غ����ӿ�
 *
 *     Exprģ�飺���캯������Parseģ�����غ��������﷨�����������������﷨������Ա����
 *     printMid��printPre��printPost��GetValue�������ڵ�ģ�����غ����õ���Ӧ���ַ����ͣ�
 *     ���ʽ��ֵ���ṩ���û���
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/06/23
 *
 */
#pragma once
#include "Parser.hpp"
#include "basic_node.hpp"
#include <iostream>
#include <string>
class Expr
{
public:
    Expr(const char *str); //�����﷨��

    ~Expr(); //�����﷨��

    double getValue() const; //�õ����ʽ��ֵ

    void printMid() const; //��ӡ��׺���ʽ

    void printPre() const; //��ӡǰ׺���ʽ

    void printPost() const; //��ӡ��׺���ʽ

private:
    basic_node *root; // ָ����ʽ���������
};
