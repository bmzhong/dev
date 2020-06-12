#include <iostream>
#include <queue>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;
pair<int, int> dot[1001];
double G[1001][1001], d[1001], res;
int u, v, n, k, use[1001];
typedef pair<double, int> P;
void prim(int s);
const double inf = 10000000000000.0;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &u, &v);
        dot[i].first = u;
        dot[i].second = v;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            double x = dot[i].first - dot[j].first;
            double y = dot[i].second - dot[j].second;
            G[i][j] = G[j][i] = sqrt(x * x + y * y);
        }
    }
    prim(1);
    // res = (res * 100 + 0.005) / 100.0;
    printf("%.2lf\n", res);
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
        if (d[u.second] < u.first)
            continue;
        for (int i = 1; i <= n; ++i)
        {
            if (use[i])
                continue;
            if (d[i] > G[u.second][i])
            {
                d[i] = G[u.second][i];
                pq.push(P(d[i], i));
            }
        }
    }
    sort(d + 1, d + n + 1);
    res = d[n - (k - 2)];
}