#include <iostream>
using namespace std;
int n, h = 2, w = 4;
char a[1025][1025];
int main()
{
    for (int i = 0; i < 1025; ++i)
    {
        for (int j = 0; j < 1025; ++j)
            a[i][j] = ' ';
    }
    a[1][2] = a[2][1] = '/';
    a[1][3] = a[2][4] = '\\';
    a[2][2] = a[2][3] = '_';
    scanf("%d", &n);
    for (int v = 1; v < n; ++v)
    {
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= w; ++j)
            {
                a[i + h][j] = a[i + h][j + w] = a[i][j];
                a[i][j] = ' ';
            }
        }
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= w; ++j)
            {
                a[i][j + w / 2] = a[i + h][j];
            }
        }
        w *= 2;
        h *= 2;
    }
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
            printf("%c", a[i][j]);
        printf("\n");
    }
    system("pause");
    return 0;
}