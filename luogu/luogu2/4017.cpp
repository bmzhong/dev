#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, m, mod = 80112002, res, use[5001], d[5001], c[5001], bc[5001];
vector<int> st, ed, G[5001];
void bfs(int s);
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        bc[u] = 1;
        c[v] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!c[i] && bc[i])
        {
            st.push_back(i);
            d[i] = 1;
        }
        if (!bc[i] && c[i])
            ed.push_back(i);
    }
    int len = st.size();
    for (int i = 0; i < len; ++i)
    {
        bfs(st[i]);
    }
    len = ed.size();
    for (int i = 0; i < len; ++i)
    {
        res = (res + d[ed[i]]) % mod;
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}

void solve(int s)
{
    memset(use, 0, sizeof(use));
    use[s] = 1;
    while (true)
    {
        int v = -1;
        for (int i = 1; i <= n; ++i)
        {
            if(!use[i]&&G[])
        }
    }
}