#include <iostream>
#include <cstdio>
using namespace std;
long long a[200000];
int n, m;
void update(int k, long long value);
long long query(int x, int y, int k, int l, int r);
int main()
{
    scanf("%d%d", &n, &m);
    long long t;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &t);
        update(n + i, t);
    }
    for(int i=1;i<=2*n;++i){
        cout<<a[i]<<endl;
    }
    int x, y, s;
    long long k;
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", &s);
        if (s == 1)
        {
            scanf("%d%d%lld", &x, &y, &k);
            for (int j = x; j <= y; ++j)
            {
                update(j + n, k);
            }
        }
        else if (s == 2)
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(x, y, 1, 1, n));
        }
    }
    system("pause");
    return 0;
}

void update(int k, long long value)
{
    a[k] += value;
    while (k > 1)
    {
        k = k / 2;
        a[k] = a[2 * k] + a[2 * k + 1];
    }
}
long long query(int x, int y, int k, int l, int r)
{
    if (l > r || y < l || r < x)
        return 0;
    else if (x <= l && r <= y)
        return a[k];
    else
        return query(x, y, 2 * k, l, (l + r) / 2) + query(x, y, 2 * k + 1, (l + r) / 2 + 1, r);
}