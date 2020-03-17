#include <stdio.h>
#include <iostream>
#define max(a, b) (a) > (b) ? (a) : (b)
int dp[30001];
int main()
{
    int N, m, v, p;
    scanf("%d%d", &N, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &v, &p);
        for (int j = N; j >= v; --j)
        {
            dp[j] = max(dp[j], dp[j - v] + v * p);
        }
    }
    printf("%d\n", dp[N]);
    system("pause");
    return 0;
}
