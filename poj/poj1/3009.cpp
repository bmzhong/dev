#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int mins = 18, w, h, m[25][25], sx, sy, dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
void dfs(int x, int y, int step);
int main()
{
    while (cin >> w >> h&&w!=0)
    {
        memset(m, -1, sizeof(m));
        mins = 18;
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= w; ++j)
            {
                cin >> m[i][j];
                if (m[i][j] == 2)
                {
                    sx = i;
                    sy = j;
                }
            }
        }
        dfs(sx, sy, 0);
        mins > 10 ? cout << -1 << endl : cout << mins << endl;
    }
    system("pause");
    return 0;
}

void dfs(int x, int y, int step)
{
    ++step;
    if (step > 10)
        return;
    pair<int, int> p(x, y);
    for (int i = 0; i < 4; ++i)
    {
        x = p.first + dx[i];
        y = p.second + dy[i];
        while (m[x][y] == 0 || m[x][y] == 2)
        {
            x += dx[i];
            y += dy[i];
        }
        if (m[x][y] == -1)
        {
            continue;
        }
        if (m[x][y] == 1)
        {
            if (x == p.first + dx[i] && y == p.second + dy[i])
                continue;
            else
            {
                m[x][y] = 0;
                dfs(x - dx[i], y - dy[i], step);
                m[x][y] = 1;
            }
        }
        if (m[x][y] == 3)
        {
            mins = min(mins, step);
            return;
        }
    }
}