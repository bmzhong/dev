/*
 * 文件描述：
 *		   实现了itoa.h中的相关函数接口。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/04
 *
 */
#include "itoa.h"
#include <stack>
using namespace std;
//将num以十进制储存在b中
int my_itoa::decimal(int num1, char b[])
{
    long long num = num1;//防止-2147483648这种情况
    stack<char> stack1;
    int temp = 0;
    int i = 0;
    if (num < 0)
    {
        if (num == -2147483648)
            num = long(num);
        num = -num;//取num的绝对值
        b[i] = '-';//负数 b[0]存放负号
        ++i;
    }
    while (num)
    {
        temp = num % 10;
        stack1.push(char(temp + '0'));
        num = num / 10;
    }

    while (!stack1.empty())
    {
        b[i++] = stack1.top();
        stack1.pop();
    }
    return i;//返回b的有效长度
}
//取补码，然后将num以十六进制储存在b中
int my_itoa::hex(int num, char b[])
{
    int len = 0;
    if (num < 0)
    {//如果num是负数则取num的补码
        long long comp = complent(num);
        len = dec_to_hex(comp, b);//将num以十六进制储存在b中
    }
    else
        len = dec_to_hex((long long)num, b);
    return len;//返回b的有效长度
}
//取补码，然后将num以八进制储存在b中
int my_itoa::octonary(int num, char b[])
{
    int len = 0;
    if (num < 0)
    {//如果num是负数则取num的补码
        long long comp = complent(num);
        len = dec_to_oct(comp, b);//将num以八进制储存在b中
    }
    else
        len = dec_to_oct((long long)num, b);
    return len;//返回b的有效长度
}
//将正十进制数num以十六进制储存在b中
int my_itoa::dec_to_hex(long long num, char b[])
{
    b[0] = '0';
    b[1] = 'X';//b以0X开头
    stack<char> stack1;
    int temp = 0;
    while (num)//将num转换成十六进制
    {
        temp = num % 16;
        if (temp < 10)
            stack1.push(char(temp + '0'));
        else
            stack1.push(char(temp - 10 + 'A'));
        num = num / 16;
    }
    int i = 2;
    while (!stack1.empty())//将十六进制字符放到b中
    {
        b[i++] = stack1.top();
        stack1.pop();
    }
    return i;
}
//将正十进制数num以八进制储存在b中
int my_itoa::dec_to_oct(long long num, char b[])
{
    b[0] = '0';//b以0开头
    stack<char> stack1;
    int temp = 0;
    while (num)//将num转换成八进制
    {
        temp = num % 8;
        stack1.push(char(temp + '0'));
        num = num / 8;
    }
    int i = 1;
    while (!stack1.empty())//将八进制字符放到b中
    {
        b[i++] = stack1.top();
        stack1.pop();
    }
    return i;//返回b的有效长度
}
//取负数num的补码
long long my_itoa::complent(int num)
{
    long long param = 1;
    for (int i = 0; i < 32; ++i)//计算2^32
    {
        param = param * 2;
    }
    return param + num;//返回补码
}
//根据基数base决定调用哪个转换函数
char *my_itoa::itoa(int i, char b[], int base = 10)
{
    int len = 0;
    if (base == 10)
        len = my_itoa::decimal(i, b);
    else if (base == 16)
        len = my_itoa::hex(i, b);
    else if (base == 8)
        len = my_itoa::octonary(i, b);
    b[len] = '\0';
    return b;
}
