#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
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
int n, a[31][31], used[31][31], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    queue<A> que;
    vector<A> v;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (a[i][j] == 0)
            {
                que.push(A(i, j));
                used[i][j] = 1;
                int f = 0;
                while (!que.empty())
                {
                    A u = que.front();
                    que.pop();
                    v.push_back(u);
                    int x = u.x;
                    int y = u.y;
                    for (int k = 0; k < 4; ++k)
                    {
                        int x1 = x + dx[k];
                        int y1 = y + dy[k];
                        if (x1 >= 0 && x1 < n && y1 >= 0 && y1 < n && a[x1][y1] == 0 && !used[x1][y1])
                        {
                            que.push(A(x1, y1));
                            used[x1][y1] = 1;
                            if (x1 == 0 || x1 == n - 1 || y1 == 0 || y1 == n - 1)
                                f = 1;
                        }
                    }
                }
                int p = 2;
                if (f)
                    p = -2;
                for (int k = 0; k < v.size(); ++k)
                {
                    A u = v[k];
                    a[u.x][u.y] = p;
                }
                v.clear();
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d%c", a[i][j] == -2 ? 0 : a[i][j], j == n - 1 ? '\n' : ' ');
        }
    }
    system("pause");
    return 0;
}