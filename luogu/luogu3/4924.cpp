#include <iostream>
#include <cstdio>
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
int a[501][501], n, m, x, y, r, z, temp[501][501];
void transfer_0(int r)
{
    for (int i = -r; i <= r; ++i)
    {
        temp[x + i][y + r] = a[x + i][y + r];
        temp[x - r][y + i] = a[x - r][y + i];
        temp[x + i][y - r] = a[x + i][y - r];
        temp[x + r][y + i] = a[x + r][y + i];
    }
    for (int i = -r; i <= r; ++i)
    {
        a[x + i][y + r] = temp[x - r][y + i];
        a[x - r][y + i] = temp[x - i][y - r];
        a[x - i][y - r] = temp[x + r][y - i];
        a[x + r][y - i] = temp[x + i][y + r];
    }
}
void transfer_1(int r)
{
    for (int i = -r; i <= r; ++i)
    {
        temp[x + i][y + r] = a[x + i][y + r];
        temp[x - r][y + i] = a[x - r][y + i];
        temp[x + i][y - r] = a[x + i][y - r];
        temp[x + r][y + i] = a[x + r][y + i];
    }
    for (int i = -r; i <= r; ++i)
    {
        a[x - r][y + i] = temp[x + i][y + r];
        a[x - i][y - r] = temp[x - r][y + i];
        a[x + r][y - i] = temp[x - i][y - r];
        a[x + i][y + r] = temp[x + r][y - i];
    }
}
int main()
{
    n = read();
    m = read();
    int t = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            a[i][j] = t++;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        x = read();
        y = read();
        r = read();
        z = read();
        if (z == 0)
        {
            for (int j = 1; j <= r; ++j)
            {
                transfer_0(j);
            }
        }
        else
        {
            for (int j = 1; j <= r; ++j)
            {
                transfer_1(j);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%d%c", a[i][j], j == n ? '\n' : ' ');
        }
    }
    system("pause");
    return 0;
}
