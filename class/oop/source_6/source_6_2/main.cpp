/*
 * 文件描述：
 *		   main函数，用于测试程序的功能。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
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
            cout << "中缀表达式：";
            ex->printMid();
            cout << "前缀表达式: ";
            ex->printPre();
            cout << "后缀表达式: ";
            ex->printPost();
            cout << "表达式的值: ";
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