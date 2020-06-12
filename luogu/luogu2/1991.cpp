#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
const double inf = 1000000000000.0;
int s, p, use[501], u, v;
double res, d[501], G[501][501];
pair<int, int> dot[501];
typedef pair<double, int> P;
void prim(int s1);
int main()
{
    scanf("%d%d", &s, &p);
    for (int i = 1; i <= p; ++i)
    {
        scanf("%d%d", &u, &v);
        dot[i].first = u;
        dot[i].second = v;
    }
    for (int i = 1; i <= p; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            double x = dot[i].first - dot[j].first;
            double y = dot[i].second - dot[j].second;
            G[i][j] = G[j][i] = sqrt(x * x + y * y);
        }
    }
    prim(1);
    res = (res * 100 + 0.005) / 100.0;
    printf("%.2lf\n", res);
    system("pause");
    return 0;
}
void prim(int s1)
{
    fill(d + 1, d + p + 1, inf);
    d[s1] = 0;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push(P(0, s1));
    while (!pq.empty())
    {
        P u = pq.top();
        pq.pop();
        use[u.second] = 1;
        if (d[u.second] < u.first)
            continue;
        for (int i = 1; i <= p; ++i)
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
    sort(d + 2, d + p + 1);
    res=d[p-(s-1)];
}