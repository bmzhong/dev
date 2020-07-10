#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstdlib>
using namespace std;
struct edge
{
    int to, cost;
};
int A, B, D, N, ML, MD, use[1001], cnt[1001];
long long d[1001], res;
vector<edge> G[20001];
const long long inf = 1000000000000;
bool spfa(int s);
int main()
{
    scanf("%d%d%d", &N, &ML, &MD);
    for (int i = 0; i < ML; ++i)
    {
        scanf("%d%d%d", &A, &B, &D);
        edge e;
        e.to = B;
        e.cost = D;
        G[A].push_back(e);
    }
    for (int i = 0; i < MD; ++i)
    {
        scanf("%d%d%d", &A, &B, &D);
        edge e;
        e.to = A;
        e.cost = -D;
        G[B].push_back(e);
    }
    for (int i = 1; i <= N; ++i)
    {
        edge e;
        e.to = i;
        e.cost = 0;
        G[0].push_back(e);
    }
    spfa(0);
    spfa(1);
    printf("%lld\n", res = (d[N] == inf ? -2 : d[N]));
    system("pause");
    return 0;
}
bool spfa(int s)
{
    fill(d, d + N + 1, inf);
    fill(use, use + N + 1, 0);
    fill(cnt, cnt + N + 1, 0);
    queue<int> que;
    que.push(s);
    d[s] = 0;
    cnt[s] = 1;
    use[s] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        use[u] = 0;
        for (int i = 0; i < G[u].size(); ++i)
        {
            edge e = G[u][i];
            if (d[e.to] > d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                cnt[e.to] = cnt[u] + 1;
                if (cnt[e.to] > N)
                {
                    printf("-1\n");
                    exit(0);
                    return false;
                }
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