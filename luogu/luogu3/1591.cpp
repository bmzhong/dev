#include <iostream>
#include <cstdio>
using namespace std;
int n, t, a, v[1000000], vlen, w[1000000], wlen;
int main()
{
    scanf("%d", &t);
    for (int x = 0; x < t; ++x)
    {
        scanf("%d%d", &n, &a);
        v[0] = 1;
        vlen = 1;
        for (int i = 1; i <= n; ++i)
        {
            int jw = 0;
            for (int j = 0; j < vlen; ++j)
            {
                v[j] = v[j] * i + jw;
                jw = v[j] / 10;
                v[j] %= 10;
            }
            while (jw > 0)
            {
                v[vlen++] = jw % 10;
                jw /= 10;
            }
        }
        int ans = 0;
        for (int i = 0; i < vlen; ++i)
        {
            if (v[i] == a)
            {
                ++ans;
                v[i] = 0;
            }
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}