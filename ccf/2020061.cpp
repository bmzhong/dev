#include <iostream>
#include <cstdio>
using namespace std;
int n, m, type, t0, t1, t2, d, res;
char maxchar, minchar;
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
    n = read();
    m = read();
    char c;
    for (int i = 0; i < n; ++i)
    {
        a[i].x = read();
        a[i].y = read();
        c = getchar();
        while (c != 'A' && c != 'B')
        {
            c = getchar();
        }
        a[i].type = c;
    }
    for (int i = 0; i < m; ++i)
    {
        res = 1;
        maxchar = 'C';
        minchar = 'C';
        t0 = read();
        t1 = read();
        t2 = read();
        d = t0 + t1 * a[0].x + t2 * a[0].y;
        if (d > 0){
            maxchar = a[0].type;
            minchar = a[0].type=='A'?'B':'A';
        }
        else if (d < 0){
            minchar = a[0].type;
            maxchar = a[0].type=='A'?'B':'A';
        }
        else
            res = 0;
        for (int i = 1; i < n; ++i)
        {
            d = t0 + t1 * a[i].x + t2 * a[i].y;
            if ((d > 0 && a[i].type != maxchar) || (d < 0 && a[i].type != minchar) || (d==0))
            {
                res = 0;
                break;
            }
        }
        if(!res)
            printf("No\n");
        else
            printf("Yes\n");
    }
    system("pause");
    return 0;
}