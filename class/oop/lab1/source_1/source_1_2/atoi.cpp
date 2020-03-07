#include <map>
#include <string.h>
#include <string>
#include <atoi.h>
using namespace std;

#define max_int 2147483647
#define min_int -2147483648

int decimal(const char *str)
{
	int len = strlen(str);
	int num = 0;
	for (int i = 0; i < len; ++i)
	{
		int temp = str[i] - '0';
		num = num * 10 + temp;
	}
	return num;
}

int octonary(const char *str)
{
	int len = strlen(str);
	int num = 0;
	int rec = 1;
	for (int i = len - 1; i > 0; --i)
	{
		num = num + (str[i] - '0') * rec;
		rec = rec * 8;
	}
	return num;
}

int hex(const char *str)
{
	int len = strlen(str);
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
	}
	for (int i = len - 1; i > 1; --i)
	{
		num = num + (str[i] - '0') * rec;
		rec = rec * 16;
	}
	return num;
}

const char *tranform(const char *str, int *symbol)
{
	string string1 = "";
	int len = strlen(str);
	int i = 0;
	while (true)
	{
		if (str[i] >= 33)
			break;
		else
			++i;
	}
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
		{
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
	return string1.c_str();
}

Classify classify(const char *str)
{
	int len = strlen(str);
	string temp = str;
	string string1;
	if (temp[0] == '-' || temp[0] == '+')
		string1 = temp.substr(1);
	else
		string1 = temp;
	if ((isdigit(string1[0]) && string1[0] != 0) || (len == 1 && string1[0] == 0))
	{
		int pos = string1.find_first_not_of("0123456789");
		if (pos == string::npos)
			return Dec;
	}
	if (string1[0] == 0)
	{
		int pos = string1.find_first_not_of("01234567");
		if (pos == string::npos)
			return Oct;
	}
	if (string1[0] == 0 && string1[1] == 'x')
	{
		int pos = string1.find_first_not_of("0123456789abcdef");
		if (pos == string::npos)
			return Hex;
	}
	return Error;
}

int fetch_power(string string1, int pos)
{
	int pos1 = string1.find_first_not_of("0123456789", pos + 1);
	if (pos1 != string::npos)
	{
		string string3 = string1.substr(pos + 2, pos1 - (pos + 2));
		if (string3.length() > 0 && string3[0] != '0')
		{
			return decimal(string3.c_str());
		}
	}
	return 0;
}

int handle_error(const char *str)
{
	int len = strlen(str);
	long long num = 0;
	if (len == 0)
		return 0;
	if (!isdigit(str[0]))
		return 0;
	string string1 = str;
	int pos = string1.find_first_not_of("01236456789");
	string string2 = string1.substr(0, pos);
	if (string2.length() == 0 || string2[0] == '0')
		return 0;
	else
		num = decimal(string2.c_str());
	int exp = 0;
	if (pos != string::npos)
	{
		if ((string1[pos] == '+' || string1[pos] == '-') && pos + 1 < len && string1[pos + 1] == 'e')

			exp = fetch_power(string1, pos + 1);
		else if (string1[pos] == 'e')

			exp = fetch_power(string1, pos);
	}
	if (exp)
	{
		if (string1[pos] == '+' || string1[pos] == 'e')
		{
			if (num * exp <= max_int && num * exp >= min_int)
				return num * exp;
			else
				return num;
		}
		else if (string1[pos] == '-')
		{
			if (num / exp == 0)
				return num;
			else
				return num / exp;
		}
	}
	if (num > max_int)
		return max_int;
	if (num < min_int)
		return min_int;
	return num;
}

int atoi(const char *str)
{
	int symbol = 1;
	const char *ch = tranform(str, &symbol);
	Classify flag = classify(ch);
	switch (flag)
	{
	case Dec:
		return decimal(ch);
	case Oct:
		return octonary(ch);
	case Hex:
		return hex(ch);
	case Error:
		return handle_error(ch);
	default:
		return 0;
	}
}