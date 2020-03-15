/*
 * 文件描述：
 *		   带main函数的文件，用于测试itoa函数。		   
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/04
 *
 */
#include <iostream>
#include "itoa.cpp"

using namespace std;

int main()
{
    int test;
    int base;
    while (cin >> test >> base)
    {
        char ch[100];
        my_itoa::itoa(test, ch, base);
        cout << ch << endl;
    }

    system("pause");
    return 0;
}
