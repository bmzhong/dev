#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
int n, xi, yi, si;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int a[200001][3];
bool judge(long double v)
{
    long double t = 0;
    for (int i = 0; i < n; ++i)
    {
        t = t + a[i][2] / v;
        if (t > a[i][1])
            return false;
        if (t < a[i][0])
            t = a[i][0];
    }
    return true;
}
int main()
{
    n = read();
    for (int i = 0; i < n; ++i)
    {
        a[i][0] = read();
        a[i][1] = read();
        a[i][2] = read();
    }
    long double lb = 0, ub = 3.0*100000001.00, mid = 0.0;
    while (ub - lb > 0.00001)
    {
        mid = (lb + ub) / 2;
        if (judge(mid))
            ub = mid;
        else
            lb = mid;
    }
    cout<<fixed<<setprecision(2)<<mid<<endl;
    system("pause");
    return 0;
}