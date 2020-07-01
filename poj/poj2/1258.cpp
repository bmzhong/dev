#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, use[101], d[101], res, cost[101][101];
const int inf = 2147483647 / 2;
typedef pair<int, int> P;
void prim(int s);
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &cost[i][j]);
            }
        }
        prim(1);
        printf("%d\n", res);
        fill(use+1,use+n+1,0);
        res=0;
    }

    system("pause");
    return 0;
}
void prim(int s)
{
    fill(d + 1, d + n + 1, inf);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P> > pq;
    pq.push(P(0, s));
    while (!pq.empty())
    {
        P u = pq.top();
        pq.pop();
        use[u.second] = 1;
        if (u.first > d[u.second])
            continue;
        for (int i = 1; i <= n; ++i)
        {
            if (use[i])
                continue;
            if (d[i] > cost[u.second][i])
            {
                d[i] = cost[u.second][i];
                pq.push(P(d[i], i));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        res += d[i];
    }
}