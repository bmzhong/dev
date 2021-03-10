#include <iostream>
#include <cstdio>
using namespace std;
char a[62510];
int cnt = 0, x = 0, y = 0;
int main()
{
    while (scanf(" %c", &a[++cnt]))
    {
        if (a[cnt] == 'E')
            break;
    }
    for (int i = 1; i < cnt; ++i)
    {
        if (a[i] == 'W')
            ++x;
        else if (a[i] == 'L')
            ++y;
        if ((x >= 11 && x - 2 >= y) || (y >= 11 && y - 2 >= x))
        {
            printf("%d:%d\n", x, y);
            x = y = 0;
        }
    }
    printf("%d:%d\n", x, y);
    printf("\n");
    x = y = 0;
    for (int i = 1; i < cnt; ++i)
    {
        if (a[i] == 'W')
            ++x;
        else
            ++y;
        if ((x >= 21 && x - 2 >= y) || (y >= 21 && y - 2 >= x))
        {
            printf("%d:%d\n", x, y);
            x = y = 0;
        }
    }
    printf("%d:%d\n", x, y);
    system("pause");
    return 0;
}