#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll tag[4000001], ans[4000001], a[4000001];
ll m, n, x, y, t, k;
void build(ll p, ll l, ll r);
ll query(ll nl, ll nr, ll l, ll r, ll p);
void update(ll nl, ll nr, ll l, ll r, ll p, ll k);
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%lld%lld%lld", &t, &x, &y);
        if (t == 1)
        {
            scanf("%lld", &k);
            update(x, y, 1, n, 1, k);
        }
        if (t == 2)
        {
            printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
    system("pause");
    return 0;
}

void pushup(int p)
{
    ans[p] = ans[p << 1] + ans[p << 1 | 1];
}

void build(ll p, ll l, ll r)
{
    tag[p] = 0;
    if (l == r)
    {
        ans[p] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
inline void f(int p, ll l, ll r, ll k)
{
    ans[p] += k * (r - l + 1);
    tag[p] += k;
}
void pushdown(ll p, ll l, ll r)
{
    ll mid = (l + r) >> 1;
    f(p << 1, l, mid, tag[p]);
    f(p << 1 | 1, mid + 1, r, tag[p]);
    tag[p] = 0;
}
void update(ll nl, ll nr, ll l, ll r, ll p, ll k)
{
    if (nl <= l && nr >= r)
    {
        ans[p] += k * (r - l + 1);
        tag[p] += k;
        return;
    }
    pushdown(p, l, r);
    ll mid = (l + r) >> 1;
    if (nl <= mid)
        update(nl, nr, l, mid, p << 1, k);
    if (nr > mid)
        update(nl, nr, mid + 1, r, p << 1 | 1, k);
    pushup(p);
}
ll query(ll nl, ll nr, ll l, ll r, ll p)
{
    if (nl <= l && nr >= r)
        return ans[p];
    ll res = 0;
    ll mid = (l + r) >> 1;
    pushdown(p, l, r);
    if (nl <= mid)
        res += query(nl, nr, l, mid, p << 1);
    if (nr > mid)
        res += query(nl, nr, mid + 1, r, p << 1 | 1);
    return res;
}
