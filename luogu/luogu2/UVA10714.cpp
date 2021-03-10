#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int cnt, L, n, minT, maxT, t;
int main()
{
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i)
    {
        minT = maxT = 0;
        scanf("%d%d", &L, &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &t);
            minT = max(minT, min(t, L - t));
            maxT = max(maxT, max(t, L - t));
        }
        printf("%d %d\n", minT, maxT);
    }
    system("pause");
    return 0;
}