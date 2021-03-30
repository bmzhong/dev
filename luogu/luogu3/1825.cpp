#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n, m, ans, cnt[301][301], a[301][301], b[30][5], x0, y0, xn, yn;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char ch;
struct A
{
    int x, y;
    A(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            scanf(" %c", &ch);
            if (ch == '#')
                a[i][j] = -4;
            else if (ch == '.')
                a[i][j] = -3;
            else if (ch == '=')
            {
                xn = i;
                yn = j;
                a[i][j] = -2;
            }
            else if (ch == '@')
            {
                x0 = i;
                y0 = j;
                a[i][j] = -1;
            }
            else
            {
                a[i][j] = ch - 'A';
                if (b[ch - 'A'][0] == 0)
                {
                    b[ch - 'A'][0] = 1;
                    b[ch - 'A'][1] = i;
                    b[ch - 'A'][2] = j;
                }
                else
                {
                    b[ch - 'A'][3] = i;
                    b[ch - 'A'][4] = j;
                }
            }
        }
    }
    queue<A> que;
    que.push(A(x0, y0));
    cnt[x0][y0] = 1;
    while (!que.empty())
    {
        A u = que.front();
        que.pop();
        int x = u.x;
        int y = u.y;
        for (int i = 0; i < 4; ++i)
        {
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < m && a[x1][y1] != -4)
            {
                if (a[x1][y1] == -3 && !cnt[x1][y1])
                {
                    cnt[x1][y1] = cnt[x][y] + 1;
                    que.push(A(x1, y1));
                }
                else if (a[x1][y1] == -2)
                {
                    cnt[x1][y1] = cnt[x][y] + 1;
                    break;
                }
                else if (a[x1][y1] >= 0)
                {
                    // printf("%c\n", a[x1][y1] + 'A');
                    if (b[a[x1][y1]][1] == x1 && b[a[x1][y1]][2] == y1)
                    {
                        cnt[x1][y1] = cnt[x][y] + 1;
                        cnt[b[a[x1][y1]][3]][b[a[x1][y1]][4]] = cnt[x][y] + 1;
                        que.push(A(b[a[x1][y1]][3], b[a[x1][y1]][4]));
                    }
                    else
                    {
                        cnt[x1][y1] = cnt[x][y] + 1;
                        cnt[b[a[x1][y1]][1]][b[a[x1][y1]][2]] = cnt[x][y] + 1;
                        que.push(A(b[a[x1][y1]][1], b[a[x1][y1]][2]));
                    }
                }
            }
        }
        if (cnt[xn][yn])
            break;
    }
    printf("%d\n", cnt[xn][yn] - 1);
    system("pause");
    return 0;
}