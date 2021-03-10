#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n, m, Q, t, x, y, k;
const int maxn = 100007;
ll ans[maxn << 2], add[maxn << 2], mul[maxn << 2], a[maxn];
ll query(ll nl, ll nr, ll l, ll r, ll p);
void build(ll l, ll r, ll p);
void update(ll nl, ll nr, ll l, ll r, ll p, ll k, ll mu);
int main()
{
    scanf("%lld%lld%lld", &n, &m, &Q);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    build(1, n, 1);
    for (int i = 1; i <= m; ++i)
    {
        scanf("%lld%lld%lld", &t, &x, &y);
        if (t == 1)
        {
            scanf("%lld", &k);
            update(x, y, 1, n, 1, 0, k);
        }
        if (t == 2)
        {
            scanf("%lld", &k);
            update(x, y, 1, n, 1, k, 1);
        }
        if (t == 3)
        {
            printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
    system("pause");
    return 0;
}
void push_up(ll l, ll r, ll p)
{
    ans[p] = (ans[p << 1] + ans[p << 1 | 1]) % Q;
}
void build(ll l, ll r, ll p)
{
    add[p] = 0;
    mul[p] = 1;
    if (l == r)
    {
        ans[p] = a[l] % Q;
        return;
    }
    ll mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    push_up(l, r, p);
}
inline void f(ll l, ll r, ll p, ll k, ll mu)
{
    ans[p] = (ans[p] % Q) * (mu % Q);
    ans[p] = (ans[p] + k * (r - l + 1)) % Q;
    add[p] = (add[p] * mu) % Q;
    add[p] = (add[p] + k) % Q;
    mul[p] = (mul[p] % Q) * (mu % Q);
}
void push_down(ll l, ll r, ll p)
{
    ll mid = (l + r) >> 1;
    f(l, mid, p << 1, add[p], mul[p]);
    f(mid + 1, r, p << 1 | 1, add[p], mul[p]);
    add[p] = 0;
    mul[p] = 1;
}
void update(ll nl, ll nr, ll l, ll r, ll p, ll k, ll mu)
{
    if (nl <= l && nr >= r)
    {
        ans[p] = (ans[p] * mu) % Q;
        add[p] = (add[p] * mu) % Q;
        mul[p] = (mul[p] * mu) % Q;
        ans[p] = (ans[p] + k * (r - l + 1)) % Q;
        add[p] = (add[p] + k) % Q;
        return;
    }
    push_down(l, r, p);
    ll mid = (l + r) >> 1;
    if (nl <= mid)
        update(nl, nr, l, mid, p << 1, k, mu);
    if (nr > mid)
        update(nl, nr, mid + 1, r, p << 1 | 1, k, mu);
    push_up(l, r, p);
}
ll query(ll nl, ll nr, ll l, ll r, ll p)
{
    if (nl <= l & nr >= r)
        return ans[p];
    ll res = 0;
    ll mid = (l + r) >> 1;
    push_down(l, r, p);
    if (nl <= mid)
        res = (res + query(nl, nr, l, mid, p << 1)) % Q;
    if (nr > mid)
        res = (res + query(nl, nr, mid + 1, r, p << 1 | 1)) % Q;
    return res;
}