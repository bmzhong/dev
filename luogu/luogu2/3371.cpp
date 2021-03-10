#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 2147483647;
struct edge
{
    int to, cost;
};
int n, m, s;
vector<edge> G[100001];
long long d[100001];
typedef pair<int, int> P;
void dijkstra();
int main()
{
    cin >> n >> m >> s;
    int u, v, c;
    for (int i = 1; i <= m; ++i)
    {
        edge e;
        cin >> u >> v >> c;
        e.to = v;
        e.cost = c;
        G[u].push_back(e);
    }
    dijkstra();
    for (int i = 1; i < n; ++i)
    {
        if (d[i] == inf)
            cout << 2147483647<<" ";
        else
            cout << d[i]<<" ";
    }
    if(d[n]==inf)
        cout << 2147483647<<endl;
    else
        cout<<d[n]<<endl;
    system("pause");
    return 0;
}
void dijkstra()
{
    fill(d, d + n + 1, inf);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P>> que;
    que.push(pair<int, int>(0, s));
    while (!que.empty())
    {
        P e = que.top();
        que.pop();
        int v = e.second;
        if (d[v] < e.first)
            continue;
        int len = G[v].size();
        for (int i = 0; i < len; ++i)
        {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost)
            {
                d[e.to] = d[v] + e.cost;
                que.push(pair<int, int>(d[e.to], e.to));
            }
        }
    }
}