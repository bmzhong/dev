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
        if (!c[i])
        {
            st.push_back(i);
            d[i] = 1;
        }
        if (!bc[i])
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
    printf("%d\n",res);
    system("pause");
    return 0;
}

void bfs(int s)
{
    memset(use + 1, n * sizeof(int), 0);
    queue<int> pq;
    pq.push(s);
    while (!pq.empty())
    {
        int u = pq.front();
        pq.pop();
        use[u] = 1;
        int len = G[u].size();
        for (int i = 0; i < len; ++i)
        {
            int v = G[u][i];
            if (use[v])
                continue;
            pq.push(v);
            d[v] = (d[v] + d[u]) % mod;
        }
    }
}