#include <iostream>
#include <cstdio>
using namespace std;
#define min(x, y) (x) > (y) ? (y) : (x)
int n, a[1000], dp[1000][1000];
const int inf = 214748364;
int matrix_chain();
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    printf("%d\n", matrix_chain());
    system("pause");
    return 0;
}
int matrix_chain()
{
    for (int l = 2; l < n; ++l)
    {
        for (int i = 0; i < n - l; ++i)
        {
            int j = i + l;
            dp[i][j] = inf;
            for (int k = i + 1; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + a[i] * a[k] * a[j]);
            }
        }
    }
    return dp[0][n - 1];
}