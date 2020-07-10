#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct edge
{
    int to, cost;
};
vector<edge> G[5001];
const int inf = 2147483647 / 2;
int n, m, d[5001], use[5001], cnt[5001];
bool spfa(int s);
int main()
{
    scanf("%d%d", &n, &m);
    int x1, x2, y;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &x1, &x2, &y);
        edge e;
        e.to = x1;
        e.cost = y;
        G[x2].push_back(e);
    }
    for (int i = 1; i <= n; ++i)
    {
        edge e;
        e.to = i;
        e.cost = 0;
        G[0].push_back(e);
    }
    if (!spfa(0))
        printf("NO\n");
    else
    {
        for (int i = 1; i <= n; ++i)
            printf("%d%c", d[i], i == n ? '\n' : ' ');
    }
    system("pause");
    return 0;
}
bool spfa(int s)
{
    fill(d, d + n + 1, inf);
    fill(use, use + n + 1, 0);
    fill(cnt, cnt + n + 1, 0);
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
                if (cnt[e.to] > n)
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
