#include <iostream>
#include <cstdlib>
using namespace std;
int n, m, dp[41], a[41];
int main()
{
    scanf("%d%d", &n, &m);
    int t;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &t);
        a[t] = 1;
    }
    dp[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (!a[i])
            dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("%d\n", dp[n]);
    system("pause");
    return 0;
}