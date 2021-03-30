#include <iostream>
#include <cstdio>
using namespace std;
int n, a[14][14], cnt = 0;
bool check(int r, int c)
{
    for (int i = 1; i <= r; ++i)
    {
        if (a[i][c])
            return false;
    }
    for (int j = 1; j <= n; ++j)
    {
        if (a[r][j])
            return false;
    }
    int i = r, j = c;
    while (i >= 1 && j >= 1)
    {
        if (a[i][j])
            return false;
        --i;
        --j;
    }
    i = r, j = c;
    while (i >= 1 && j <= n)
    {
        if (a[i][j])
            return false;
        --i;
        ++j;
    }
    return true;
}
void dfs(int r)
{
    if (r == n + 1)
    {
        ++cnt;
        if (cnt >= 4)
            return;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (a[i][j])
                    printf("%d%c", j, i == n ? '\n' : ' ');
            }
        }
    }
    for (int j = 1; j <= n; ++j)
    {
        if (check(r, j))
        {
            a[r][j] = 1;
            dfs(r + 1);
            a[r][j] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    printf("%d\n", cnt);
    system("pause");
    return 0;
}
