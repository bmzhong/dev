#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int n, m, e, u, v, G[501][501], vis[501], matched[501], ans = 0;
bool match(int i)
{
    for (int j = 1; j <= m; ++j)
    {
        if (G[i][j] && !vis[j])
        {
            vis[j] = 1;
            if (matched[j] == 0 || match(matched[j]))
            {
                matched[j] = i;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    n = read();
    m = read();
    e = read();
    for (int i = 0; i < e; ++i)
    {
        u = read();
        v = read();
        G[u][v] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        memset(vis, 0, sizeof(vis));
        if (match(i))
            ++ans;
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}