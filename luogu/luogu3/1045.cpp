#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define min(x, y) (x) > (y) ? (y) : (x)
int p, r[25002], t[25002], k[25002], ri = 0, ti = 0;
void solve()
{
    t[0] = 2;
    r[0] = 1;
    ri = 1;
    ti = 1;
    while (p > 0)
    {
        if (p & 1)
        {
            // res *= t;
            for (int i = 0; i < ri; ++i)
            {
                int jw = 0;
                for (int j = 0; j < ti; ++j)
                {
                    k[i + j] += r[i] * t[j] + jw;
                    jw = k[i + j] / 10;
                    k[i + j] %= 10;
                }
                k[i + ti] += jw;
            }
            int q = ti + ri;
            while (q > 1 && !k[q - 1])
                --q;
            for (int i = 0; i < q; ++i)
            {
                if (i < 500)
                    r[i] = k[i];
                k[i] = 0;
            }
            ri = min(q, 500);
        }
        // t *= t;
        for (int i = 0; i < ti; ++i)
        {
            int jw = 0;
            for (int j = 0; j < ti; ++j)
            {
                k[i + j] += t[i] * t[j] + jw;
                jw = k[i + j] / 10;
                k[i + j] %= 10;
            }
            k[ti + i] += jw;
        }
        int q = ti + ti;
        while (q > 1 && !k[q - 1])
            --q;
        // printf("q: %d\n", q);
        for (int i = 0; i < q; ++i)
        {
            if (i < 500)
                t[i] = k[i];
            k[i] = 0;
            // printf("%d ", t[i]);
        }
        // printf("\n");
        ti = min(500, q);
        // printf("ti: %d\n\n", ti);
        p /= 2;
        // printf("p: %d\n\n", p);
    }
}
int main()
{
    scanf("%d", &p);
    printf("%d\n", (int)(p * log10(2) + 1));
    solve();
    r[0] -= 1;
    for (int i = 499; i >= 0; --i)
    {
        printf("%d", r[i]);
        if (i % 50 == 0)
            printf("\n");
    }
    system("pause");
    return 0;
}