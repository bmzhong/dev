#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, h[301];
long long ans=0;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &h[i]);
    }
    sort(h, h + n + 1);
    int i = 0, j = n;
    while (i < j)
    {
        ans += (h[i] - h[j]) * (h[i] - h[j]);
        ans += (h[i + 1] - h[j]) * (h[i + 1] - h[j]);
        ++i;
        --j;
    }
    printf("%lld\n", ans);
    system("pause");
    return 0;
}
