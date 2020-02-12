#include <iostream>
#include <cstdio>
using namespace std;
const int mod = 1000000;
int t, a, s, b, temp, dp[1001][10001], mp[1001];
int main()
{
    scanf("%d%d%d%d", &t, &a, &s, &b);
    for (int i = 1; i <= a; ++i)
    {
        scanf("%d", &temp);
        ++mp[temp];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= t; ++i)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= b; ++j)
        {
            if (j - mp[i] - 1 >= 0)
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - mp[i] - 1] + mod) % mod;
            else
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + mod) % mod;
        }
    }
    int res = 0;
    for (int i = s; i <= b; ++i)
    {
        res = (res + dp[t][i] + mod) % mod;
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}
