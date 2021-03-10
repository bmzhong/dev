#include <iostream>
#include <cstdio>
using namespace std;
int n, m;
char g[101][101] = {'0'};
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf(" %c", &g[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (g[i][j] == '*')
                printf("*");
            else
            {
                int cnt = 0;
                for (int w = -1; w <= 1; ++w)
                {
                    for (int v = -1; v <= 1; ++v)
                    {
                        if (g[i + w][j + v] == '*')
                            ++cnt;
                    }
                }
                printf("%d", cnt);
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
