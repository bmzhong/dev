/*
 * 文件描述：
 *		   定义了实现itoa功能的相关函数接口。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/03/04
 *
 */

#ifndef _my_itoa
#define _my_itoa

namespace my_itoa
{

int decimal(int num1, char b[]);//将num以十进制储存在b中

int hex(int num, char b[]);//取(负数)补码，然后调用dec_to_hex函数将num以十六进制储存在b中

int octonary(int num, char b[]);//取(负数)补码，然后调用dec_to_oct函数将num以八进制储存在b中

int dec_to_hex(long long num,char b[]);//将正十进制数num以十六进制储存在b中

int dec_to_oct(long long num,char b[]);//将正十进制数num以八进制储存在b中

long long complent(int num);//取负数num的补码

char *itoa(int i, char b[], int base );//根据基数base决定调用哪个转换函数

} // namespace my_itoa

#endif