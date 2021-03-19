#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int n, a[2][11], acid=1, ans = 2147483647, bitter=0;
void dfs(int k)
{
    if (k == n)
    {
        if (acid != 1 && bitter != 0)
        {
            ans = min(ans, abs(acid - bitter));
        }
    }
    else
    {
        dfs(k + 1);
        acid *= a[0][k];
        bitter += a[1][k];
        dfs(k + 1);
        acid /= a[0][k];
        bitter -= a[1][k];
    }
}
int main()
{
    n = read();
    for (int i = 0; i < n; ++i)
    {
        a[0][i] = read();
        a[1][i] = read();
    }
    dfs(0);
    printf("%d\n", ans);
    system("pause");
    return 0;
}