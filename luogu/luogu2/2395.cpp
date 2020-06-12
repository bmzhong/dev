#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
struct edge
{
    int to, cost;
};
vector<edge> G[2001];
typedef pair<long long, int> P;
int n, m, u, v, w, use[2001];
long long res, d[2001], mx[2001], inf = 1000000000000000;
void prim(int s);
int main()
{
    scanf("%d%d", &n, &m);
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
    prim(1);
    printf("%lld\n",res);
    system("pause");
    return 0;
}

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
                pq.push(P(e.cost, e.to));
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        res = max(res, d[i]);
    }
}