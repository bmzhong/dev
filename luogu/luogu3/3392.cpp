#include <iostream>
#include <cstdio>
using namespace std;
int n, m, res = 2147483647;
struct A
{
    int w = 0, b = 0, r = 0;
};
A a[51];
char ch;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf(" %c", &ch);
            if (ch == 'W')
                a[i].w++;
            else if (ch == 'B')
                a[i].b++;
            else
                a[i].r++;
        }
    }
    for (int i = 2; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int temp = 0;
            for (int k = 1; k < i; ++k)
            {
                temp += a[k].b + a[k].r;
            }
            for (int k = i; k <= j; ++k)
            {
                temp += a[k].r + a[k].w;
            }
            for (int k = j + 1; k <= n; ++k)
            {
                temp += a[k].b + a[k].w;
            }
            if (res > temp)
                res = temp;
        }
    }
    // res += a[1].b + a[1].r + a[n].b + a[n].w;
    printf("%d\n",res);
    system("pause");
    return 0;
}