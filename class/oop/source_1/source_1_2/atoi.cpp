/*
 * 文件描述：
 *		   实现了atoi.h中的相关函数接口。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/04
 *
 */
#include <string.h>
#include <string>
#include "atoi.h"
using namespace std;

#define max_int 2147483647
#define min_int -2147483648
//将str转换成十进制数
long long my_atoi::decimal(const char *str)
{
	int len = strlen(str);
	long long num = 0;
	for (int i = 0; i < len; ++i)//从前往后扫描，一次转换
	{
		int temp = str[i] - '0';
		num = num * 10 + temp;
	}
	return num;
}
//将str转换为八进制数
long long my_atoi::octonary(const char *str)
{
	int len = strlen(str);
	long long num = 0;
	int rec = 1;
	for (int i = len - 1; i > 0; --i)
	{
		num = num + (str[i] - '0') * rec;
		rec = rec * 8;
	}
	return num;
}
//将str转换为十六进制数
long long my_atoi::hex(const char *str)
{
	int len = strlen(str);
	long long num = 0;
	int rec = 1;
	for (int i = len - 1; i > 1; --i)
	{
		if (isdigit(str[i]))
			num = num + (str[i] - '0') * rec;
		else
			num = num + (str[i] - 'a' + 10) * rec;
		rec = rec * 16;
	}
	return num;
}
//去除空白符，处理正负号，处理转义字符
string my_atoi::tranform(const char *str, int *symbol)
{
	string string1 = "";
	int len = strlen(str);
	int i = 0;
	while (true)//去除空白符
	{
		if (str[i] >= 33)
			break;
		else
			++i;
	}
	//处理正负号
	if (str[i] == '+')
	{
		*symbol = 1;
		++i;
	}
	else if (str[i] == '-')
	{
		*symbol = -1;
		++i;
	}
	else
	{
		*symbol = 1;
	}
	while (i < len)
	{
		if (str[i] == '\\' && i + 3 < len)
		{//将\x12这类字符转成相应的十进制字符
			if (str[i + 1] == 'x' || str[i + 1] == 'X')
			{
				int temp = (str[i + 2] - '0') * 16 + (str[i + 3] - '0');
				string1.push_back(char(temp));
			}
			else if (str[i + 1] == '0')
			{
				int temp = (str[i + 2] - '0') * 8 + (str[i + 3] - '0');
				string1.push_back(char(temp));
			}
			i += 4;
		}
		else
		{
			if (isalpha(str[i]) && str[i] >= 65 && str[i] <= 90)
				string1.push_back(char(str[i] + 32));
			else
				string1.push_back(str[i]);
			++i;
		}
	}
	return string1;
}
//判断str属于哪一类
my_atoi::Classify my_atoi::classify(const char *str)
{
	int len = strlen(str);
	string temp = str;
	string string1;
	if (temp[0] == '-' || temp[0] == '+')
		string1 = temp.substr(1);
	else
		string1 = temp;
	if (len > 10)
		return Error;
	if ((isdigit(string1[0]) && string1[0] != '0') || (len == 1 && string1[0] == '0'))
	{
		int pos = string1.find_first_not_of("0123456789");
		if (pos == string::npos)
			return Dec;//十进制整数字面量
	}
	if (string1[0] == '0')
	{
		int pos = string1.find_first_not_of("01234567");
		if (pos == string::npos)
			return Oct;//八进制整数字面量
	}
	if (string1[0] == '0' && string1[1] == 'x')
	{
		int pos = string1.find_first_not_of("0123456789abcdef", 2);
		if (pos == string::npos)
			return Hex;//十六进制整数字面量
	}
	return Error;
}
//取出e后面的数字
long long my_atoi::fetch_power(string string1, int pos)
{
	int pos1 = string1.find_first_not_of("0123456789", pos + 1);//去下pos后面的字符串
	if (pos1 != string::npos)
	{
		string string3 = string1.substr(pos + 2, pos1 - (pos + 2));
		if (string3.length() > 0 && string3[0] != '0')
			return decimal(string3.c_str());//将其转换成十进制数
	}
	else//e后面全部是数字
	{
		string string3 = string1.substr(pos + 1);
		if (string3.length() > 0)
			return decimal(string3.c_str());
	}

	return 0;
}
//处理错误情况
long long my_atoi::handle_error(const char *str)
{
	int len = strlen(str);
	long long num = 0;
	if (len == 0)
		return 0;//str长度为0
	if (!isdigit(str[0]))
		return 0;
	string string1 = str;
	int pos = string1.find_first_not_of("01236456789");
	string string2 = string1.substr(0, pos);
	if (string2.length() == 0 || string2[0] == '0')
		return 0;//如果以字母开头或者首字符为0则返回0.
	else
		num = decimal(string2.c_str());//直接将第一个字母前的数字串以十进制数字返回
	int exp = 0;
	if (pos != string::npos)
	{//获取指数
		if ((string1[pos] == '+' || string1[pos] == '-') && pos + 1 < len && string1[pos + 1] == 'e')
			exp = fetch_power(string1, pos + 1);
		else if (string1[pos] == 'e')
			exp = fetch_power(string1, pos);
	}
	if (exp)
	{
		int power = 1 ;
		for (int i = 0; i < exp; ++i)
		{
			power = power * 10;
		}//计算10^exp
		if (pos+1<len && string1[pos+1] == '+')
		{
			if (num * power <= max_int && num * power >= min_int)
				return num * power;
			else
				return num;
		}
		else if (pos+1<len && string1[pos+1] == '-')
		{
			if (num / power == 0)
				return num;
			else
				return num / power;
		}
	}
	if (num > max_int)
		return max_int;
	if (num < min_int)
		return min_int;
	return num;
}

int my_atoi::atoi(const char *str)
{
	int symbol = 1;
	long long num = 0;
	string string1 = tranform(str, &symbol);//预处理
	const char *ch = string1.c_str();
	Classify flag = classify(ch);//分类
	switch (flag)
	{
	case Dec:
		num = decimal(ch);
		break;
	case Oct:
		num = octonary(ch);
		break;
	case Hex:
		num = hex(ch);
		break;
	case Error:
		num = handle_error(ch);
		break;
	default:
		num = 0;
	}
	if (symbol == -1)
		num = -num;
	if (num > max_int)
		return max_int;
	if (num < min_int)
		return min_int;
	return num;
}
