#include <string.h>
#include<iostream>
#include <stdio.h>
const long long inf = 100000000000001;
long long dp[1003][1003], a[1003], n;
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            dp[i][j]=inf;
        }
    }
    for (int i = 1; i <= n + 1; ++i)
    {
        dp[i][i] = 0;
        scanf("%d", &a[i]);
    }
    for (int p = 1; p < n; ++p)
    {
        for (int i = 1; i <= n - p; ++i)
        {
            int j = i + p;
            for (int k = i; k < j; ++k)
            {
                long long  q1 = dp[i][j];
                long long  q2 = dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j + 1];
                dp[i][j] = q1 > q2 ? q2 : q1;
            }
        }
    }
    printf("%lld\n", dp[1][n]);
    system("pause");
    return 0;
}