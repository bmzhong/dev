#include <iostream>
#include <stdio.h>
using namespace std;
const long long inf = 9999999999998;
long long dp[1001][1001], sum[1001];
int n, a[1001];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int p = 1; p < n; ++p)
    {
        for (int i = 1; i <= n - p; ++i)
        {
            int j = i + p;
            for (int k = i; k < j; ++k)
            {
                long long q1 = dp[i][j];
                long long q2 = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1];
                if (!q1)
                    dp[i][j] = q2;
                else
                    dp[i][j] = q1 > q2 ? q2 : q1;
            }
        }
    }
    printf("%lld\n", dp[1][n]);
    system("pause");
    return 0;
}