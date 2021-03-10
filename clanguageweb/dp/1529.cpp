#include <iostream>
using namespace std;
int n, m, a[101], dp[101][101], res = 0;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= a[1]; ++i)
    {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 0; k <= a[i]&&k<=j; ++k)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000007;
            }
        }
    }
    printf("%d\n", dp[n][m]);
    system("pause");
    return 0;
}