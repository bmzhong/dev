#include <iostream>
#include <algorithm>
using namespace std;
int dp[51][51][13], a[51][51], n, m, o, maxs;
int main()
{
    cin >> n >> m >> o;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j][0] = 1;
            for (int k = 1; k <= o; ++k)
            {
                dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k];
                if (a[i][j] > maxs)
                {
                    dp[i][j][k] += dp[i][j - 1][k - 1] + dp[i - 1][j][k - 1];
                    maxs = max(maxs, a[i][j]);
                }
            }
        }
    }
}