#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct edge
{
    int to, cost;
};
const int maxn = 100;
vector<edge> G[maxn];
queue<int> Q, T;
int n, m, u, v, cost, in[maxn];
void solve()
{
    for (int i = 1; i <= n; ++i)
    {
        if (!in[i])
        {
            Q.push(i);
        }
    }
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();
        T.push(u);
        int len = G[u].size();
        for (int i = 0; i < len; ++i)
        {
            v = G[u][i].to;
            --in[v];
            if (!in[v])
                Q.push(v);
        }
    }
    if (T.size() != n)
    {
        cout << "circle" << endl;
        return;
    }
    while (!T.empty())
    {
        cout << T.front() << " ";
        T.pop();
    }
    cout << endl;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        edge e;
        cin >> u >> v;
        // cin >> e.cost;
        e.to = v;
        G[u].push_back(e);
        ++in[v];
    }
    solve();
    system("pause");
    return 0;
}