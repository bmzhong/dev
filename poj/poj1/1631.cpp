#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[40004], a[40004];
const int inf = 999999;
int main()
{
    int n;
    scanf("%d", &n);
    for (int o = 0; o < n; ++o)
    {
        int p, res = 0;
        scanf("%d", &p);
        for (int i = 1; i <= p; ++i)
        {
            scanf("%d", &a[i]);
        }
        fill(dp, dp + p, inf);
        for (int i = 1; i <= p; ++i)
        {
            *lower_bound(dp, dp + p, a[i]) = a[i];
        }
        printf("%d\n", lower_bound(dp, dp + p, inf) - dp);
    }
    system("pause");
    return 0;
}