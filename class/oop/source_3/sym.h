/*
 * �ļ����������ű�symbol table���ӿ�
 *		   
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/11
 *
 */
#ifndef _Symbol_table_
#define _Symbol_table_

#include<map>
#include<string>
using namespace std;

namespace Symbol_table{
   
   extern map<string, double> table; //���ű�: "��������������-ֵ" 

   void init();//��ʼ��table

   void add(const string &name,const double &value);//��ӱ�����ֵ

   double select(const string &name);//��ѯ������ֵ

   void update(const string &name,const double &value);//���±�����ֵ

}

#endif