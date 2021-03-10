#include <iostream>
#include <cstdio>
using namespace std;
int n, a[10001];
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
int bubble_sort()
{
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] < a[j - 1])
            {
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
                ++cnt;
            }
        }
    }
    return cnt;
}
int main()
{
    n = read();
    for (int i = 0; i < n; ++i)
    {
        a[i] = read();
    }
    printf("%d\n", bubble_sort());
    system("pause");
    return 0;
}