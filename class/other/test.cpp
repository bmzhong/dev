#include <iostream>
#include <cstdlib>
#include<string.h>
using namespace std;
void func()
{
    char a = '1';
    char *b = &a;
    cout << b << endl;
}
int main()
{
    // int a = 12;
    // int *b = &a;
    // printf("%p", b);
    // func();
    const char *s = "123";
    cout << strlen(s) << endl;
    system("pause");
    return 0;
}
