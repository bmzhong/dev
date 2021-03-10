#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
struct edge
{
    int from, to, cost;
};
edge eg[100001];
int n, m, u, v, w, k, cnt, parent[100001], ranks[100001];
long long res = 0;
const int inf = 10000;
bool cmp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}
int find_root(int x)
{
    if (!parent[x])
        return x;
    return parent[x] = find_root(parent[x]);
}
void unit(int x, int y)
{
    x = find_root(x);
    y = find_root(y);
    if (x != y)
    {
        if (ranks[x] < ranks[y])
            parent[x] = y;
        else
        {
            parent[y] = x;
            if (ranks[x] == ranks[y])
                ++ranks[x];
        }
    }
}
bool same(int x, int y)
{
    return find_root(x) == find_root(y);
}

void krustral()
{
    sort(eg + 1, eg + m + 1, cmp);
    priority_queue<int> pq;
    for (int i = 1; i <= m; ++i)
    {
        edge e = eg[i];
        if (!same(e.from, e.to))
        {
            unit(e.from, e.to);
            pq.push(e.cost);
            res += e.cost;
        }
    }
    while (pq.size() > k)
    {
        res -= pq.top();
        pq.pop();
    }
    res = inf * k - res;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        eg[i].from = u;
        eg[i].to = v;
        eg[i].cost = inf - w;
    }
    krustral();
    printf("%lld\n", res);
    system("pause");
    return 0;
}
