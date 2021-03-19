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
    int i = 0;
    while (i < n)
    {
        int a1 = a[i] + a[i + 1] - x;
        int a2 = a[i + 1] + a[i + 2] - x;
        if (a1 > 0 && a2 > 0)
        {
            if (a[i + 1] >= a1 && a[i + 1] >= a2)
            {
                a[i + 1] -= max(a1, a2);
                ans += max(a1, a2);
            }
            else if (a[i + 1] >= a1 && a[i + 1] < a2)
            {
                a[i + 1] -= a1;
                a[i + 2] -= (a2 - a1);
                ans += a2;
            }
            else if (a[i + 1] < a1 && a[i + 1] >= a2)
            {
                a[i + 1] -= a2;
                a[i] -= (a1 - a2);
                ans += a1;
            }
            else if (a[i + 1] < a1 && a[i + 1] < a2)
            {
                a[i] -= (a1 - a[i + 1]);
                a[i + 2] -= (a2 - a[i + 1]);
                ans += a1 + a2 - a[i + 1];
                a[i + 1] -= a[i + 1];
            }
        }
        else if (a1 > 0 && a2 <= 0)
            ans += a1;
        else if (a1 <= 0 && a2 > 0)
        {
            if (a[i + 2] >= a2)
                a[i + 2] -= a2;
            else
                a[i + 2] = 0;
            ans += a2;
        }
        i += 2;
    }
    printf("%lld\n", ans);
    system("pause");
    return 0;
}