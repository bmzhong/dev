#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct A
{
    int x, y, id, d;
};
int n, X, Y;
A a[200];
bool cmp(A &a1, A &a2)
{
    int d1 = (a1.x - X) * (a1.x - X) + (a1.y - Y) * (a1.y - Y);
    int d2 = (a2.x - X) * (a2.x - X) + (a2.y - Y) * (a2.y - Y);
    if (d1 == d2)
    {
        return a1.id < a2.id;
    }
    return d1 < d2;
}
int main()
{
    scanf("%d%d%d", &n, &X, &Y);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].id = i + 1;
    }
    sort(a, a + n, cmp);
    printf("%d\n%d\n%d\n", a[0].id, a[1].id, a[2].id);
    system("pause");
    return 0;
}