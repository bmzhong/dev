
#include<iostream>

#include<string>

using namespace std;

int main()

{

	string str = "he is@ a@ good boy";

	char * str1 = "12345";

	str=str.replace(0,5,str1);   //��str�滻��ָ��λ�ÿ�ʼ����Ϊ5���ַ���

	cout<<str<<endl;

	return 0; 

}

