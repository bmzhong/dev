#ifndef _my_itoa
#define _my_itoa

namespace my_itoa
{

int decimal(int num, char b[]);

int hex(int num, char b[]);

int octonary(int num, char b[]);

int dec_to_hex(long long num,char b[]);

int dec_to_oct(long long num,char b[]);

long long complent(int num);

char *itoa(int i, char b[], int base );

} // namespace my_itoa

#endif