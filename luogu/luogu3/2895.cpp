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
int m, x, y, temp, t[305][305], a[305][305], dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0}, res = 2147483647;
queue<A> que;
bool check(int x, int y) //考虑要严谨，不是300，而是302,理解题目意思;
{
    bool j1 = (t[x][y] == -1) || (t[x][y] != -1 && a[x][y] < t[x][y]);
    bool j2 = x - 1 < 0 || ((x - 1 >= 0) && (t[x - 1][y] == -1 || (t[x - 1][y] != -1 && a[x][y] < t[x - 1][y])));
    bool j3 = x + 1 > 302 || ((x + 1 <= 302) && (t[x + 1][y] == -1 || (t[x + 1][y] != -1 && a[x][y] < t[x + 1][y])));
    bool j4 = y + 1 > 302 || ((y + 1 <= 302) && (t[x][y + 1] == -1 || (t[x][y + 1] != -1 && a[x][y] < t[x][y + 1])));
    bool j5 = y - 1 < 0 || ((y - 1 >= 0) && (t[x][y - 1] == -1 || (t[x][y - 1] != -1 && a[x][y] < t[x][y - 1])));
    return j1 && j2 && j3 && j4 && j5;
}
int main()
{
    scanf("%d", &m);
    for (int i = 0; i <= 302; ++i)
    {
        for (int j = 0; j <= 302; ++j)
        {
            a[i][j] = 2147483646;
            t[i][j] = -1;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &x, &y, &temp);
        t[x][y] = temp;
    }
    a[0][0] = 0;
    que.push(A(0, 0));
    while (!que.empty())
    {
        A u = que.front();
        que.pop();
        for (int i = 0; i < 4; ++i)
        {
            x = u.x + dx[i];
            y = u.y + dy[i];
            if (x >= 0 && x <= 302 && y >= 0 && y <= 302 && a[x][y] > a[u.x][u.y] + 1)
            {
                a[x][y] = a[u.x][u.y] + 1;
                if (check(x, y))
                    que.push(A(x, y));
                else
                    a[x][y] = -1;
            }
        }
    }
    for (int i = 0; i <= 302; ++i)
    {
        for (int j = 0; j <= 302; ++j)
        {
            if (t[i][j] == -1 && a[i][j] != -1)
            {
                bool j1 = i - 1 < 0 || (i - 1 >= 0 && t[i - 1][j] == -1);
                bool j2 = i + 1 > 302 || (i + 1 <= 302 && t[i + 1][j] == -1);
                bool j3 = j - 1 < 0 || (j - 1 >= 0 && t[i][j - 1] == -1);
                bool j4 = j + 1 > 302 || (j + 1 <= 302 && t[i][j + 1] == -1);
                if (j1 && j2 && j3 && j4)
                {
                    if (a[i][j] < res)
                        res = a[i][j];
                }
            }
        }
    }
    if (res == 2147483646) //注意不是2147483647，看清楚自己上面赋值的是什么。
        res = -1;
    printf("%d\n", res);
    system("pause");
    return 0;
}