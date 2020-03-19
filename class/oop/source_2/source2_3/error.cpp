#include"error.h"
#include<cstdarg>
#include<cstring>
#include<iostream>
using namespace std;
void Error::error(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    int len = strlen(format);
    int pos = 0;//位置下标
    while (pos < len)
    {
        //如果这个位置为%，下一个位置为's','c','d'中的一种，则获取参数。
        if (format[pos] == '%' && pos + 1 < len && (format[pos + 1] == 's' || format[pos + 1] == 'c' || format[pos + 1] == 'd'))
        {
            if (format[pos + 1] == 's')
            {
                const char *temp = va_arg(ap, const char *);
                cout << temp;
            }
            if (format[pos + 1] == 'c')
            {
                int temp = va_arg(ap, int);
                cout << char(temp);
            }
            if (format[pos + 1] == 'd')
            {
                int temp = va_arg(ap, int);
                cout << temp;
            }
            pos += 2;//跳过%d('s','c');
        }
        else
        {
            //不是特殊格式字符，原样输出
            cout << format[pos];
            ++pos;
        }
    }
    va_end(ap);
}