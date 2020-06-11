#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
double cost[1001][1001], res, d[1001];
pair<int, int> dot[1001];
const double inf = 10000000000000000.0;
int n, m, use[1001], u, v;
typedef pair<double, int> P;
void prim(int s);
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &u, &v);
        dot[i].first = u;
        dot[i].second = v;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            double x = dot[i].first - dot[j].first;
            double y = dot[i].second - dot[j].second;
            cost[i][j] = sqrt(x * x + y * y);
            cost[j][i] = cost[i][j];
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        cost[u][v] = 0;
        cost[v][u] = 0;
    }
    prim(1);
    printf("%.2f\n", res);
    system("pause");
    return 0;
}

void prim(int s)
{
    fill(d + 1, d + n + 1, inf);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
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
    for(int i=1;i<=n;++i){
        res+=d[i];
    }
}