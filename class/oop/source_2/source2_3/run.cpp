/*
 * 文件描述：
 *		   测试error函数
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/19
 *
 */

#include <iostream>
#include "error.cpp"
using namespace std;

int main()
{
    Error::error("i %s %d do%clar\n", "have", 10, 'l');
    system("pause");
    return 0;
}
