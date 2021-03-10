#include <iostream>
#include <cstdio>
using namespace std;
#define min(x, y) (x) > (y) ? (y) : (x)
int N, P, Q, A[101], dp[101][101];
int solve();
int main()
{
    scanf("%d", &N);
    for (int x = 1; x <= N; ++x)
    {
        scanf("%d%d", &P, &Q);
        for (int i = 1; i <= Q; ++i)
        {
            scanf("%d", &A[i]);
        }
        int res = solve();
        printf("Case #%d: %d\n", x, res);
    }
    system("pause");
    return 0;
}
int solve()
{
    A[0] = 0;
    A[Q + 1] = P + 1;
    for (int i = 0; i <= Q; ++i)
    {
        dp[i][i + 1] = 0;
    }
    for (int w = 2; w <= Q + 1; ++w)
    {
        for (int i = 0; i + w <= Q + 1; ++i)
        {
            int j = i + w, t = 2147483647;
            for (int k = i + 1; k < j; ++k)
            {
                t = min(t, dp[i][k] + dp[k][j]);
            }
            dp[i][j] = t + A[j] - A[i] - 2;
        }
    }
    return dp[0][Q + 1];
}
