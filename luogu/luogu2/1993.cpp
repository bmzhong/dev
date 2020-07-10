#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct edge
{
    int to, cost;
};
vector<edge> G[5001];
const int inf = 2147483647 / 2;
int n, m, use[5001], cnt[5001], d[5001];
bool spfa(int s);
int main()
{
    scanf("%d%d", &n, &m);
    int a, b, c, x;
    edge e;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &x, &a, &b);
        if (x == 3)
        {
            e.cost = 0;
            e.to = a;
            G[b].push_back(e);
            e.to = b;
            G[a].push_back(e);
            continue;
        }
        scanf("%d", &c);
        if (x == 1)
        {
            e.to = b;
            e.cost = -c;
            G[a].push_back(e);
        }
        if (x == 2)
        {
            e.to = a;
            e.cost = c;
            G[b].push_back(e);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        e.to = i;
        e.cost = 0;
        G[0].push_back(e);
    }
    if (!spfa(0))
        printf("No\n");
    else
        printf("Yes\n");
    system("pause");
    return 0;
}
bool spfa(int s)
{
    fill(d, d + n + 1, inf);
    d[s] = 0;
    cnt[s] = 1;
    queue<int> que;
    que.push(s);
    use[s] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        use[u] = 0;
        int len = G[u].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = G[u][i];
            if (d[e.to] > d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                cnt[e.to] = cnt[u] + 1;
                if (cnt[e.to] > n + 1)
                    return false;
                if (!use[e.to])
                {
                    que.push(e.to);
                    use[e.to] = 1;
                }
            }
        }
    }
    return true;
}