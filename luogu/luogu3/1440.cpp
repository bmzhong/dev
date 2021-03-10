#include <iostream>
using namespace std;
int m, n, q[2000001], a[2000001], res[2000001];
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
int head = 1, tail = 0;
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    int len = 0;
    for (int i = 1; i <= n; ++i)
    {
        while (tail >= head && i - m >= q[head])
        {
            ++head;
        }
        while (tail >= head && a[i] <= a[q[tail]])
        {
            --tail;
        }
        q[++tail] = i;
        res[++len] = a[q[head]];
    }
    for (int i = 0; i < len; ++i)
    {
        printf("%d\n",res[i]);
    }
    system("pause");
    return 0;
}