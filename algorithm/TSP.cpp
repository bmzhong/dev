#include <iostream>
#include <algorithm>
using namespace std;
int n, G[100][100], m;
int dp[1 << 18][100];
const int INF = 2147483647 / 2;
void solve01();
void solve02();
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            G[i][j] = INF;
        }
    }
    m = 9;
    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        G[u][v] = w;
        G[v][u] = w;
    }
    solve02();
    system("pause");
    return 0;
}
void solve01()
{
    for (int S = 0; S < 1 << n; ++S)
    {
        fill(dp[S], dp[S] + n, INF);
    }
    dp[(1 << n) - 1][0] = 0;
    for (int S = (1 << n) - 1; S >= 0; --S)
    {
        for (int v = 0; v < n; ++v)
        {
            for (int u = 0; u < n; ++u)
            {
                if (!(S >> u & 1))
                {
                    dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + G[v][u]);
                }
            }
        }
    }
    printf("%d\n", dp[0][0]);
}
void solve02()
{
    for (int S = 0; S < 1 << n; ++S)
    {
        fill(dp[S], dp[S] + n, INF);
    }
    dp[0][0] = 0;
    for (int S = 0; S < 1 << n; ++S)
    {
        for (int u = 0; u < n; ++u)
        {
            for (int v = 0; v < n; ++v)
            {
                if (!(S >> v & 1))
                {
                    dp[S | 1 << v][v] = min(dp[S | 1 << v][v], dp[S][u] + G[u][v]);
                }
            }
        }
    }
    // for (int i = 1; i < 1 << n; i += 2)
    // {
    //     for (int j = 0; j < n; ++j)
    //         printf("%d%c", dp[i][j],j==n-1?'\n':' ');
    // }
    printf("%d ",dp[3][0]);
    printf("%d\n", dp[(1 << n) - 1][0]);
}

/*
5 9
0 1 3
0 4 9
0 3 8
1 2 3
1 3 10
1 4 5
2 3 4
2 4 3
3 4 20
*/