#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int t, w, ans, dp[1005][35], a[1005];
int main()
{
    scanf("%d%d", &t, &w);
    for (int i = 1; i <= t; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= t; ++i)
    {
        dp[i][0] = dp[i-1][0]+2 - a[i];
        for (int j = 1; j <= w; ++j)
        {
            if (j & 1)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i] - 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + 2 - a[i];
        }
    }
    for (int i = 0; i <= w; ++i)
    {
        ans = max(ans, dp[t][i]);
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}