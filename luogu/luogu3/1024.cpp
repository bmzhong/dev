#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
double a, b, c, d, cnt;
double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
void solve(double l, double r)
{
    ++cnt;
    if (f(r) < 0)
    {
        int t = r;
        r = l;
        l = t;
    }
    double mid = (l + r) / 2;
    while (abs(f(mid)) >= 0.005)
    {
        if (f(mid) > 0)
            r = mid;
        else
            l = mid;
        mid = (r + l) / 2;
    }
    printf("%.2lf%c", mid, cnt == 3 ? '\n' : ' ');
}
int main()
{
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    for (int i = -100; i <= 100; ++i)
    {
        if (f(i) == 0)
        {
            ++cnt;
            printf("%.2lf%c", (double)i, cnt == 3 ? '\n' : ' ');
        }
        else if (f(i + 1) == 0)
        {
            ++cnt;
            printf("%.2lf%c", (double)i + 1, cnt == 3 ? '\n' : ' ');
            ++i;
        }
        else if (f(i) * f(i + 1) < 0)
            solve(i, i + 1);
    }
    system("pause");
    return 0;
}