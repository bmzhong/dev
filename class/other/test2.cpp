#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
// class B;
// class B{
// public:
//     B(){cout<<"B"<<endl;}
//     ~B(){cout<<"-B"<<endl;}
// };
class A
{
public:
    int re, im;
    A(int a) : re(a)
    {
        cout << "hello" << endl;
    }
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "-A" << endl;
    }
};
// A aa;
// A func(A &b)
// {
//     return b;
// }

void f2()
{
    throw "f2 error";
    cout << "f2" << endl;
}

void f1()
{
    f2();
    cout << "f1" << endl;
}
int main()
{
    // B b;
    // B b1=func(b);
    // A a;
    // a = 3;
    // A c=func(aa);
    // char *ch=new char[10];
    // ch[0]='1';
    // ch[1]='2';
    // ch[2]='.';
    // ch[3]='2';
    // ch[4]='\0';
    // ch[5]='9';
    // cout<<atof(ch)<<endl;
    // delete ch;
    // enum T{
    //     token='+'
    // };
    // string str;
    // T a=token;
    // char = token;
    // char ch[10] = "12123";
    // string str = "aaa";
    // str += ch;
    // const char *s = "123";
    // pair<int, int> p = make_pair(1, 2);
    // cout << strlen(s) << endl;
    try
    {
        f1();
         cout<<"main"<<endl;
    }
    catch(const char *msg)
    {
        cout<<msg<<endl;
        
    }
   
    
    system("pause");
    return 0;
}
