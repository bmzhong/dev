#include <iostream>
#include <cstdio>
using namespace std;
struct A
{
    int ch[70]={0};
    int length=0;
};
A dp[1001];
int n, k;
A add_int(A _x, A _y)
{
    A x = _x, y = _y, res;
    if (x.length < y.length)
    {
        A a = x;
        x = y;
        y = a;
    }
    res.length = x.length;
    int jw = 0, len = res.length, sum = 0, i = 0;
    for (i = 0; i < len; ++i)
    {
        sum = x.ch[i] + y.ch[i] + jw;
        if (sum >= 10)
        {
            jw = 1;
        }
        else
            jw = 0;
        res.ch[i] = sum % 10;
    }
    if (jw)
    {
        res.ch[i] = 1;
        ++res.length;
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &k);
    dp[0].length = 1;
    dp[0].ch[0] = 1;
    for (int i = 1; i <= k; ++i)
    {
        for (int j = i; j <= n; ++j)
        {
            dp[j] = add_int(dp[j], dp[j - i]);
        }
    }
    int len = dp[n].length;
    for (int i = len-1; i >=0 ; --i)
    {
        printf("%d", dp[n].ch[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}