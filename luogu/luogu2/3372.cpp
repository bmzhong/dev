#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t, x, y, k, m, n = 1, _n;
long long data1[1000002], datb[1000002];
void add(int a, int b, int x, int k, int l, int r);
long long sum(int a, int b, int k, int l, int r);
int main()
{
    scanf("%d%d", &_n, &m);
    while (n < _n)
        n = n << 1;
    for (int i = 0; i < _n; ++i)
    {
        scanf("%d", &t);
        add(i, i + 1, t, 0, 0, n);
    }
    for (int i = 0; i < m; ++i)
    {
        char ch;
        scanf(" %c", &ch);
        if (ch == 'C')
        {
            scanf("%d%d%d", &x, &y, &k);
            add(x-1, y, k, 0, 0, n);
        }
        else
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", sum(x-1, y, 0, 0, n));
        }
    }
    system("pause");
    return 0;
}

void add(int a, int b, int x, int k, int l, int r)
{
    if (a <= l && r <= b)
        data1[k] += x;
    else if (l < b && a < r)
    {
        datb[k] += (min(b, r) - max(a, l)) * x;
        add(a, b, x, 2 * k + 1, l, (l + r) / 2);
        add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }
}

long long sum(int a, int b, int k, int l, int r)
{
    if (b <= l || r <= a)
        return 0;
    else if (a <= l && r <= b)
        return data1[k] * (r - l) + datb[k];
    else
    {
        long long res = (min(r, b) - max(l, a)) * data1[k];
        res += sum(a, b, 2 * k + 1, l, (l + r) / 2);
        res += sum(a, b, 2 * k + 2, (l + r) / 2, r);
        return res;
    }
}

/* #include <iostream>
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
} */