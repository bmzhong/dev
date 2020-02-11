#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, rownum, a[100000], dp[100000];
int main()
{
    scanf("%d", &rownum);
    n = rownum * (rownum + 1) / 2;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    int row = 3, next = 4, last = 1, ans = 0, now = 2, p = 2;
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i)
    {
        if (i == next)
        {
            last = next - row + 1;
            now = next;
            next = row + i;
            ++row;
        }
        p = row - 1;
        if (i - p >= last && i - p + 1 < now)
            dp[i] = max(dp[i - p], dp[i + 1 - p]) + a[i];
        else if (i - p < last && i - p + 1 < now)
            dp[i] = dp[last] + a[i];
        else if (i - p >= last && i - p + 1 >= now)
            dp[i] = dp[now - 1] + a[i];
    }
    ans = a[1];
    for (int i = n; i >= n - p+1; --i)
    {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}