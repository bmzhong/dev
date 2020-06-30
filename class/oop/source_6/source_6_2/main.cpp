/*
 * �ļ�������
 *		   main���������ڲ��Գ���Ĺ��ܡ�
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
#include <string>

using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        try
        {
            Expr *ex = new Expr(str.c_str());
            cout << "��׺���ʽ��";
            ex->printMid();
            cout << "ǰ׺���ʽ: ";
            ex->printPre();
            cout << "��׺���ʽ: ";
            ex->printPost();
            cout << "���ʽ��ֵ: ";
            cout << ex->getValue() << endl;
            delete ex;
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }

    system("pause");
    return 0;
}