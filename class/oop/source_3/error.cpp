/*
 * �ļ�������ʵ�ִ���������error handler��
 *		   
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/11
 *
 */
#include <string>
#include <iostream>
#include "lexer.h"
using namespace std;

namespace Error
{

int no_of_errors = 0;
//�������
double error(const int &rows, const string &msg)
{
    ++no_of_errors;
    cerr << "error row:" << rows << "   " << msg << "\n";
    return 1;
}
//��ȡ������Ϣ
string error_msg(const int &error_type)
{
    string error_message="bad expression";
    if (error_type == 1)
    {
        error_message = "divide by 0";
    }
    if (error_type == 2)
    {
        error_message = ") expected";
    }
    if (error_type == 3)
    {
        error_message = "primary expected";
    }
    return error_message;
}

} // namespace Error
