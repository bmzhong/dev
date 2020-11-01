#include <iostream>
#include <cstdio>
using namespace std;
int n, m, type, t0, t1, t2, u, d;
struct A
{
    int x, y;
    char type;
};
A a[1000];
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int main()
{
    // n = read();
    // m = read();
    // char c;
    // for (int i = 0; i < n; ++i)
    // {
    //     a[i].x = read();
    //     a[i].y = read();
    //     c = getchar();
    //     while (c != 'A' && c != 'B')
    //     {
    //         c = getchar();
    //     }
    //     a[i].type = c;
    // }
    // for (int i = 0; i < m; ++i)
    // {
    //     t0 = read();
    //     t1 = read();
    //     t2 = read();
    //     d = t0 + t1 * a[0].x + t2 * a[0].y > 0;
    //     if (d > 0)
    //         u = 1;
    //     else if (d < 0)
    //         u = 0;
    //     else
    //         printf("");
    //     for (int i = 0; i < n; ++i)
    //     {
    //         if (t0 + t1)
    //     }
    // }
}