#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct edge
{
    int to, cost;
};
vector<edge> G[50005];
int T, n, a, b, c, m, M, use[50005], d[50005], cnt[50005];
bool spfa(int s);
int main()
{
    scanf("%d", &T);
    for (int x = 0; x < T; ++x)
    {
        m = 10000000;
        M = 0;
        scanf("%d", &n);
        edge e;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            e.to = b + 1;
            e.cost = c;
            G[a].push_back(e);
            m = min(m, a);
            M = max(M, b);
        }
        for (int i = m; i <= M; ++i)
        {
            e.to = i + 1;
            e.cost = 0;
            G[i].push_back(e);
            e.to = i;
            e.cost = -1;
            G[i + 1].push_back(e);
        }
        spfa(m);
        if (x < T - 1)
            printf("%d\n", d[M + 1]);
        else
            printf("%d", d[M + 1]);
        for (int i = 0; i <= M + 1; ++i)//多组测试数据，记得清空图G
        {
            G[i].clear();
        }
    }
    system("pause");
    return 0;
}
bool spfa(int s)
{
    memset(use, 0, sizeof(use));
    memset(d, -1, sizeof(d));
    memset(cnt, 0, sizeof(cnt));
    queue<int> que;
    que.push(s);
    use[s] = 1;
    d[s] = 0;
    cnt[s] = 1;
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
                if (cnt[e.to] > M - m + 3)
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