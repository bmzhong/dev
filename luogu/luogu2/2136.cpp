#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
struct edge
{
    int to, cost;
};
int n, m, u, v, w;
vector<edge> G[1001];
const int inf = 2147483647 / 2;
int d[1001], use[1001], cnt[1001];
bool spfa(int s);
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        edge e;
        e.to = v;
        e.cost = -w;
        G[u].push_back(e);
    }
    bool a = spfa(1);
    int res1 = d[n];
    bool b = spfa(n);
    int res2 = d[1];
    if (a || b)
        printf("Forever love\n");
    else
        printf("%d\n", res1 < res2 ? res1 : res2);
    system("pause");
    return 0;
}

bool spfa(int s)
{
    queue<int> que;
    fill(d + 1, d + n + 1, inf);
    fill(use + 1, use + 1 + n, 0);
    fill(cnt + 1, cnt + n + 1, 0);
    d[s] = 0;
    use[s] = 1;
    cnt[s] = 1;
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
            if (d[e.to] > d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                cnt[e.to] = cnt[u] + 1;
                if (cnt[e.to] > n)
                    return true;
                if (!use[e.to])
                {
                    use[e.to] = 1;
                    que.push(e.to);
                }
            }
        }
    }
    return false;
}