#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, w, a[30001], ans;
int main()
{
    scanf("%d%d", &w, &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (a[i] + a[j] <= w)
        {
            ++ans;
            ++i;
            --j;
        }
        else
        {
            --j;
            ++ans;
        }
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}