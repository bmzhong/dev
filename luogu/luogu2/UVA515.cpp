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
vector<edge> G[102];
int x, y, c, n, m, minn, maxn, d[102], use[102], cnt[102];
char ch[2];
const int inf = 2147483647 / 2;
bool spfa(int s);
int main()
{
    while (true)
    {
        scanf("%d", &n);
        if (!n)
            break;
        scanf("%d", &m);
        minn = inf;
        maxn = 0;
        edge e;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &x, &y);
            scanf("%s", ch);
            scanf("%d", &c);
            if (*ch == 'g')
            {
                e.cost = c + 1;
                e.to = x + y + 1;
                G[x].push_back(e);
            }
            else
            {
                e.cost = 1 - c;
                e.to = x;
                G[x + y + 1].push_back(e);
            }
            minn = min(minn, x);
            maxn = max(maxn, x + y + 1);
        }
        for (int i = minn; i <= maxn; ++i)
        {
            e.cost = 0;
            e.to = i;
            G[0].push_back(e);
        }
        if (spfa(0))
            printf("lamentable kingdom\n");
        else
            printf("successful conspiracy\n");
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
    fill(d, d + maxn + 1, -inf);
    fill(use, use + maxn + 1, 0);
    fill(cnt, cnt + maxn + 1, 0);
    queue<int> que;
    que.push(s);
    use[s] = 1;
    d[s] = 0;
    cnt[s] = 1;//更新use,d,cnt这三个值
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        use[u] = 0;//不要写成了s
        int len = G[u].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = G[u][i];
            if (d[e.to] < d[u] + e.cost)
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