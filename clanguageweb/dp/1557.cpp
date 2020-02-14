#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 999999;
int dp[1001], a[1001], n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int res=0;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        for (int j = 1; j < i; ++j)
        {
            if (a[j] <= a[i])
                dp[i] = max(dp[j]+1, dp[i]);
        }
        res=max(res,dp[i]);
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}