#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
struct edge
{
    int to, cost;
};
int n, m, u, v, w;
long long d[5001], res;
typedef pair<int, int> P;
const int inf = 2147483647 / 2;
vector<edge> G[5001];
int use[5001];
bool prim();
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        if (u == v)
            continue;
        edge e;
        e.to = v;
        e.cost = w;
        G[u].push_back(e);
        e.to = u;
        G[v].push_back(e);
    }
    if (prim())
        printf("%lld\n", res);
    else
        printf("orz\n");
    system("pause");
    return 0;
}
bool prim()
{
    priority_queue<P, vector<P>, greater<P>> pq;
    fill(d + 1, d + n + 1, inf);
    d[1] = 0;
    pq.push(P(0, 1));
    use[1] = 1;
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
            if(use[e.to])
                continue;
            if (d[e.to] > e.cost)
            {
                d[e.to] = e.cost;
                pq.push(P(d[e.to], e.to));
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (d[i] == inf)
            return false;
        res += d[i];
    }
    return true;
}