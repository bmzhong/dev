#include <iostream>
using namespace std;
int f, n, m, w;
int G[501][501];
const int inf = 2147483647 / 2;
int d[501];
int main()
{
    cin >> f;
}
void init()
{
    int s, e, t;
    cin >> n >> m >> w;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            G[i][j] = inf;
            if (i == j)
                G[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; ++m)
    {
        cin >> s >> e >> t;
        G[s][e] = t;
        G[e][s] = t;
    }
    for (int i = 1; i <= w; ++i)
    {
        cin >> s >> e >> t;
        G[s][e] = -t;
    }
}

bool find_negetive_circle()
{
    fill(d + 1, d + 1 + n, 0);
    d[]
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if()
        }
    }
}