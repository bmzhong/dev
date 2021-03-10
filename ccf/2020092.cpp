#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, k, t, xl, yd, xr, yu, pass, stay;
int first, second;
inline int read()
{
    int f = 1, x = 0;
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
    k = read();
    t = read();
    xl = read();
    yd = read();
    xr = read();
    yu = read();
    for (int i = 0; i < n; ++i)
    {
        int stay1 = 0, pass1 = 0, last = 0, temp = 0;
        for (int j = 0; j < t; ++j)
        {
            first = read();
            second = read();
            if (first >= xl && second >= yd && first <= xr && second <= yu)
            {
                pass1 = 1;
                if (last)
                {
                    ++temp;
                    if (temp >= k)
                        stay1 = 1;
                }
                else
                    temp = 1;
                last = 1;
            }
            else
                last = 0;
        }
        pass += pass1;
        stay += stay1;
    }
    printf("%d\n%d\n", pass, stay);
    system("pause");
    return 0;
}
