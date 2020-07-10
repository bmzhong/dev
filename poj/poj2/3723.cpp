#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge
{
    int u, v, w;
};
int T, N, M, R, u, v, w, parent[20002], ranks[20002];
edge G[50001];
bool cmp(const edge &e1, const edge &e2)
{
    return e1.w < e2.w;
}
void solve();
int main()
{
    scanf("%d", &T);
    for (int x = 0; x < T; ++x)
    {
        scanf("%d%d%d", &N, &M, &R);
        for (int i = 0; i < R; ++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            edge e;
            e.u = u;
            e.v = N + v;
            e.w = -w;
            G[i] = e;
        }
        solve();
    }
    system("pause");
    return 0;
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
        if (ranks[x] > ranks[y])
            parent[y] = x;
        else
        {
            parent[x] = y;
            ++ranks[y];
        }
    }
}
bool same(int x, int y)
{
    return find_root(x) == find_root(y);
}
void solve()
{
    sort(G, G + R, cmp);
    memset(parent, 0, sizeof(parent));
    memset(ranks, 0, sizeof(ranks));
    long long res = 0;
    for (int i = 0; i < R; ++i)
    {
        edge e = G[i];
        if (!same(e.u, e.v))
        {
            unit(e.u, e.v);
            res += e.w;
        }
    }
    printf("%lld\n", 10000 * (N + M) + res);
}