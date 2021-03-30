#include <iostream>
#include <cstdio>
using namespace std;
int n, m, t, g[30][30], a[30][30], x, y, x0, y0, x1, y1;
int dfs(int x, int y)
{
    if (x == x1 && y == y1)
        return 1;
    int cnt = 0;
    if (x + 1 <= n && !a[x + 1][y] && !g[x + 1][y])
    {
        a[x + 1][y] = 1;
        cnt += dfs(x + 1, y);
        a[x + 1][y] = 0;
    }
    if (x - 1 >= 1 && !a[x - 1][y] && !g[x - 1][y])
    {
        a[x - 1][y] = 1;
        cnt += dfs(x - 1, y);
        a[x - 1][y] = 0;
    }
    if (y + 1 <= m && !a[x][y + 1] && !g[x][y + 1])
    {
        a[x][y + 1] = 1;
        cnt += dfs(x, y + 1);
        a[x][y + 1] = 0;
    }
    if (y - 1 >= 1 && !a[x][y - 1] && !g[x][y - 1]) //不要写成了a[x][y-1]
    {
        a[x][y - 1] = 1;
        cnt += dfs(x, y - 1);
        a[x][y - 1] = 0;
    }
    return cnt;
}
int main()
{
    scanf("%d%d%d", &n, &m, &t);
    scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
    for (int i = 0; i < t; ++i)
    {
        scanf("%d%d", &x, &y);
        g[x][y] = 1;
    }
    a[x0][y0] = 1;//不能忘记写这句了。回溯前需要对一些变量进行赋值。
    printf("%d\n", dfs(x0, y0));
    system("pause");
    return 0;
}