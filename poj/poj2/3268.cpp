#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, x, m;
struct edge
{
    int to, cost;
};
const int inf = 2147483647 / 2;
vector<edge> G[1001];
typedef pair<int, int> P;
int d0[1001], d1[1001], u, v, w, res;
void dijkstra(int s, int d[]);
int main()
{
    scanf("%d%d%d", &n, &m, &x);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        edge e;
        e.to = v;
        e.cost = w;
        G[u].push_back(e);
    }
    dijkstra(x, d0);
    for (int i = 1; i <= n; ++i)
    {
        dijkstra(i, d1);
        res = max(res, d0[i] + d1[x]);
    }
    printf("%d\n",res);
    system("pause");
    return 0;
}

void dijkstra(int s, int d[])
{
    fill(d + 1, d + n + 1, inf);
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, s));
    d[s] = 0;
    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        if (d[p.second] < p.first)
            continue;
        int len = G[p.second].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = G[p.second][i];
            if (d[e.to] > d[p.second] + e.cost)
            {
                d[e.to] = d[p.second] + e.cost;
                pq.push(P(d[e.to], e.to));
            }
        }
    }
}