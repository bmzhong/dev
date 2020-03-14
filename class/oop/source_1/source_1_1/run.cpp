/*
 * 文件描述：
 *		   带main函数的文件，输入数据，计算，并将结果输出到控制台中。		   
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/04
 *
 */

#include<iostream>
#include "Info.cpp"
#include<map>
#include <string>
using namespace std;

map<string, Info> table;//通过全局变量table来储存输入的数据

int main()
{
	string name;
	int value;
	
	while(cin>>name>>value)//Windos 下以ctrl+z结束输入
	{
		table[name].sum =table[name].sum+value;//当name第一次出现时，table[name]的值会调用无参构造函数初始化sum和count为0；
		++table[name].count;
	}

	double all_sum = 0;  //所有name对应的value总和；
	int all_count = 0;//所有name出现的次数总和；
	double all_mean = 0;//所有name对应的value的平均数;
	
	//输出每个name的value的总和和平均值,并计算all_sum,all_count。
	cout << "按名字小计：" << endl;
	for(auto it:table)
	{
		cout << it.first << " 总和: " << it.second.sum << " 平均值：" << it.second.sum / it.second.count << endl;
		all_count += it.second.count;
		all_sum += it.second.sum;
	}

	all_mean = all_sum / all_count;

	//输出平均值
	cout << "\n总计：" << endl;
	cout <<"总和：" << all_sum <<" 平均值：" << all_mean << endl;
	
	system("pause");
	return 0;
	
	
}

