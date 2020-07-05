#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
struct P
{
    int x, y, z;
};
P p[50000];
int n;
bool cmp(const P &p1, const P &p2)
{
    return p1.z < p2.z;
}
double f(const P &p1, const P &p2)
{
    return (double)sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
    }
    sort(p, p + n, cmp);
    double res = 0;
    for (int i = 1; i < n; ++i)
    {
        res += f(p[i], p[i - 1]);
    }
    printf("%.3lf\n",res);
    system("pause");
    return 0;
}