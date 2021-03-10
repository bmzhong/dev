/*
 * 文件描述：
 *		   定义了实现atoi功能的相关函数接口。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/04
 *
 */

#ifndef _atoi
#define _atoi

#include <string>

namespace my_atoi
{

enum Classify
{
	Oct = 8, //八进制整数字面量
	Dec = 10,//十进制整数字面量
	Hex = 16,//十六进制整数字面量
	Error = 0//非法的字符串
};

long long decimal(const char *str);//将str转换成十进制数

long long octonary(const char *str);//将str转换为八进制数

long long hex(const char *str);//将str转换为十六进制数

std::string tranform(const char *str, int *symbol);//去除空白符，处理正负号，处理转义字符

Classify classify(const char *str);//判断str属于哪一类

long long fetch_power(std::string string1, int pos);//取出e后面的数字

long long handle_error(const char *str);//处理错误情况

int atoi(const char *str);//调用上述函数

} // namespace my_atoi

#endif