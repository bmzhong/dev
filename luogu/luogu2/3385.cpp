#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int t, u, v, w, m, n;
struct edge
{
    int to, cost;
};
int d[2001], use[2001], cnt[2001];
const int inf = 2147483647 / 2;
vector<edge> G[2001];
bool spfa(int s);
int main()
{
    cin >> t;
    for (int k = 0; k < t; ++k)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            G[i].clear();
        }
        for (int i = 1; i <= m; ++i)
        {
            cin >> u >> v >> w;
            edge e;
            e.to = v;
            e.cost = w;
            G[u].push_back(e);
            if (w >= 0)
            {
                e.to = u;
                G[v].push_back(e);
            }
        }
        if (spfa(1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    system("pause");
    return 0;
}

bool spfa(int s)
{
    queue<int> que;
    fill(d + 1, d + 1 + n, inf);
    fill(use + 1, use + 1 + n, 0);
    fill(cnt + 1, cnt + n + 1, 0);
    cnt[s] = 1;
    d[s] = 0;
    que.push(s);
    use[s] = 1;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        use[v] = 0;
        int len = G[v].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                cnt[e.to] = cnt[v] + 1;
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