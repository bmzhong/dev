// version 1.0
/* #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edge
{
    int to = 0, cost = 0;
};
int n, m, s, u, v, w, used[10001], d[10001];
const int inf = 2147483647;
vector<edge> g[10001];
void dijstra(int s);
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; ++i)
    {
        edge e;
        scanf("%d%d%d", &u, &v, &w);
        e.to = v;
        e.cost = w;
        g[u].push_back(e);
    }
    dijstra(s);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", d[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
void dijstra(int s)
{
    fill(used, used + n + 1, 0);
    fill(d, d + n + 1, inf);
    d[s] = 0;
    while (true)
    {
        int u = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (!used[i] && (u == -1 || d[i] < d[u]))
                u = i;
        }
        if (u == -1)
            break;
        used[u] = 1;
        int len = g[u].size();
        for (int v = 0; v < len; ++v)
        {
            if (d[g[u][v].to] > d[u] + g[u][v].cost)
                d[g[u][v].to] = d[u] + g[u][v].cost;
        }
    }
} */

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct edge
{
    int to = 0, cost = 0;
};
int n, m, s, u, v, w, d[10001];
const int inf = 2147483647;
vector<edge> g[10001];
typedef pair<int, int> P;
void dijstra(int s);
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; ++i)
    {
        edge e;
        scanf("%d%d%d", &u, &v, &w);
        e.to = v;
        e.cost = w;
        g[u].push_back(e);
    }
        dijstra(s);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", d[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}
void dijstra(int s)
{
    fill(d, d + n + 1, inf);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(P(0, s));
    while (!que.empty())
    {
        P p = que.top();
        que.pop();
        u = p.second;
        if (d[u] < p.first)
            continue;
        int len = g[u].size();
        for (int v = 0; v < len; ++v)
        {
            if (d[g[u][v].to] > d[u] + g[u][v].cost)
            {
                d[g[u][v].to] = d[u] + g[u][v].cost;
                que.push(P(d[g[u][v].to], g[u][v].to));
            }
        }
    }
}