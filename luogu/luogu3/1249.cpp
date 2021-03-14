#include <iostream>
#include <cstdio>
using namespace std;
int n, a[100000], len = 0;
void mutiply(int b)
{
    int jw = 0;
    for (int i = 0; i < len; ++i)
    {
        a[i] = a[i] * b + jw;
        jw = a[i] / 10;
        a[i] %= 10;
    }
    while (jw > 0)
    {
        a[len++] = jw % 10;
        jw /= 10;
    }
}
int main()
{
    scanf("%d", &n);
    a[0] = 1;
    len = 1;
    int sum = 0, k;
    for (int i = 2; i <= n; ++i)
    {
        sum += i;
        if (sum >= n)
        {
            k = i;
            break;
        }
    }
    int q = 0;
    if (sum - n == 1)
        q = 2;
    else if (sum - n > 1)
        q = sum - n;
    for (int i = 2; i <= k; ++i)
    {
        if (i != q)
        {
            printf("%d%c", i, i == k ? '\n' : ' ');
            mutiply(i);
        }
    }
    if (q == k)
        printf("\n");
    for (int i = len-1; i >= 0; --i)
    {
        printf("%d",a[i]);
    }
    system("pause");
    return 0;
}