#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, x, a[100010];
long long ans = 0;
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    if (a[0] > x)
    {
        ans += a[0] - x;
        a[0] -= a[0] - x;
    }
    for (int i = 1; i < n; ++i)
    {
        if (a[i] + a[i - 1] > x)
        {
            ans += a[i] + a[i - 1] - x;
            a[i] -= a[i] + a[i - 1] - x;
        }
    }
    printf("%lld\n", ans);
    system("pause");
    return 0;
}