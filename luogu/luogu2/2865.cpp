#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
struct edge
{
    int to, cost;
};
vector<edge> G[5001];
typedef pair<int, int> P;
int N, R, u, v, w, dist[5001], dist2[5002];
const int inf = 2147483647 / 2;
void dijkstra();
int main()
{
    scanf("%d%d", &N, &R);
    for (int i = 0; i < R; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        edge e;
        e.cost = w;
        e.to = v - 1;
        G[u - 1].push_back(e);
        e.to = u - 1;
        G[v - 1].push_back(e);
    }
    dijkstra();
    system("pause");
    return 0;
}
void dijkstra()
{
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, 0));
    fill(dist, dist + N, inf);
    fill(dist2, dist2 + N, inf);
    while (!pq.empty())
    {
        P p = pq.top();
        pq.pop();
        int u = p.second;
        if (dist2[u] < p.first)
            continue;
        for (int i = 0; i < G[u].size(); ++i)
        {
            edge e = G[u][i];
            int d = p.first + e.cost;
            if (dist[e.to] > d)
            {
                swap(dist[e.to], d);
                pq.push(P(dist[e.to], e.to));
            }
            if (dist2[e.to] > d && dist[e.to] < d)
            {
                dist2[e.to] = d;
                pq.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%d\n", dist2[N - 1]);
}