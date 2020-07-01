#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int m, n, tile[16][16], flip[16][16], opt[16][16];
const int dx[5] = {-1, 0, 0, 0, 1}, dy[5] = {0, -1, 0, 1, 0};
void solve();
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &tile[i][j]);
        }
    }
    solve();
    system("pause");
    return 0;
}
int get(int x, int y)
{
    int c = tile[x][y];
    for (int i = 0; i < 5; ++i)
    {
        int x2 = x + dx[i], y2 = y + dy[i];
        if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n)
            c += flip[x2][y2];
    }
    return c % 2;
}
int calcu()
{
    for (int i = 1; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (get(i - 1, j) != 0)
            {
                flip[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (get(m - 1, i) != 0)
            return -1;
    }
    int res = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            res += flip[i][j];
        }
    }
    return res;
}
void solve()
{
    int res = 2147483647;
    for (int i = 0; i < 1 << n; ++i)
    {
        memset(flip, 0, sizeof(flip));
        for (int j = 0; j < n; ++j)
        {
            flip[0][n - j - 1] = i >> j & 1;
        }
        int num = calcu();
        if (num >= 0 && num < res)
        {
            res = num;
            memcpy(opt, flip, sizeof(flip));
        }
    }

    if (res == 2147483647)
        printf("IMPOSSIBLE\n");
    else
    {
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                printf("%d%c", opt[i][j], j == n - 1 ? '\n' : ' ');
            }
        }
    }
}