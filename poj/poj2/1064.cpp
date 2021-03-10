#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const double inf = 10000001;
int n, k;
double a[10001];
double res;
void solve();
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
    {
        double t;
        scanf("%lf", &t);
        a[i] = t;
    }
    solve();
    system("pause");
    return 0;
}

bool ju(double x)
{
    int num = 0;
    for (int i = 1; i <= n; ++i)
    {
        num += (int)(a[i] / x);
    }
    return num >= k;
}

void solve()
{
    double lb = 0;
    double ub = inf;
    for (int i = 0; i < 100; ++i)
    {
        double mid = (lb + ub) / 2;
        if (ju(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%.2f\n", floor(lb * 100) / 100);
}