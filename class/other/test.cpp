#include <iostream>
#include <cstdlib>
#include <string.h>
using namespace std;
void func()
{
    char a = '1';
    char *b = &a;
    cout << b << endl;
}

template <class T>
void func(T s)
{
    cout << sizeof(T) << endl;
}

int main()
{
    // int a = 12;
    // int *b = &a;
    // printf("%p", b);
    // func();
    // const char *s = "123";
    // cout << strlen(s) << endl;
    // char *ch=new char[4];
    //  ch[0]='1';
    //  ch[0]='2';
    //  ch[0]='3';
    //  ch[0]='4';
    // cout<<ch<<endl;
    // char* n=new char[100];
    // char s[9] = "123";
    // cout << sizeof(n) << endl;
    // func(1.2);
    int a[10];
    memset(a, 10000, 10);
    for (int i = 0; i < 10; ++i)
    {
        cout<<a[i]<<endl;
    }
    system("pause");
    return 0;
}
