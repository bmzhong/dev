#include <iostream>
using namespace std;
int h, w, mins, dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1}, a[20][20], count = 0;
pair<int, int> s, e;
void dfs(int px, int py, int step);
int main()
{
    while (cin >> w >> h && w != 0 && h != 0)
    {
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == 2)
                {
                    s.first = i;
                    s.second = j;
                }
                if (a[i][j] == 3)
                {
                    e.first = i;
                    e.second = j;
                }
            }
        }
        int step = 0;
        dfs(s.first, s.second, step);
    }
    system("pause");
    return 0;
}
void dfs(int px, int py, int step)
{
    ++step;
    pair<int, int> p(px, py);
    a[px][py] = 1;
    for (int i = 0; i < 4; ++i)
    {
        px = p.first;
        py = p.second;
        while (px >= 0 && px < h && py >= 0 && py < w && a[px][py] == 0)
        {
            px += dx[i];
            py += dy[i];
        }
        if (px >= 0 && px < h && py >= 0 && py < w)
        {
            if (a[px][py] == 3)
            {
                mins = step;
                return;
            }
            else
            {
                a[px][py] = 0;
            }
        }
        px -= dx[i];
        py -= dy[i];
        if (px >= 0 && px < h && py >= 0 && py < w && a[px][py] == 0)
        {
            dfs(px, py, step);
        }
    }
}
