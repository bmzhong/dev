#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, k, a[100001];
bool solve(int x)
{
    if (0 == x)
        return true;
    int c = 0;
    for (int i = 0; i < n; ++i)
    {
        c += a[i] / x;
    }
    return c >= k;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int mid, l = 0, r = 200000000;
    while (l < r - 1) //注意是l<r-1而不是l<r (l<r l=mid-1 r=mid+1)
    {
        mid = (l + r) / 2;
        if (solve(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", l);
    system("pause");
    return 0;
}