#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, T, a[4001], b[4001], c[4001], d[4001], C[16000002];
long long res = 0;
void solve();
int main()
{
    scanf("%d", &T);
    for (int x = 0; x < T; ++x)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        }
        solve();
        if (x != T - 1)
            printf("\n");
    }
    system("pause");
    return 0;
}
void solve()
{
    int k = 0;
    res = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            C[k++] = a[i] + b[j];
        }
    }
    sort(C, C + k);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int cd = -(c[i] + d[j]);
            res += upper_bound(C, C + k, cd) - lower_bound(C, C + k, cd);
        }
    }
    printf("%lld\n", res);
}