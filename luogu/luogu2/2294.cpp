#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct edge
{
    int to, cost;
};
vector<edge> G[102];
const int inf = 2147483647 / 2;
int s, t, v, w, n, m, minn, maxn, d[102], use[102], cnt[102];
bool spfa(int s);
int main()
{
    scanf("%d", &w);
    for (int x = 0; x < w; ++x)
    {
        edge e;
        minn = 1000000;
        maxn = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d", &s, &t, &v);
            e.to = t + 1;
            e.cost = v;//别写成了-v
            G[s].push_back(e);
            e.to = s;
            e.cost = -v;
            G[t + 1].push_back(e);
            minn = min(minn, s);
            maxn = max(maxn, t + 1);
        }
        for (int i = 1; i <= maxn; ++i)
        {
            e.to = i;
            e.cost = 0;
            G[0].push_back(e);
        }
        if (spfa(0))
            printf("true\n");
        else
            printf("false\n");
        for (int i = 0; i <= maxn; ++i)
        {
            G[i].clear();
        }
    }
    system("pause");
    return 0;
}
bool spfa(int s)
{
    fill(d, d + maxn + 1, inf);
    fill(use, use + maxn + 1, 0);
    fill(cnt, cnt + maxn + 1, 0);
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
                if (cnt[e.to] > maxn - minn + 2)
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