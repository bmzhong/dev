#include <iostream>
#include <cstdio>
using namespace std;
int n, dp[100001], a[100001], res;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        dp[i] = a[i];
        for (int j = i - 1; j >= 1; --j)
        {
            if (a[j] >= 0)
                dp[i] += a[j];
            else
                break;
        }
        res = res > dp[i] ? res : dp[i];
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}