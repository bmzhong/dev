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