#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
struct A
{
    int x, y;
    double l, r;
};
A a[1005];
int n, d, ans = 0;
bool cmp(const A a1, const A a2);
int main()
{
    int index = 1;
    while (scanf("%d%d", &n, &d) != EOF && d != 0 || n != 0)
    {
        ans = 0;
        int f = 1;
        int s = 0, dx, dy;
        if (d <= 0)
        {
            f = 0;
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &dx, &dy);
            if (d < dy)
            {
                f = 0;
            }
            if (f)
            {
                if (dy >= 0)
                {
                    a[s].x = dx;
                    a[s].y = dy;
                    a[s].l = a[s].x - (double)sqrt(double(d * d - a[s].y * a[s].y));
                    a[s].r = a[s].x + (double)sqrt(double(d * d - a[s].y * a[s].y));
                    ++s;
                }
            }
        }
        if (f)
        {
            sort(a, a + s, cmp);
            int i = 0;
            double maxs;
            while (i < s)
            {
                maxs = a[i].r;
                ++ans, ++i;
                while (a[i].l <= maxs && i < s)
                {
                    ++i;
                }
            }
        }
        printf("Case %d: %d\n", index++, f ? ans : -1);
    }

    system("pause");
    return 0;
}
bool cmp(const A a1, const A a2)
{
    return a1.r < a2.r;
}