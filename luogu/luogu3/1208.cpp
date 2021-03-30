#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int t;
struct A
{
    int dj = 0, w = 0;
};
A a[5001];
int m, v, ans = 0;
bool cmp(const A &a1, const A &a2)
{
    return a1.dj < a2.dj;
}
int main()
{
    scanf("%d%d", &t, &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a[i].dj, &a[i].w);
    }
    sort(a, a + n, cmp);
    int i = 0;
    while (t > 0 && i < n)
    {
        m = t > a[i].w ? a[i].w : t;
        ans += m * a[i].dj;
        ++i;
        t -= m;
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}