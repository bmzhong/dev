#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
// inline int read()
// {
//     int x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9')
//     {
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//     {
//         x = (x << 1) + (x << 3) + (ch ^ 48);
//         ch = getchar();
//     }
//     return x * f;
// }
struct edge
{
    int from, to, cost;
};
int a, b, w, m, res, cnt, parent[130000], ranks[130000];
edge eg[130000];
bool cmp(const edge &e1, const edge &e2)
{
    return e1.cost < e2.cost;
}
int find_root(const int &x)
{
    if (!parent[x])
        return x;
    return parent[x] = find_root(parent[x]);
}

void unit(const int &x, const int &y)
{
    int x_root = find_root(x);
    int y_root = find_root(y);
    if (x_root != y_root)
    {
        if (ranks[x_root] < ranks[y_root])
            parent[x_root] = y_root;
        else if (ranks[x_root] == ranks[y_root])
        {
            parent[x_root] = y_root;
            ++ranks[y_root];
        }
        else
            parent[y_root] = x_root;
    }
}

bool same(const int &x, const int &y)
{
    return find_root(x) == find_root(y);
}

void krustral()
{
    sort(eg + 1, eg + m + 1, cmp);
    for (int i = 1; i <= m; ++i)
    {
        edge e = eg[i];
        if (!same(e.from, e.to))
        {
            --cnt;
            unit(e.from, e.to);
            res += e.cost;
        }
    }
    res += cnt * a;
}

int main()
{
    scanf("%d%d", &a, &b);
    cnt = b;
    fill(ranks + 1, ranks + cnt + 1, 1);
    for (int i = 1; i <= b; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            scanf("%d", &w);
            if (i <= j)
                continue;
            if (w && w < a)
            {
                eg[++m].from = i;
                eg[m].to = j;
                eg[m].cost = w;
            }
        }
    }
    krustral();
    printf("%d\n", res);
    system("pause");
    return 0;
}