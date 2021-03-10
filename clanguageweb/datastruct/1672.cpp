#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int inf = 999999;
int  d[102][102];
char a[102][102];
int n, m;
pair<int, int> s, e;
int dx[4] = {1, 0, 0, -1}, dy[4] = {0, 1, -1, 0};
void init();
void bfs();
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }
        init();
        bfs();
        if (d[e.first][e.second] == inf)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << d[e.first][e.second] << endl;
        }
    }
    system("pause");
    return 0;
}

void init()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (a[i][j] == 'S')
            {
                s.first = i;
                s.second = j;
            }
            if (a[i][j] == 'E')
            {
                e.first = i;
                e.second = j;
            }
            d[i][j] = inf;
        }
    }
}

void bfs()
{
    pair<int, int> p;
    queue<pair<int, int>> q;
    q.push(s);
    d[s.first][s.second] = 0; //这里不是d[0][0]=0;而是起点坐标的d为0.
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        if (p.first == e.first && p.second == e.second)
            break;
        for (int i = 0; i < 4; ++i)
        {
            int px = p.first + dx[i], py = p.second + dy[i];
            if (px >= 0 && px < n && py >= 0 && py < m && d[px][py] == inf && a[px][py] != '#')
            {
                d[px][py] = d[p.first][p.second] + 1;
                q.push(make_pair(px, py));
            }
        }
    }
}