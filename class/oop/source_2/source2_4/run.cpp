/*
 * 文件描述：
 *		   测试Date类型的相关操作。
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/19
 *
 */
#include <iostream>
#include "date.cpp"
using namespace _Date_;
int main()
{
    Date date = {1700, 1, 1};
    int week = get_week(date);
    system("pause");
    return 0;
}
