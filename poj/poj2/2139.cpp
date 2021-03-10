#include <iostream>
#include <algorithm>
using namespace std;
int G[501][501];
int n, m;
const int inf = 2147483647 / 2;
int w[501];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            G[i][j] = inf;
            G[j][i] = inf;
            if (i == j)
                G[i][j] = 0;
        }
    }
    int M, t;
    for (int i = 1; i <= m; ++i)
    {
        cin >> M;
        for (int j = 1; j <= M; ++j)
        {
            cin >> w[j];
        }
        for (int j = 1; j <= M; ++j)
        {
            for (int k = 1; k <= M; ++k)
            {
                if (k != j)
                {
                    G[w[j]][w[k]] = 1;
                    G[w[k]][w[j]] = 1;
                }
            }
        }
    }
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
            }
        }
    }
    int res = inf;
    for (int i = 1; i <= n; ++i)
    {
        w[i] = 0;
        for (int j = 1; j <= n; ++j)
        {
            w[i] += G[i][j];
        }
        res = min(w[i], res);
    }
    res = (res * 100) / (n - 1);
    cout << res << endl;
    system("pause");
    return 0;
}