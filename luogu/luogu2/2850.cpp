#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
struct edge
{
    int to, cost;
};
int n, m, u, w, v, t, p;
int d[501], cnt[501], use[501], sta[501];
vector<edge> G[501];
const int inf = 2147483647 / 2;
bool spfa(int s);
int main()
{
    scanf("%d", &t);
    for (int k = 0; k < t; ++k)
    {
        scanf("%d %d %d", &n, &m, &w);
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d %d %d", &u, &v, &p);
            edge e;
            e.to = v;
            e.cost = p;
            G[u].push_back(e);
            e.to = u;
            G[v].push_back(e);
        }
        for (int i = 1; i <= w; ++i)
        {
            scanf("%d %d %d", &u, &v, &p);
            edge e;
            e.to = v;
            e.cost = -p;
            G[u].push_back(e);
            sta[i] = u;
        }
        int res = 1;
        for (int i = 1; i <= w; ++i)
        {
            if (spfa(sta[i]))
            {
                cout << "YES" << endl;
                res = 0;
                break;
            }
        }
        if (res)
            cout << "NO" << endl;
        for (int i = 1; i <= n; ++i)
        {
            G[i].clear();
        }
    }
    system("pause");
    return 0;
}

bool spfa(int s)
{
    fill(d + 1, d + n + 1, inf);
    fill(cnt + 1, cnt + n + 1, 0);
    fill(use + 1, use + n + 1, 0);
    queue<int> que;
    que.push(s);
    use[s] = 1;
    d[s] = 0;
    cnt[s] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        use[u] = 0;
        int len = G[u].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = G[u][i];
            if (d[e.to] > d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                cnt[e.to] = cnt[u] + 1;
                if (cnt[e.to] > n)
                    return true;
                if (!use[e.to])
                {
                    que.push(e.to);
                    use[e.to] = 1;
                }
            }
        }
    }
    return false;
}