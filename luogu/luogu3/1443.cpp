#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
struct A
{
    int x, y;
    A(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};
int n, m, a[402][402], h[402][402], x0, y0, cnt;
queue<A> que;
void bfs(int x, int y)
{
    if (!h[x][y])
        h[x][y] = cnt;
    else
        return;
}
int main()
{
    scanf("%d%d%d%d", &n, &m, &x0, &y0);
    que.push(A(x0, y0));
    while (!que.empty())
    {
        A u = que.front();
        que.pop();
        int x = u.x, y = u.y;
        if (x + 2 <= n && y - 1 >= 1 && !a[x + 2][y - 1])
        {
            a[x + 2][y - 1] = a[x][y] + 1;
            que.push(A(x + 2, y - 1));
        }
        if (x + 2 <= n && y + 1 <= m && !a[x + 2][y + 1])
        {
            a[x + 2][y + 1] = a[x][y] + 1;
            que.push(A(x + 2, y + 1));
        }
        if (x - 2 >= 1 && y + 1 <= m && !a[x - 2][y + 1])
        {
            a[x - 2][y + 1] = a[x][y] + 1;
            que.push(A(x - 2, y + 1));
        }
        if (x - 2 >= 1 && y - 1 >= 1 && !a[x - 2][y - 1])
        {
            a[x - 2][y - 1] = a[x][y] + 1;
            que.push(A(x - 2, y - 1));
        }
        if (x + 1 <= n && y - 2 >= 1 && !a[x + 1][y - 2])
        {
            a[x + 1][y - 2] = a[x][y] + 1;
            que.push(A(x + 1, y - 2));
        }
        if (x + 1 <= n && y + 2 <= m && !a[x + 1][y + 2])
        {
            a[x + 1][y + 2] = a[x][y] + 1;
            que.push(A(x + 1, y + 2));
        }
        if (x - 1 >= 1 && y + 2 <= m && !a[x - 1][y + 2])
        {
            a[x - 1][y + 2] = a[x][y] + 1;
            que.push(A(x - 1, y + 2));
        }
        if (x - 1 >= 1 && y - 2 >= 1 && !a[x - 1][y - 2])
        {
            a[x - 1][y - 2] = a[x][y] + 1;
            que.push(A(x - 1, y - 2));
        }
    }
    a[x0][y0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (!(i == x0 && j == y0) && !a[i][j])
                a[i][j] = -1;
            printf("%-5d", a[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}