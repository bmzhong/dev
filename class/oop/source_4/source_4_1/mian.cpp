/*
 * 文件描述：
 *		   main函数，用于测试程序
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/23
 *
 */

#include <iostream>
#include <string>
#include "Tree.cpp"
using namespace std;
int main()
{
    Tree *tree = new Tree();
    string word;
	
	while(cin>>word)
		tree->regist((word));//将word登记在树中。

    tree->print_byorder(cout);//以字典顺序打印树
    
    system("pause");
    return 0;
}