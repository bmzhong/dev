#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int x, y, z;
bool solve(double a)
{
    double res = 0;
    double temp = 1.0;
    for (int i = 1; i <= z; ++i)
    {
        temp *= (1 + a);
        res += 1 / temp;
    }
    return res > (double)x / y;
}
int main()
{
    scanf("%d%d%d", &x, &y, &z);
    double l = 0, r = 5;
    while (l < r - 0.0005)
    {
        double mid = (l + r) / 2;
        if (solve(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.1lf\n", l * 100);
    system("pause");
    return 0;
}