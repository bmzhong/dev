#include <iostream>
#include <cstring>
using namespace std;
char s1[2001], s2[2001];
int a[2001], b[2001], c[4001];
int main()
{
    scanf("%s%s", s1, s2);
    int fa = 1, fb = 1, fc = 1;
    if (s1[0] == '-')
    {
        fa = -1;
        strcpy(s1, &s1[1]);
    }
    if (s2[0] == '-')
    {
        fb = -1;
        strcpy(s2, &s2[1]);
    }
    if ((fa == -1 && fb == 1) || (fa == 1 && fb == -1))
        fc = -1;
    int lena = strlen(s1), lenb = strlen(s2);
    for (int i = 0; i < lena; ++i)
    {
        a[i] = s1[lena - i - 1] - 48;
    }
    for (int i = 0; i < lenb; ++i)
    {
        b[i] = s2[lenb - i - 1] - 48;
    }
    int jw = 0;
    for (int i = 0; i < lena; ++i)
    {
        jw = 0;
        for (int j = 0; j < lenb; ++j)
        {
            c[i + j] = c[i + j] + jw + a[i] * b[j];
            jw = c[i + j] / 10;
            c[i + j] %= 10;
        }
        c[i + lenb] += jw;
    }
    int lenc = lena + lenb;
    while (lenc > 1 && !c[lenc - 1])
        --lenc;
    if (fc == -1)
        printf("-");
    for (int i = lenc - 1; i >= 0; --i)
    {
        printf("%d", c[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}