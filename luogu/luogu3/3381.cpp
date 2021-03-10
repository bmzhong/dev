#include <iostream>
#include <queue>
using namespace std;
#define min(x, y) (x) > (y) ? (y) : (x)
const int inf = 2147483647;
int n, s, t, m, u, v, w, c, cnt = 1, mincost = 0, maxflow = 0;
struct node
{
    int to = 0, next = 0, cap = 0, dis = 0;
};
node edge[100002];
int d[5001], last[5001], pre[5001], flow[5001], head[5001], used[5001];
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
void add_edge(int from, int to, int cap, int dis)
{
    edge[++cnt].to = to;
    edge[cnt].cap = cap;
    edge[cnt].dis = dis;
    edge[cnt].next = head[from];
    head[from] = cnt;
}
bool spfa()
{
    for (int i = 1; i <= n; ++i)
    {
        d[i] = inf;
        last[i] = 0;
        flow[i] = inf;
        pre[i] = 0;
        used[i] = 0;
    }
    d[s] = 0;
    queue<int> que;
    que.push(s);
    used[s] = 1;
    while (!que.empty())
    {
        u = que.front();
        que.pop();
        used[u] = 0;
        for (int i = head[u]; i; i = edge[i].next)
        {
            v = edge[i].to;
            if (edge[i].cap > 0 && d[v] > d[u] + edge[i].dis)
            {
                d[v] = d[u] + edge[i].dis;
                pre[v] = u;
                last[v] = i;
                flow[v] = min(flow[u], edge[i].cap);
                if (!used[v])
                {
                    que.push(v);
                    used[v] = 1;
                }
            }
        }
    }
    return flow[t] != inf;
}

void update()
{
    while (spfa())
    {
        maxflow += flow[t];
        mincost += flow[t] * d[t];
        int now = t;
        while (now != s)
        {
            edge[last[now]].cap -= flow[t];
            edge[(last[now]) ^ 1].cap += flow[t];
            now = pre[now];
        }
    }
}
int main()
{
    n = read();
    m = read();
    s = read();
    t = read();
    for (int i = 0; i < m; ++i)
    {
        u = read();
        v = read();
        w = read();
        c = read();
        add_edge(u, v, w, c);
        add_edge(v, u, 0, -c);
    }
    update();
    printf("%d %d\n", maxflow, mincost);
    system("pause");
    return 0;
}