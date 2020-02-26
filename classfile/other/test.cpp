#include <iostream>
using namespace std;
void func()
{
    char a='1';
    char *b = &a;
    cout<<b<<endl;
}
int main()
{
    // int a = 12;
    // int *b = &a;
    // printf("%p", b);
    func();
    system("pause");
    return 0;
}
