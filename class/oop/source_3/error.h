/*
 * �ļ�����������������error handler���ӿ�
 *		   
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/11
 *
 */
#ifndef _Error_
#define _Error_

#include<string>
#include "lexer.h"
#include "parser.h"
using namespace std;

namespace Error{

    extern int no_of_errors;//ȫ�ֱ���no_of_errors��ʾ������� 

    double error(const int &rows, const string &msg);//���������Ϣ

    string error_msg(const int &error_type);//����error_tpye��ֵ���ش�����Ϣ
}
#endif
