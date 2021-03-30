#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct A
{
    double a = 0, b = 0;
};
int n;
double p, a[100001], b[100001];
bool check(double u)
{
    vector<A> w1, w2;
    for (int i = 0; i < n; ++i)
    {
        if (b[i] / a[i] < u)
        {
            if (a[i] >= p)
            {
                A temp;
                temp.a = a[i];
                temp.b = b[i];
                w1.push_back(temp);
            }
            else
            {
                A temp;
                temp.a = a[i];
                temp.b = b[i];
                w2.push_back(temp);
            }
        }
    }
    double t = u;
    int len1 = w1.size(), len2 = w2.size();
    for (int i = 0; i < len1; ++i)
    {
        double x = (w1[i].b + p * u - w1[i].a * u) / p;
        t -= (u - x);
        if (t < 0)
            return false;
    }
    for (int i = 0; i < len2; ++i)
    {
        double c = w2[i].b / w2[i].a;
        double d = w2[i].a * (u - c) / p;
        t -= d;
        if (t < 0)
            return false;
    }
    return true;
}
int main()
{
    scanf("%d%lf", &n, &p);
    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf%lf", &a[i], &b[i]);
        sum += a[i];
    }
    if (sum <= p)
    {
        printf("-1\n");
        return 0;
    }
    double l = 0, r = 1e8;
    while (l < r - 1e-7)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    if (l == 1e8)
        l = 2499975000;
    printf("%.6lf\n", l);
    system("pause");
    return 0;
}