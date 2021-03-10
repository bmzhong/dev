#include <iostream>
#include <cstdio>
using namespace std;
char a[12][12] = {'*'};
int fx, fy, fd = 1, cx, cy, cd = 1, ju[900000], res = 0, d[5], p[5] = {0, -1, 0, 1, 0}, q[5] = {0, 0, 1, 0, -1};
void detect(int x, int y, char t)
{
    for (int i = 1; i <= 4; ++i)
    {
        d[i] = 1;
        if (a[x + p[i]][y + q[i]] == '.' || a[x + p[i]][y + q[i]] == t)
            d[i] = 0;
    }
}
int main()
{
    for (int i = 1; i <= 10; ++i)
    {
        for (int j = 1; j <= 10; ++j)
        {
            scanf(" %c", &a[i][j]);
            if (a[i][j] == 'F')
            {
                fx = i;
                fy = j;
            }
            else if (a[i][j] == 'C')
            {
                cx = i;
                cy = j;
            }
        }
    }
    while (true)
    {
        int temp = fx + fy * 10 + cx * 100 + cy * 1000 + fd * 10000 + cd * 40000;
        if (ju[temp])
        {
            res = 0;
            break;
        }
        ju[temp] = 1;
        if (fx == cx && fy == cy)
            break;
        detect(fx, fy, 'C');
        if (d[fd])
            fd = fd % 4 + 1;
        else
        {
            a[fx][fy] = '.';
            fx += p[fd];
            fy += q[fd];
        }
        detect(cx, cy, 'F');
        if (d[cd])
            cd = cd % 4 + 1;
        else
        {
            a[cx][cy] = '.';
            cx += p[cd];
            cy += q[cd];
        }
        ++res;
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}