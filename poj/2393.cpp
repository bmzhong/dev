#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, s, a[10001][2];
__int64 ans = 0;
int main()
{
    scanf("%d%d", &n, &s);
    scanf("%d%d", &a[0][0], &a[0][1]);
    ans = a[0][0] * a[0][1];
    for (int i = 1; i < n; ++i)
    {
        scanf("%d%d", &a[i][0], &a[i][1]);
        if (a[i - 1][0] + s > a[i][0])
            ans += a[i][0] * a[i][1];
        else
            ans += (a[i - 1][0] + s) * a[i][1];
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}