#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
int n, m, x, y;
vector<int> G[1000001];
int res, d[1000001], len[1000001];
void bfs();
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &x, &y);
        if (x == y)
            G[x].push_back(y);
        else
        {
            G[x].push_back(y);
            G[y].push_back(x);
        }
    }
    bfs();
    for (int i = 1; i <= n; ++i)
    {
        cout << d[i] << endl;
    }
    system("pause");
    return 0;
}

void bfs()
{
    queue<int> q;
    q.push(1);
    d[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        int length = G[u].size();
        // for (int i = 0; i < length; ++i)
        // {
        //     int v = G[u][i];
        //     if (u == v)
        //         d[u] = (++d[u]) % 100003;
        // }
        for (int i = 0; i < length; ++i)
        {
            int v = G[u][i];
            if (u == v || v == 1)
                continue;
            if (len[v] && len[v] != len[u] + 1)
                continue;
            if (len[v] == len[u] + 1)
                d[v] = (d[v] + d[u]) % 100003;
            if (!len[v])
            {
                d[v] = d[u];
                len[v] = len[u] + 1;
                q.push(v);
            }
        }
    }
}