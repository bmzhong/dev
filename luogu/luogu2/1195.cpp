#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, m, u, k, v, w, res, cnt;
int parent[1001];
struct edge
{
    int from, to, cost;
};
edge eg[10001];
priority_queue<int> pq;
bool cmp(const edge &e1, const edge &e2);
void unit(const int &x, const int &y);
bool issame(const int &x, const int &y);
int find_root(const int &x);
void krustral();
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    cnt = n;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        eg[i].from = u;
        eg[i].to = v;
        eg[i].cost = w;
    }
    krustral();
    if (cnt > k)
        printf("No Answer\n");
    else
    {
        for (int i = 0; i < k - cnt; ++i)
        {
            res -= pq.top();
            pq.pop();
        }
        printf("%d\n", res);
    }
    system("pause");
    return 0;
}

void krustral()
{
    sort(eg + 1, eg + m + 1, cmp);
    for (int i = 1; i <= m; ++i)
    {
        edge e = eg[i];
        if (!issame(e.from, e.to))
        {
            --cnt;
            unit(e.from, e.to);
            res += e.cost;
            pq.push(e.cost);
        }
    }
}

void unit(const int &x, const int &y)
{
    int x_root = find_root(x);
    int y_root = find_root(y);
    if (x_root != y_root)
        parent[x_root] = y_root;
}

int find_root(const int &x)
{
    if (!parent[x])
        return x;
    return parent[x] = find_root(parent[x]);
}

bool issame(const int &x, const int &y)
{
    return find_root(x) == find_root(y);
}
bool cmp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}