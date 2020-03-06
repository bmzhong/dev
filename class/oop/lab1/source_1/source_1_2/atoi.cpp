#include<map>
#include<string.h>
#include<string>
using namespace std;

int decimal(const char* str)
{
	int len = strlen(str);
	int num = 0;
	int flag = 0;
	if (str[0] == '-' || str[0] == '+')
		flag = 1;
	for (int i = flag; i < len; ++i)
	{
		int temp = str[i] - '0';
		num = num * 10 + temp;
	}
	if (str[0] == '-')
		num = -num;
	return num;
}

int octonary(const char* str)
{
	int len = strlen(str);
	int num = 0;
	int rec = 1;
	int flag = 0;
	if (str[0] == '-' || str[0] == '+')
		flag = 1;
	for (int i = len - 1; i > flag; --i)
	{
		num = num + (str[i] - '0') * rec;
		rec = rec * 8;
	}
	if (str[0] == '-')
		num = -num;
	return num;
}

int hex(const char* str)
{
	int len = strlen(str);
	int flag = 1;
	if (str[0] == '-' || str[0] == '+')
		flag = 2;
	int num = 0;
	int rec = 1;
	map<char, int> m;
	for (int i = 0; i <= 9; ++i)
	{
		char temp = char(i + '0');
		m[temp] = i;
	}
	for (int i = 0; i < 6; ++i)
	{
		char temp = char('a' + i);
		m[temp] = 10 + i;
		temp = char('A') + i;
		m[temp] = 10 + i;
	}
	for (int i = len - 1; i > flag; --i)
	{
		num = num + (str[i] - '0') * rec;
		rec = rec * 16;
	}
	if (str[0] == '-')
		num = -num;
	return num;
}

const char * literal(const char* str)
{
	string string1="";
	int len = strlen(str);
	int i = 0;
	while(i<len)
	{
		if(str[i] != '\\'&&i+3<len)
		{
			if(str[i+1]=='x'||str[i+1]=='X')
			{
				int temp = (str[i + 2] - '0') * 16 + (str[i + 3] - '0');
				string1.push_back(char(temp));
			}else if(str[i + 1] == '0')
			{
				int temp = (str[i + 2] - '0') * 8 + (str[i + 3] - '0');
				string1.push_back(char(temp));
			}
			i += 4;
		}else
		{
			string1.push_back(str[i]);
			++i;
		}
	}
	return string1.c_str();
}

int classify(const char * str)
{
	int len = strlen(str);
	string temp = str;
	string string1;
	if (temp[0] == '-' || temp[0] == '+')
		string1 = temp.substr(1);
	else
		string1 = temp;
	if((isdigit(string1[0])&&string1[0]!=0)||(len==1&&string1[0]==0))
	{
		int pos = string1.find_first_not_of("0123456789");
		if (pos == string::npos)
			return 10;
	}
	if(string1[0]==0)
	{
		int pos = string1.find_first_not_of("01234567");
		if (pos == string::npos)
			return 8;
	}
	if(string1[0] == 0 && (string1[1]=='x'||string1[1]=='X') )
	{
		int pos = string1.find_first_not_of("0123456789abcdefABCDEF");
		if (pos == string::npos)
			return 16;
	}
	return 0;
	
}

int handle_error(const char * str)
{
	
}

