#include <iostream>
using namespace std;
int func(int n);
int a[60] = {0};
int main()
{
    int n;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    for (int i = 4; i < 55; ++i)
    {
        a[i] = a[i - 1] + a[i - 3];
    }
    while (scanf("%d", &n) && n != 0)
    {
        printf("%d\n", a[n]);
    }
    system("pause");
    return 0;
}