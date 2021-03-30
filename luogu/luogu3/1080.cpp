#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct A
{
    int a = 1, b = 1;
};
A h[1002];
int n, a, b, r[1001][5000], s[1001];
bool cmp(const A &a1, const A &a2)
{
    return a1.a * a1.b <= a2.a * a2.b;
}
int main()
{
    scanf("%d%d%d", &n, &h[0].a, &h[0].b);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &h[i].a, &h[i].b);
    }
    sort(h + 1, h + n + 1, cmp);
    
    for (int i = 0; i < n; ++i)
    {
    }
    system("pause");
    return 0;
}