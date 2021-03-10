#include <iostream>
#include <cstring>
using namespace std;
char s1[5001], s2[5001];
int a[5001], b[5001], c[10001];
int main()
{
    scanf("%s%s", s1, s2);
    int lena = strlen(s1);
    int lenb = strlen(s2);
    for (int i = 0; i < lena; ++i)
    {
        a[i] = s1[lena - i - 1] - 48;
    }
    for (int i = 0; i < lenb; ++i)
    {
        b[i] = s2[lenb - i - 1] - 48;
    }
    int lenc = lena > lenb ? lena : lenb;
    int jw = 0;
    for (int i = 0; i < lenc; ++i)
    {
        c[i] = a[i] + b[i] + jw;
        jw = c[i] / 10;
        c[i] %= 10;
    }
    if (jw)
    {
        lenc++;
        c[lenc - 1] = 1;
    }
    for (int i = lenc - 1; i >= 0; --i)
    {
        printf("%d",c[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}