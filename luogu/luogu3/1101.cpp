#include <iostream>
#include <cstdio>
using namespace std;
int a[101][101], n;
char c[101][101], b[8] = {"yizhong"};
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf(" %c", &c[i][j]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (c[i][j] == 'y')
            {
                if (j + 6 < n)
                {
                    int k = 0;
                    for (; k <= 6; ++k)
                    {
                        if (c[i][j + k] != b[k])
                            break;
                    }
                    if (k == 7)
                    {
                        for (int v = 0; v <= 6; ++v)
                        {
                            a[i][j + v] = 1;
                        }
                    }
                    if (i + 6 < n)
                    {
                        int k = 0;
                        for (; k <= 6; ++k)
                        {
                            if (c[i + k][j + k] != b[k])
                                break;
                        }
                        if (k == 7)
                        {
                            for (int v = 0; v <= 6; ++v)
                            {
                                a[i + v][j + v] = 1;
                            }
                        }
                    }
                }
                if (i + 6 < n)
                {
                    int k = 0;
                    for (; k <= 6; ++k)
                    {
                        if (c[i + k][j] != b[k])
                            break;
                    }
                    if (k == 7)
                    {
                        for (int v = 0; v <= 6; ++v)
                        {
                            a[i + v][j] = 1;
                        }
                    }
                    if (j - 6 >= 0)
                    {
                        int k = 0;
                        for (; k <= 6; ++k)
                        {
                            if (c[i + k][j - k] != b[k])
                                break;
                        }
                        if (k == 7)
                        {
                            for (int v = 0; v <= 6; ++v)
                            {
                                a[i + v][j - v] = 1;
                            }
                        }
                    }
                }
                if (j - 6 >= 0)
                {
                    int k = 0;
                    for (; k <= 6; ++k)
                    {
                        if (c[i][j - k] != b[k])
                            break;
                    }
                    if (k == 7)
                    {
                        for (int v = 0; v <= 6; ++v)
                        {
                            a[i][j - v] = 1;
                        }
                    }
                    if (i - 6 >= 0)
                    {
                        int k = 0;
                        for (; k <= 6; ++k)
                        {
                            if (c[i - k][j - k] != b[k])
                                break;
                        }
                        if (k == 7)
                        {
                            for (int v = 0; v <= 6; ++v)
                            {
                                a[i - v][j - v] = 1;
                            }
                        }
                    }
                }
                if (i - 6 >= 0)
                {
                    int k = 0;
                    for (; k <= 6; ++k)
                    {
                        if (c[i - k][j] != b[k])
                            break;
                    }
                    if (k == 7)
                    {
                        for (int v = 0; v <= 6; ++v)
                        {
                            a[i - v][j] = 1;
                        }
                    }
                    if (j + 6 < n)
                    {
                        int k = 0;
                        for (; k <= 6; ++k)
                        {
                            if (c[i - k][j + k] != b[k])
                                break;
                        }
                        if (k == 7)
                        {
                            for (int v = 0; v <= 6; ++v)
                            {
                                a[i - v][j + v] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%c", a[i][j] ? c[i][j] : '*');
        }
        printf("\n");
    }
    system("pause");
    return 0;
}