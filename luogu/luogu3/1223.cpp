#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct A
{
    int v, in;
};
A t[1001];
double ans;
bool cmp(const A &a1, const A &a2)
{
    if (a1.v == a2.v)
        return a1.in < a2.in;
    return a1.v < a2.v;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &t[i].v);
        t[i].in = i + 1;
    }
    sort(t, t + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        printf("%d%c", t[i].in, i == n - 1 ? '\n' : ' ');
        ans += (double)(n - i-1) * t[i].v;
    }
    printf("%.2lf\n", ans / n);
    system("pause");
    return 0;
}