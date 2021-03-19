#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n, f[20][20], c[40][40];
int catalan1()
{
    int f[20];
    memset(f, 0, sizeof(f));
    f[0] = f[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            f[i] += f[j] * f[i - j - 1];
        }
    }
    return f[n];
}
int catalan4()
{
    for (int i = 1; i <= 2 * n; ++i)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    return c[2 * n][n] - c[2 * n][n - 1];
}
int dp()
{
    for (int j = 0; j <= n; ++j)
        f[0][j] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            if (i == j)
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    return f[n][n];
}
int dfs(int i, int j)
{
    if (f[i][j])
        return f[i][j];
    if (i == 0)
        return 1;
    if (j > 0)
        f[i][j] += dfs(i, j - 1);
    f[i][j] += dfs(i - 1, j + 1);
    return f[i][j];
}
int main()
{
    scanf("%d", &n);
    printf("%d\n", dfs(n, 0));
    printf("%d\n", catalan1());
    printf("%d\n", catalan4());
    printf("%d\n", dp());
    system("pause");
    return 0;
}