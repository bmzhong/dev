#include <iostream>
#include <cstdio>
using namespace std;
int n, m, a[101][101], dp[101][101], res = 0;
inline int min(int x, int y, int z)
{
    int t = x > y ? y : x;
    return t > z ? z : t;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (i & 1)
        {
            dp[i][0] = 1;
            res = res > dp[i][0] ? res : dp[i][0];
        }
        for (int j = 1; j < m; ++j)
        {
            if (a[i][j])
            {
                if (!i)
                    dp[i][j] = 1;
                else
                {
                    int x = dp[i - 1][j];
                    int y = dp[i][j - 1];
                    int z = dp[i - 1][j - 1];
                    dp[i][j] = min(x, y, z) + 1;
                }
                res = res > dp[i][j] ? res : dp[i][j];
            }
        }
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}