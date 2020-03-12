#include "itoa.h"
#include <stack>
using namespace std;

int my_itoa::decimal(int num, char b[])
{
    stack<char> stack1;
    int temp = 0;
    while (num)
    {
        temp = num % 10;
        stack1.push(char(temp + '0'));
        num = num / 10;
    }
    int i = 0;
    while (!stack1.empty())
    {
        b[i++] = stack1.top();
        stack1.pop();
    }
    return i;
}

int my_itoa::hex(int num, char b[])
{
    int len = 0;
    if (num < 0)
    {
        long long comp = complent(num);
        len = dec_to_hex(comp, b);
    }
    else
        len = dec_to_hex((long long)num, b);
    return len;
}

int my_itoa::octonary(int num, char b[])
{
    int len = 0;
    if (num < 0)
    {
        long long comp = complent(num);
        len = dec_to_oct(comp, b);
    }
    else
        len = dec_to_oct((long long)num, b);
    return len;
}

int my_itoa::dec_to_hex(long long num, char b[])
{
    b[0] = '0';
    b[1] = 'X';
    stack<char> stack1;
    int temp = 0;
    while (num)
    {
        temp = num % 16;
        if (temp < 10)
            stack1.push(char(temp + '0'));
        else
            stack1.push(char(temp - 10 + 'A'));
        num = num / 16;
    }
    int i = 2;
    while (!stack1.empty())
    {
        b[i++] = stack1.top();
        stack1.pop();
    }
    return i;
}

int my_itoa::dec_to_oct(long long num, char b[])
{
    b[0] = '0';
    stack<char> stack1;
    int temp = 0;
    while (num)
    {
        temp = num % 8;
        stack1.push(char(temp + '0'));
        num = num / 8;
    }
    int i = 1;
    while (!stack1.empty())
    {
        b[i++] = stack1.top();
        stack1.pop();
    }
    return i;
}

long long my_itoa::complent(int num)
{
    long long param = 1;
    for (int i = 0; i < 32; ++i)
    {
        param = param * 2;
    }
    return param + num;
}

char *my_itoa::itoa(int i, char b[], int base)
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
