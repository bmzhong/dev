#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, f[100001], x[100001];
long long ans = 0;
int solve(int x1)
{
    int l = 0, r = m, mid;
    while (l < r - 1)
    {
        mid = (l + r) / 2;
        if (f[mid] == x1)
            return 0;
        else if (f[mid] > x1)
            r = mid;
        else
            l = mid;
    }
    return abs(x1 - f[l]) > abs(x1 - f[r]) ? abs(x1 - f[r]) : abs(x1 - f[l]);
}
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &f[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x[i]);
    }
    sort(f, f + m);
    for (int i = 0; i < n; ++i)
    {
        ans += solve(x[i]);
    }
    printf("%lld\n",ans);
    system("pause");
    return 0;
}