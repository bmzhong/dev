#include <iostream>
using namespace std;
int w, h;
pair<int, int> s;
int sum = 0, px, py;
char a[21][21];
int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
void dfs();
int main()
{
    while (cin >> w >> h && w != 0 && h != 0)
    {
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                cin >> a[i][j];
                if (a[i][j] == '@')
                {
                    s.first = i;
                    s.second = j;
                }
            }
        }
        sum = 0;
        px = s.first;
        py = s.second;
        dfs();
        cout << sum << endl;
    }
    return 0;
}

void dfs()
{
    ++sum;
    pair<int, int> p(px, py); //必须在每个一dfs中单独设置一个p，不可将p设置为全局变量，因为p需要使用4次。
    a[px][py] = '#';          //必须将访问过的点标记，否则会陷入死循环。
    for (int i = 0; i < 4; ++i)
    {
        px = p.first + dx[i];
        py = p.second + dy[i];
        if (px >= 0 && px < h && py >= 0 && py < w && a[px][py] != '#')
            dfs();
    }
}
