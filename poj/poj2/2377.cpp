#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
typedef pair<int, int> P;
struct edge
{
    int to, cost;
};
vector<edge> G[1001];
const int inf = 2147483647 / 2;
int n, m, u, v, w, res, d[1001], use[1001];
bool prim(int s);
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
    if (prim(1))
        printf("%d\n", res);
    else
        printf("-1\n");
    system("pause");
    return 0;
}

bool prim(int s)
{
    // fill(d + 1, d + n + 1, 0);
    d[s] = 0;
    priority_queue<P, vector<P>, less<P>> pq;
    pq.push(P(0, s));
    while (!pq.empty())
    {
        P u = pq.top();
        pq.pop();
        use[u.second] = 1;
        if (d[u.second] > u.first)
            continue;
        int len = G[u.second].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = G[u.second][i];
            if (use[e.to])
                continue;
            if (d[e.to] < e.cost)
            {
                d[e.to] = e.cost;
                pq.push(P(d[e.to], e.to));
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (!d[i])
            return false;
        res += d[i];
    }
    return true;
}