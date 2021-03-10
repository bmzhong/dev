#include <iostream>
#include <algorithm>
using namespace std;
int n, c, a[100001], t;
void solve();
int main()
{
    scanf("%d", &t);
    for (int j = 0; j < t; ++j)
    {
        scanf("%d%d", &n, &c);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        solve();
    }
    system("pause");
    return 0;
}

bool ju(int x)
{
    int i = 1;
    int j = 2;
    int cnt = 1;
    while (1)
    {
        while (j <= n && a[j] - a[i] < x)
        {
            ++j;
        }
        if (j > n)
            return false;
        ++cnt;
        if (cnt == c)
            return true;
        i = j;
    }
}

void solve()
{
    int lb = 0;
    int ub = 1000000001;
    int mid;
    for (int i = 0; i < 32; ++i)
    {
        mid = (lb + ub) / 2;
        if (ju(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%d\n", lb);
}