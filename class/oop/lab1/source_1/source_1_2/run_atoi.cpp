#include<iostream>
#include<map>
#include<string.h>
using namespace std;

int decimal(const char * str)
{
	int len = strlen(str);
	int num = 0;
	int flag = 0;
	if (str[0] == '-'||str[0]=='+')
		flag = 1;
	for(int i=flag;i<len;++i)
	{
		int temp = str[i] - '0';
		num = num * 10 + temp;
	}
	if (str[0]=='-')
		num = -num;
	return num;
}

int octonary(const char * str)
{
	int len = strlen(str);
	int num = 0;
	int rec = 1;
	int flag = 0;
	if (str[0] == '-'||str[0]=='+')
		flag = 1;
	for(int i=len-1;i>flag;--i)
	{
		num = num + (str[i] - '0') * rec;
		rec = rec * 8;
	}
	if (str[0]=='-')
		num = -num;
	return num;
}

int hex(const char * str)
{
	int len = strlen(str);
	int flag = 1;
	if (str[0] == '-' || str[0] == '+')
		flag = 2;
	int num = 0;
	int rec = 1;
	map<char, int> m;
	for(int i=0;i<=9;++i)
	{
		char temp = char(i + '0');
		m[temp] = i;
	}
	for(int i=0;i<6;++i)
	{
		char temp = char('a' + i);
		m[temp] = 10 + i;
		temp = char('A') + i;
		m[temp] = 10 + i;
	}
	for(int i=len-1;i>flag;--i)
	{
		num = num + (str[i] - '0') * rec;
		rec = rec * 16;
	}
	if (str[0] == '-')
		num = -num;
	return num;
}

int mixture(const char * str)
{
	
}

int main()
{
	cout<<decimal("+123")<<endl;
	system("pause");
	return 0;	
}