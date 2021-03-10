#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int p1, p2, p3;
char a[1000], t[1000];
int main()
{
    scanf("%d%d%d", &p1, &p2, &p3);
    scanf("%s", a);
    int n = strlen(a);
    for (int i = 0; i < n; ++i)
    {
        if ((a[i] == '-') && (i > 0 && i + 1 < n) && (a[i - 1] >= 'a' && a[i - 1] <= 'z' && a[i + 1] >= 'a' && a[i + 1] <= 'z' || a[i - 1] >= '0' && a[i - 1] <= '9' && a[i + 1] >= '0' && a[i + 1] <= '9' || a[i - 1] >= 'A' && a[i - 1] <= 'Z' && a[i + 1] >= 'A' && a[i + 1] <= 'Z'))
        {
            if (a[i - 1] + 1 == a[i + 1])
                continue;
            else if (a[i + 1] <= a[i - 1])
                printf("%c", a[i]);
            else
            {
                int k = 0;
                if (p1 == 1)
                {
                    if (a[i - 1] >= 'A' && a[i - 1] <= 'Z')
                    {
                        for (int j = a[i - 1] + 1; j < a[i + 1]; ++j)
                        {
                            t[k++] = (char)j + 'a' - 'A';
                        }
                    }
                    else
                    {
                        for (int j = a[i - 1] + 1; j < a[i + 1]; ++j)
                        {
                            t[k++] = (char)j;
                        }
                    }
                }
                else if (p1 == 2)
                {
                    if (a[i - 1] >= 'a' && a[i - 1] <= 'z')
                    {
                        for (int j = a[i - 1] + 1; j < a[i + 1]; ++j)
                        {
                            t[k++] = (char)j + 'A' - 'a';
                        }
                    }
                    else
                    {
                        for (int j = a[i - 1] + 1; j < a[i + 1]; ++j)
                        {
                            t[k++] = (char)j;
                        }
                    }
                }
                else if (p1 == 3)
                {
                    for (int j = a[i - 1] + 1; j < a[i + 1]; ++j)
                    {
                        t[k++] = '*';
                    }
                }

                if (p3 == 1)
                {
                    for (int v = 0; v < k; ++v)
                    {
                        for (int j = 0; j < p2; ++j)
                        {
                            printf("%c", t[v]);
                        }
                    }
                }
                else
                {
                    for (int v = k - 1; v >= 0; --v)
                    {
                        for (int j = 0; j < p2; ++j)
                        {
                            printf("%c", t[v]);
                        }
                    }
                }
            }
        }
        else
        {
            printf("%c", a[i]);
        }
    }
    printf("\n");
    system("pause");
    return 0;
}