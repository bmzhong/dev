#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[102][102];
int main()
{
    int T, n;
    scanf("%d", &T);
    for (int o = 0; o < T; ++o)
    {
        memset(dp, 0, sizeof(dp));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                scanf("%d", &dp[i][j]);
            }
        }
        for (int i = n - 1; i >= 1; --i)
        {
            for (int j = 1; j <= i; ++j)
            {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j];
            }
        }
        printf("%d\n",dp[1][1]);
    }
    system("pause");
    return 0;
}