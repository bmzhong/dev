#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int dp[100000], a[100000], b[100000], m, n;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = m; j >= a[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - a[i]]+ b[i]);
        }
    }
    printf("%d\n", dp[m]);
    system("pause");
    return 0;
}