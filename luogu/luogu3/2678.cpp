#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int p, n, m, d[50002];
inline bool solve(int x)
{
    int j = 1, i = 0, cnt = 0;
    while (i < n)
    {
        while (j <= n && d[j] - d[i] < x)
        {
            ++cnt;
            ++j;
        }
        if (j > n)
        {
            if (d[j] - d[i] < x && i != 0)
                ++cnt;
            else if (d[j] - d[i] < x && i == 0)
                return false;
            break;
        }
        else if (j <= n && d[j] - d[i] >= x)
        {
            i = j;
            ++j;
        }
    }
    return cnt <= m;
}
int main()
{
    scanf("%d%d%d", &p, &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &d[i]);
    }
    d[0] = 0;
    d[n + 1] = p;
    int l = 0, r = p * 2;
    while (l < r - 1)
    {
        int mid = (l + r) / 2;
        if (solve(mid))
            l = mid;
        else
            r = mid;
    }
    if(l>p)
        l=p;
    printf("%d\n", l);
    system("pause");
    return 0;
}