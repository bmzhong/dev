/*
 * �ļ�������
 *		   main���������ڲ��Գ���
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
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
		tree->regist((word));//��word�Ǽ������С�

    tree->print_byorder(cout);//���ֵ�˳���ӡ��
    
    system("pause");
    return 0;
}