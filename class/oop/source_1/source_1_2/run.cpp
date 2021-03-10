/*
 * 文件描述：
 *		   带main函数的文件，用于测试atoi函数。		   
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
#include "atoi.cpp"
using namespace std;
int main()
{
	char *ch = new char[100];
	while (cin >> ch)
	{
		int num = my_atoi::atoi(ch);
		cout << num << endl;
	}
	system("pause");
	return 0;
}
