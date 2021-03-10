#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
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
set<int, greater<int> > s;
int m, y, r, res = 0, yi;
struct A
{
    int y = 0, r = 0;
};
A a[100001];
bool cmp(const A &a1, const A &a2)
{
    return a1.y > a2.y;
}
int main()
{
    m = read();
    for (int i = 0; i < m; ++i)
    {
        a[i].y = read();
        a[i].r = read();
        s.insert(a[i].y);
    }
    int theta = *s.begin();
    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        if (a[i].y < theta && a[i].r == 0)
            ++cnt;
        else if (a[i].y >= theta && a[i].r == 1)
            ++cnt;
    }
    sort(a, a + m, cmp);
    yi = *s.begin();
    res = cnt;
    int k = 0;
    while (k < m && a[k].y == *s.begin())
    {
        ++k;
    }
    set<int, greater<int> >::iterator i = s.begin();
    ++i;
    for (; i != s.end(); ++i)
    {
        while (k < m && a[k].y == *i)
        {
            if (a[k].r == 1)
                ++cnt;
            else
                --cnt;
            ++k;
        }
        if (res < cnt)
        {
            res = cnt;
            yi = *i;
        }
    }
    printf("%d\n", yi);
    system("pause");
    return 0;
}