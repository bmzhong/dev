#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int to = 0, cost = 0;
};
int u, v, w, s, n, m, d[10000], used[10000], cnt[10000];
const int inf = 2147483647;
bool spfa(int s);
vector<edge> g[10000];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        edge e;
        scanf("%d%d%d", &u, &v, &w);
        e.to = v;
        e.cost = w;
        g[u].push_back(e);
        if (w >= 0)
        {
            e.to = u;
            g[v].push_back(e);
        }
    }
    if (spfa(1))
        printf("YES\n");
    else
        printf("NO\n");

    // for (int i = 1; i <= n; ++i)
    // {
    //     printf("%d ", d[i]);
    // }
    // printf("\n");
    system("pause");
    return 0;
}
bool spfa(int s)
{
    fill(d, d + n + 1, inf);
    queue<int> que;
    d[s] = 0;
    cnt[s] = 1;
    used[s] = 1;
    que.push(s);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        used[u] = 0;
        int len = g[u].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = g[u][i];
            if (d[e.to] > d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                cnt[e.to] = cnt[u] + 1;
                if (cnt[e.to] > n)
                    return true;
                if (!used[e.to])
                {
                    used[e.to] = 1;
                    que.push(e.to);
                }
            }
        }
    }
    return false;
}
