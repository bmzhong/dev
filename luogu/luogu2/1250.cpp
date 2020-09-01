#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
struct edge
{
    int to, cost;
};
vector<edge> G[30002];
int x, y, w, n, h, d[30002], use[30002], cnt[30002];
const int inf = 2147483647 / 2;
bool spfa(int s);
int main()
{
    scanf("%d%d", &n, &h);
    edge e;
    for (int i = 0; i < h; ++i)
    {
        scanf("%d%d%d", &x, &y, &w);
        e.to = y + 1;
        e.cost = w;
        G[x].push_back(e);
    }
    for (int i = 1; i <= n; ++i)
    {
        e.to = i + 1;
        e.cost = 0;
        G[i].push_back(e);
        e.to = i;
        e.cost = -1;
        G[i + 1].push_back(e);
    }
    spfa(1);
    printf("%d\n", d[n + 1]);
    system("pause");
    return  0;
}
bool spfa(int s)
{
    fill(d, d + n + 1, -inf);
    fill(use, use + n + 1, 0);
    fill(cnt, cnt + n + 1, 0);
    d[s] = 0;
    cnt[s] = 1;
    use[s] = 1;
    queue<int> que;
    que.push(s);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        use[u] = 0;
        int len = G[u].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = G[u][i];
            if (d[e.to] < d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                cnt[e.to] = cnt[u] + 1;
                if (cnt[e.to] > n + 1)
                    return false;
                if (!use[e.to])
                {
                    use[e.to] = 1;
                    que.push(e.to);
                }
            }
        }
    }
    return true;
}