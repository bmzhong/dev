#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int v[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &v[i]);
    }
    sort(v, v + n, greater<int>());
    if (a > b)
    {
        int t = a;
        a = b;
        b = t;
    }
    int r1 = 0;
    for (int i = 0; i < a; ++i)
    {
        r1 += v[i];
    }
    int r2 = 0;
    for (int i = a; i < a + b; ++i)
    {
        r2 += v[i];
    }
    double re1 = (double)r1 / a;
    double re2 = (double)r2 / b;
    double re3 = re1 + re2;
    printf("%.6f\n",re3);
    system("pause");
    return 0;
}