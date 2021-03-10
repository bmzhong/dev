#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m, a, b, p;
int t[11], d[31][31];
double dp[1024][31];
const double inf = 2147483647.0;
void solve();
int main()
{
    while (true)
    {
        scanf("%d%d%d%d%d", &n, &m, &p, &a, &b);
        if (!n && !m && !p && !a && !b)
            return 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &t[i]);
        }
        int x, y, z;
        memset(d, -1, sizeof(d));
        for (int i = 0; i < p; ++i)
        {
            scanf("%d%d%d", &x, &y, &z);
            d[x - 1][y - 1] = z;
            d[y - 1][x - 1] = z;
        }
        solve();
    }
    system("pause");
    return 0;
}
void solve()
{
    for (int i = 0; i < 1 << n; ++i)
    {
        fill(dp[i], dp[i] + m, inf);
    }
    dp[(1 << n) - 1][a - 1] = 0;
    double res = inf;
    for (int S = (1 << n) - 1; S >= 0; --S)
    {
        res = min(res, dp[S][b - 1]);
        for (int u = 0; u < m; ++u)
        {
            for (int i = 0; i < n; ++i)
            {
                if (S >> i & 1)
                {
                    for (int v = 0; v < m; ++v)
                    {
                        if (d[u][v] >= 0)
                        {
                            dp[S ^ 1 << i][v] = min(dp[S ^ 1 << i][v], dp[S][u] + (double)d[u][v] / t[i]);
                        }
                    }
                }
            }
        }
    }
    if (res == inf)
        printf("Impossible\n");
    else
        printf("%.3lf\n", res);
}