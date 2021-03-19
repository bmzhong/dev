#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, dp[1001][10000], len[1001];
void add(int x, int y, int z)
{
    len[z] = max(len[x], len[y]); //注意不要写成了max(x,y);
    for (int i = 0; i < len[z]; ++i)
    {
        dp[z][i] += dp[x][i] + dp[y][i];
        dp[z][i + 1] += dp[z][i] / 10;
        dp[z][i] %= 10;
    }
    if (dp[z][len[z]])
        ++len[z];
}
int main()
{
    scanf("%d%d", &m, &n);
    n = n - (m - 1);
    m = 1;
    dp[1][0] = 1;
    dp[2][0] = 1;
    len[1] = len[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        add(i - 2, i - 1, i);
    }
    for (int i = len[n] - 1; i >= 0; --i) //不要写成了++i;
    {
        printf("%d", dp[n][i]);
    }
    printf("\n");
    system("pause");
    return 0;
}