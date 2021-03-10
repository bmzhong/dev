#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define min(x, y) (x) > (y) ? (y) : (x)
int n, m, s, t, u, v, w, level[503], cnt = 1;
struct edge
{
    int to, next = 0;
    long long cost;
};
edge node[10004];
int head[503];
const long long inf = 1e18;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
void add_edge(int u, int v, int cost)
{
    node[++cnt].to = v;
    node[cnt].cost = cost;
    node[cnt].next = head[u];
    head[u] = cnt;
}
bool bfs()
{
    memset(level, 0, sizeof(level));
    queue<int> q;
    q.push(s);
    level[s] = 1;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int i = head[u]; i; i = node[i].next)
        {
            v = node[i].to;
            if (!level[v] && node[i].cost)
            {
                q.push(v);
                level[v] = level[u] + 1;
            }
        }
    }
    return level[t] != 0;
}
long long dfs(int u, long long in)
{
    if (u == t)
        return in;
    long long out = 0;
    for (int i = head[u]; i; i = node[i].next)
    {
        v = node[i].to;
        if (node[i].cost && level[v] == level[u] + 1)
        {
            long long d = dfs(v, min(in, node[i].cost));
            node[i].cost -= d;
            node[i ^ 1].cost += d;
            in -= d;
            out += d;
        }
    }
    if (out == 0)
        level[u] = 0;
    return out;
}
int main()
{
    n = read();
    m = read();
    s = 1;
    t = m;
    for (int i = 0; i < n; ++i)
    {
        u = read();
        v = read();
        w = read();
        add_edge(u, v, w);
        add_edge(v, u, 0);
    }
    long long res = 0;
    while (bfs())
    {
        res += dfs(s, inf);
    }
    printf("%lld\n", res);
    system("pause");
    return 0;
}