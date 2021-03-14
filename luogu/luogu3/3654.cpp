#include <iostream>
#include <cstdio>
using namespace std;
int r, c, k, a[2][101], ans, one;
char ch[101][101];
#define max(x, y) (x) > (y) ? (x) : (y)
int main()
{
    scanf("%d%d%d", &r, &c, &k);
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
        {
            scanf(" %c", &ch[i][j]);
            if (ch[i][j] == '.')
                ++one;
        }
    }
    for (int i = 1; i <= r; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= c; ++j)
        {
            if (ch[i][j] == '.')
            {
                ++cnt;
                if (cnt >= k)
                    ++ans;
            }
            else
                cnt = 0;
        }
    }
    for (int i = 1; i <= c; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= r; ++j)
        {
            if (ch[j][i] == '.')
            {
                ++cnt;
                if (cnt >= k)
                    ++ans;
            }
            else
                cnt = 0;
        }
    }
    if (k == 1)
        ans = one;
    printf("%d\n", ans);
    system("pause");
    return 0;
}