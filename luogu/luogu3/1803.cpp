#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, ans = 0;
struct A
{
    int s = 0, e = 0;
};
A a[1000001];
bool cmp(const A &a1, const A &a2)
{
    if (a1.e == a2.e)
        return a1.s > a2.s;
    return a1.e < a2.e;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a[i].s, &a[i].e);
    }
    sort(a, a + n, cmp);
    int e = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i].s >= e)
        {
            e = a[i].e;
            ++ans;
        }
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}