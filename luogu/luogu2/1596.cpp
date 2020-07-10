#include <iostream>
#include <cstdio>
using namespace std;
char pond[100][100];
int m, n, res;
void solve();
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> pond[i][j];
        }
    }
    solve();
    system("pause");
    return 0;
}

void dfs(int x, int y)
{
    pond[x][y] = '.';
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && pond[nx][ny] == 'W')
            {
                dfs(nx, ny);
            }
        }
    }
}
void solve()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (pond[i][j] == 'W')
            {
                dfs(i, j);
                ++res;
            }
        }
    }
    printf("%d\n", res);
}