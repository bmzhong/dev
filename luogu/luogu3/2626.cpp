#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int n, h, a[20001];
int main()
{
    n = read();
    h = read();
    for (int i = 0; i < n; ++i)
    {
        a[i] = read();
    }
    sort(a, a + n, greater<int>());
    int x = 0, i = 0;
    while (i < n && x < h)
    {
        x += a[i];
        ++i;
    }
    printf("%d\n", i);
    system("pause");
    return 0;
}