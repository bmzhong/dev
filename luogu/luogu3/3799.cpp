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
int n;
long long ans = 0, a[10001];
int mod = 1000000007;
int main()
{
    n = read();
    for (int i = 0; i < n; ++i)
    {
        int temp = read();
        a[temp]++;
    }
    for (int i = 1; i <= 5000; ++i)
    {
        if (a[i] >= 2)
        {
            for (int j = 1; j < i / 2; ++j)
            {
                if (a[j] != 0 && a[i - j] != 0)
                    ans = (ans + a[j] * a[i - j] * (a[i] * (a[i] - 1)) / 2) % mod;
            }
            if (a[i / 2])
            {
                if (i % 2)
                    ans = (ans + a[i / 2] * a[i - i / 2] * (a[i] * (a[i] - 1)) / 2) % mod;
                else
                    ans = (ans + (a[i / 2] * (a[i / 2] - 1) / 2) * (a[i] * (a[i] - 1)) / 2) % mod;
            }
            if (a[0] && a[i] >= 3)
                ans = (ans + a[i] * (a[i] - 1) * (a[i] - 2) * a[0]) % mod;
        }
    }
    printf("%lld\n", ans);
    system("pause");
    return 0;
}
