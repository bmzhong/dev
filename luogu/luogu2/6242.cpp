#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define mid ((l + r) / 2)
#define pl (p << 1)
#define pr (p << 1 | 1)
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))
const int maxn = 500002;
ll rare[maxn];
struct Tree
{
    ll mina, maxa, suma, maxb;
};
Tree tree[maxn << 2];
ll n, m, op, l, r, k, v, tagk[maxn << 2], tagv[maxn << 2];
inline ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return f * x;
}
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
    {
        rare[i] = read();
    }
    for (int i = 1; i <= m; ++i)
    {
        op = read();
        l = read();
        r = read();
        if (op == 1)
        {
        }
    }
}
void push_up(ll l, ll r, ll p)
{
    tree[p].mina = min(tree[pl].mina, tree[pr].mina);
    tree[p].maxa = max(tree[pl].maxa, tree[pr].maxa);
    tree[p].suma = tree[pl].suma + tree[pr].suma;
    tree[p].maxb = max(tree[pl].maxb, tree[pr].maxb);
}
void build(ll l, ll r, ll p)
{
    tagk[p] = 0;
    if (l == r)
    {
        tagv[p] = rare[l];
        tree[p].mina = tree[p].maxa = rare[l];
        tree[p].suma = tree[p].maxb = rare[l];
        return;
    }
    build(l, mid, pl);
    build(mid + 1, r, pr);
    push_up(l, r, p);
    tagv[p] = tree[p].mina;
}
inline void f(ll l, ll r, ll p, ll k)
{
    tree[p].mina += k;
    tree[p].maxa += k;
    tree[p].suma += k * (r - l + 1);
    tree[p].maxb = max(tree[p].maxb, tree[p].maxa);
}
void push_down(ll l, ll r, ll p)
{
    f(l, mid, pl, tagk[p]);
    f(mid + 1, r, pr, tagk[p]);
    tagk[p] = 0;
}
void update_k(ll nl, ll nr, ll l, ll r, ll p, ll k)
{
    if (nl <= l && nr >= r)
    {
        tagk[p] += k;
        tree[p].mina += k;
        tree[p].maxa += k;
        tree[p].suma += k * (r - l + 1);
        tree[p].maxb = max(tree[p].maxb, tree[p].maxa);
        return;
    }
    push_down(l, r, p);
    if (nl <= mid)
        update_k(nl, nr, l, mid, pl, k);
    if (nr > mid)
        update_k(nl, nr, mid + 1, r, pr, k);
    push_up(l, r, p);
}
