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
    // const char *s = "123";
    // cout << strlen(s) << endl;
    char *ch=new char[4];
     ch[0]='1';
     ch[0]='2';
     ch[0]='3';
     ch[0]='4';
    cout<<ch<<endl;
    system("pause");
    return 0;
}
