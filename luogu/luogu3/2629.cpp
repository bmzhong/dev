#include <iostream>
#include <queue>
using namespace std;
int n, a[2000002], sum[2000002], ans, q[2000002], head = 1, tail = 0;
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
int main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i + n] = a[i] = read();
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i < n; ++i)
    {
        sum[i + n] = sum[i + n - 1] + a[i];
    }
    for (int i = 1; i <= 2 * n - 1; ++i)
    {
        while (tail >= head && i - n >= q[head])
        {
            ++head;
        }
        while (tail >= head && sum[i] <= sum[q[tail]])
        {
            --tail;
        }
        q[++tail] = i;
        if (i >= n && sum[q[head]] - sum[i - n] >= 0)
        {
            ++ans;
        }
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}