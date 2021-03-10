#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MIN(x, y) (x) < (y) ? (x) : (y)
struct edge
{
    int to, cost;
};
vector<edge> G[1001];
int g[1001][1001];
int d[1001], t[1001], res;
const int inf = 2147483647 / 2;
int n, m, u, v, w;
typedef pair<int, int> P;
void dijkstra(const int &s, int dis[1001]);
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        if (!g[u][v])
        {
            edge e;
            e.to = v;
            e.cost = w;
            G[u].push_back(e);
        }
        else
        {
            int len = G[u].size();
            for (int i = 0; i < len; ++i)
            {
                if (G[u][i].to == v)
                {
                    G[u][i].cost = MIN(G[u][i].cost, w);
                    break;
                }
            }
        }
        if (g[u][v])
            g[u][v] = MIN(g[u][v], w);
        else
            g[u][v] = w;
    }
    dijkstra(1, d);
    for (int i = 2; i <= n; ++i)
    {
        res += d[i];
        dijkstra(i, t);
        res += t[1];
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}
void dijkstra(const int &s, int dis[1001])
{
    fill(dis + 1, dis + n + 1, inf);
    priority_queue<P, vector<P>, greater<P>> pq;
    dis[s] = 0;
    pq.push(P(0, s));
    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        if (dis[p.second] < p.first)
            continue;
        int len = G[p.second].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = G[p.second][i];
            if (dis[e.to] > dis[p.second] + e.cost)
            {
                dis[e.to] = dis[p.second] + e.cost;
                pq.push(P(dis[e.to], e.to));
            }
        }
    }
}