#include <iostream>
using namespace std;
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
int n, m, q[500001], a[500001], sum[500001], head = 0, tail = 0;
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
    }
    int res = sum[1];
    for (int i = 1; i <= n; ++i)
    {
        while (head <= tail && i - m > q[head])
        {
            ++head;
        }
        res = res > sum[i] - sum[q[head]] ? res : sum[i] - sum[q[head]];
        while (head <= tail && sum[i] <= sum[q[tail]])
        {
            --tail;
        }
        q[++tail] = i;
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}