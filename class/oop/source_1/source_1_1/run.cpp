/*
 * �ļ�������
 *		   ��main�������ļ����������ݣ����㣬����������������̨�С�		   
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/03/04
 *
 */

#include<iostream>
#include "Info.cpp"
#include<map>
#include <string>
using namespace std;

map<string, Info> table;//ͨ��ȫ�ֱ���table���������������

int main()
{
	string name;
	int value;
	
	while(cin>>name>>value)//Windos ����ctrl+z��������
	{
		table[name].sum =table[name].sum+value;//��name��һ�γ���ʱ��table[name]��ֵ������޲ι��캯����ʼ��sum��countΪ0��
		++table[name].count;
	}

	double all_sum = 0;  //����name��Ӧ��value�ܺͣ�
	int all_count = 0;//����name���ֵĴ����ܺͣ�
	double all_mean = 0;//����name��Ӧ��value��ƽ����;
	
	//���ÿ��name��value���ܺͺ�ƽ��ֵ,������all_sum,all_count��
	cout << "������С�ƣ�" << endl;
	for(auto it:table)
	{
		cout << it.first << " �ܺ�: " << it.second.sum << " ƽ��ֵ��" << it.second.sum / it.second.count << endl;
		all_count += it.second.count;
		all_sum += it.second.sum;
	}

	all_mean = all_sum / all_count;

	//���ƽ��ֵ
	cout << "\n�ܼƣ�" << endl;
	cout <<"�ܺͣ�" << all_sum <<" ƽ��ֵ��" << all_mean << endl;
	
	system("pause");
	return 0;
	
	
}

