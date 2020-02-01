#include <iostream>
using namespace std;
const int inf = 10000;
int maxx = 0, maxy = 0, mins, dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
int m, a[300][300] = {0}, b[300][300] = {0}, c[302][302] = {0}, x, y, time;
int abs(int r);
void dfs(int px, int py, int sum);
int main()
{
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> x >> y >> time;
        if (x > maxx)
            maxx = x;
        if (y > maxy)
            maxy = y;
        a[x][y] = time;
        c[x + 1][y + 1] = 1;
        c[x + 1][y] = 1;
        c[x + 1][y + 2] = 1;
        c[x][y + 1] = 1;
        c[x + 2][y + 1] = 1;
    }
    dfs(0, 0, -1);
    cout<<mins<<endl;
    system("pause");
    return 0;
}

void dfs(int px, int py, int sum)
{
    pair<int, int> p(px, py);
    b[px][py] = 1;
    ++sum;
    if (c[px + 1][py + 1] == 0 && c[px + 1][py] == 0 && c[px + 1][py + 2] == 0 && c[px][py + 1] == 0 && c[px + 2][py + 1] == 0)
    {
        mins = sum;
        return;
    }
    for (int i = 0; i < 4; ++i)
    {
        px = p.first + dx[i];
        py = p.second + dy[i];
        if (px >= 0 && py >= 0 && px < maxx + 2 && py < maxy + 2 && b[px][py] == 0)
        {
            if ((a[px][py] == 0 || abs(sum - a[px][py]) > 1))
            {
                bool j0 = (px + dx[0] < 0 || px + dx[0] > 300) || abs(sum - a[px + dx[0]][py + dy[0]]) > 0;
                bool j1 = (px + dx[1] < 0 || px + dx[1] > 300) || abs(sum - a[px + dx[1]][py + dy[1]]) > 0;
                bool j2 = (px + dx[2] < 0 || px + dx[2] > 300) || abs(sum - a[px + dx[2]][py + dy[2]]) > 0;
                bool j3 = (px + dx[3] < 0 || px + dx[3] > 300) || abs(sum - a[px + dx[3]][py + dy[3]]) > 0;
                if (j0 && j1 && j2 && j3)
                {
                    dfs(px, py, sum);
                }
            }
        }
    }
}

int abs(int r)
{
    return r < 0 ? -r : r;
}