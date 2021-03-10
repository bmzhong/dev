#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#pragma GCC optimize(2)
int m, n;
bool dp[100001];
int a[102], b[102];
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 1) + (x << 3) + c - 48;
        c = getchar();
    }
    return x * f;
}

int main()
{
    while (true)
    {
        n = read();
        m = read();
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= n; ++i)
            a[i] = read();
        for (int i = 1; i <= n; ++i)
            b[i] = read();
        memset(dp, 0, sizeof(dp));
        int mins = 0, res = 0;
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            if (b[i] > m / a[i])
            {
                for (int j = a[i]; j <= m; ++j)
                {
                    dp[j] = dp[j] || dp[j - a[i]];
                }
            }
            else
            {
                mins = b[i];
                for (int k = 1; mins > 0; k <<= 1)
                {
                    if (k > mins)
                        k = mins;
                    mins -= k;
                    for (int j = m; j >= k * a[i]; --j)
                    {
                        dp[j] = dp[j] || dp[j - k * a[i]];
                    }
                }
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            res += dp[i];
        }
        printf("%d\n", res);
    }
    system("pause");
    return 0;
}