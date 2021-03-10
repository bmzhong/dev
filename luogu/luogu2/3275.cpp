#pragma GCC optimize(2)
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct edge
{
    int to, cost;
};
vector<edge> G[100001];
int N, K, X, A, B, use[100001], cnt[100001];
long long res = 0, d[100001];
const long long inf = 1000000000000000;
bool spfa(int s);
inline int read()
{
    int f = 1, x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return f * x;
}
int main()
{
    N = read();
    K = read();
    edge e;
    for (register int i = 0; i < K; ++i)
    {
        X = read();
        A = read();
        B = read();
        if (X == 1)
        {
            e.to = B;
            e.cost = 0;
            G[A].push_back(e);
            e.to = A;
            G[B].push_back(e);
        }
        else if (X == 2)
        {
            if (A == B)
            {
                printf("-1\n");
                return 0;
            }
            else
            {
                e.cost = 1;
                e.to = B;
                G[A].push_back(e);
            }
        }
        else if (X == 3)
        {
            e.to = A;
            e.cost = 0;
            G[B].push_back(e);
        }
        else if (X == 4)
        {
            if (A == B)
            {
                printf("-1\n");
                return 0;
            }
            else
            {
                e.cost = 1;
                e.to = A;
                G[B].push_back(e);
            }
        }
        else
        {
            e.to = B;
            e.cost = 0;
            G[A].push_back(e);
        }
    }
    e.cost = 1;
    for (register int i = 1; i <= N; ++i)
    {
        e.to = i;
        G[0].push_back(e);
    }
    if (!spfa(0))
        printf("-1\n");
    else
    {
        for (register int i = 1; i <= N; ++i)
        {
            res += d[i];
        }
        printf("%lld\n", res);
    }
    system("pause");
    return 0;
}
bool spfa(int s)
{
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
        for (register int i = 0; i < len; ++i)
        {
            edge e = G[u][i];
            if (d[e.to] < d[u] + e.cost)
            {
                d[e.to] = d[u] + e.cost;
                cnt[e.to] = cnt[u] + 1;
                if (cnt[e.to] > N + 1)
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