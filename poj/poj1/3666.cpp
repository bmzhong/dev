#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const long long inf = 999999999999999;
long long dp[2001][2001];
int a[2001], b[2001], n;
long long my_abs(long long a)
{
    return a > 0 ? a : -a;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i)
    {
        long long mins = dp[i - 1][1];
        for (int j = 1; j <= n; ++j)
        {
            mins = min(mins, dp[i - 1][j]);
            dp[i][j] = my_abs(a[i] - b[j]) + mins;
        }
    }
    long long ans = dp[n][1];
    for (int i = 1; i <= n; ++i)
    {
        ans = min(ans, dp[n][i]);
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}