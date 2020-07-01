#include <iostream>
#include <cstdio>
using namespace std;
#define min(x, y) (x) > (y) ? (y) : (x)
int n, s;
int a[100001];
void solve();
int main()
{
    while(scanf("%d%d", &n, &s)!=EOF)
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        solve();
    }
    system("pause");
    return 0;
}

void solve()
{
    int sum = 0;
    int i = 1, j = 1, res = 100001;
    while (true)
    {
        while (j <= n && sum < s)
        {
            sum += a[j];
            ++j;
        }
        if (sum < s)
            break;
        res = min(res, j - i);
        sum -= a[i++];
    }
    if (res == 100001)
        res = 0;
    printf("%d\n", res);
}