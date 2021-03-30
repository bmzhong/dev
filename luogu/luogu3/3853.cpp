#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int p, n, k, d[50002];
inline bool solve(int x)
{
    int i = 0, cnt = 0;
    while (i < n - 1)
    {
        if (d[i + 1] - d[i] > x)
        {
            cnt += (d[i + 1] - d[i]) / x;
            if ((d[i + 1] - d[i]) % x == 0)
                --cnt;
        }
        ++i;
    }
    return cnt <= k;
}
int main()
{
    scanf("%d%d%d", &p, &n, &k);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &d[i]);
    }
    int l = 0, r = p * 2;
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (solve(mid))
            r = mid;
        else
            l = mid;
    }
    printf("%d\n", r);
    system("pause");
    return 0;
}