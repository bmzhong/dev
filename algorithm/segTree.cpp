#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll tag[200001], ans[200001], a[100001];
ll m, n;
int main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
    }
}

void pushup(int p)
{
    ans[p] = ans[p << 1] + ans[p << 1 | 1];
}

void build(ll p, ll l, ll r)
{
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
    if (l == r)
        return ans[p];
    ll res = 0;
    ll mid = (l + r) >> 1;
}