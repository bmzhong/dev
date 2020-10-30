#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, k, t, xl, yd, xr, yu, pass, stay;
pair<int, int> p[20][1000];
inline bool judge(int x, int y)
{
    return (x >= xl && y >= yd && x <= xr && y <= yu);
}
inline void record(int xi)
{
    int pass1 = 0, stay1 = 0, last = 0;
    for (int j = 0; j < t; ++j)
    {
        if (judge(p[xi][j].first, p[xi][j].second))
        {
            pass1 = 1;
            if (last)
            {
                ++stay1;
                if (stay1 >= k)
                    break;
                    
            }
            else
                stay1 = 1;
            last = 1;
        }
        else
        {
            last = 0;
        }
    }
    pass += pass1;
    if (stay1 >= k)
    {
        ++stay;
    }
}
int main()
{
    scanf("%d%d%d%d%d%d%d", &n, &k, &t, &xl, &yd, &xr, &yu);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < t; ++j)
        {
            scanf("%d%d", &p[i][j].first, &p[i][j].second);
        }
        record(i);
    }
    printf("%d\n%d\n", pass, stay);
    system("pause");
    return 0;
}
