#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct edge
{
    int to, cost;
};
vector<edge> G[10001];
const int inf = 2147483647 / 2;
int n, m, s, t, u, v, w, res, use[10001], d[10001], mx[10001];
typedef pair<int, int> P;
void prim(int s)
{
    fill(d + 1, d + n + 1, inf);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, s));
    while (!pq.empty())
    {
        P u = pq.top();
        pq.pop();
        use[u.second] = 1;
        if (u.first > d[u.second])
            continue;
        int len = G[u.second].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = G[u.second][i];
            if (use[e.to])
                continue;
            if (d[e.to] > e.cost)
            {
                d[e.to] = e.cost;
                mx[e.to] = max(mx[u.second], e.cost);
                pq.push(P(e.cost, e.to));
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        edge e;
        e.to = v;
        e.cost = w;
        G[u].push_back(e);
        e.to = u;
        G[v].push_back(e);
    }
    prim(s);
    printf("%d\n",mx[t]);
    system("pause");
    return 0;
}