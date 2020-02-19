#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int inf = 1 << 20;
int dp[200001], n, s[104], f[101], res;
int main()
{
    for(int i=0;i<=200000;++i){
        dp[i]=-inf;
    }
    dp[100000] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &s[i], &f[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] > 0)
        {
            for (int j = 200000; j >= s[i]; --j)
            {
                if (dp[j - s[i]] > -inf)
                    dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
            }
        }
        else
        {
            for (int j = s[i]; j-s[i] <= 200000; ++j)
            {
                if (dp[j - s[i]] > -inf)
                {
                    dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
                }
            }
        }
    }
    for (int i = 100000; i <= 200000; ++i)
    {
        if (dp[i] > 0)
            res = max(res, dp[i] + i - 100000);
    }
    printf("%d\n",res);
    system("pause");
    return 0;
}