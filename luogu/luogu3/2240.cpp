#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
double t;
struct A
{
    double dj = 0, w = 0;
};
A a[101];
double m, v, ans = 0;
bool cmp(const A &a1, const A &a2)
{
    return a1.dj > a2.dj;
}
int main()
{
    scanf("%d%lf", &n, &t);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf%lf", &m, &v);
        a[i].w = m;
        a[i].dj = v / m;
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
    printf("%.2lf\n", ans);
    system("pause");
    return 0;
}