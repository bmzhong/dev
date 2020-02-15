#include <iostream>
#include <cstdlib>

using namespace std;
int n, m, dp[51][20001], a[51], b[51];

int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 0; k <= b[i] && k * a[i] <= j; ++k)
            {
                if (dp[i - 1][j - k * a[i]] > 0 || (j - k * a[i] == 0))
                {
                    if (!dp[i][j])
                        dp[i][j] = dp[i - 1][j - k * a[i]] + k;
                    else
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - k * a[i]] + k);
                }
            }
        }
    }
    if(dp[n][m]>0)
    printf("%d\n", dp[n][m]);
    else
    printf("><\n");
    system("pause");
    return 0;
}