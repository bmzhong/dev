#include <iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
struct A
{
    int hi, ai, ci;
};
A a[401];
bool dp[40001];
int k, maxs = 0;
bool cmp(const A a1, const A a2)
{
    return a1.ai < a2.ai;
}
int main()
{
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d%d%d", &a[i].hi, &a[i].ai, &a[i].ci);
    }
    sort(a + 1, a + k + 1, cmp);
    dp[0] = true;
    for (int i = 1; i <= k; ++i)
    {
        if (a[i].ci > a[i].ai / a[i].hi)
        {
            for (int j = a[i].hi; j <= a[i].ai; ++j)
            {
                dp[j] = dp[j] || dp[j - a[i].hi];
            }
        }
        else
        {
            int num = a[i].ci;
            for (int x = 1; num > 0; x <<= 1)
            {
                if (x > num)
                    x = num;
                num -= x;
                for (int j = a[i].ai; j >= x * a[i].hi; --j)
                {
                    dp[j] = dp[j] || dp[j - x * a[i].hi];
                }
            }
        }
    }
    for (int i = 1; i <= 40000; ++i)
    {
        if (dp[i])
        {
            maxs = i;
        }
    }
    printf("%d\n", maxs);
    system("pause");
    return 0;
}