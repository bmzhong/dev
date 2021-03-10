#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, a[10001], b[10001];
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
void bubble_sort()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] < a[j - 1])
            {
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
            }
        }
    }
}
int main()
{
    n = read();
    for (int i = 0; i < n; ++i)
    {
        b[i] = read();
    }
    for (int i = 1; i < n; ++i)
    {
        a[i - 1] = abs(b[i] - b[i - 1]);
    }
    n = n - 1;
    bubble_sort();
    int flag = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] != i+1)
        {
            flag = 1;
            break;
        }
        // printf("%d ", a[i]);
    }
    if (!flag)
        printf("Jolly\n");
    else
        printf("Not jolly\n");
    system("pause");
    return 0;
}