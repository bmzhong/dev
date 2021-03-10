#include <iostream>
#include <queue>
using namespace std;
int n, a[200001], sum[200001];
deque<int> dq;
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
    sum[1] = a[1] = read();
    for (int i = 2; i <= n; ++i)
    {
        a[i] = read();
        sum[i] = sum[i - 1] + a[i];
    }
    dq.push_back(0);
    int maxs = sum[1], temp;
    for (int i = 1; i <= n; ++i)
    {
        temp = sum[i] - sum[dq.front()];
        maxs = maxs > temp ? maxs : temp;
        while (!dq.empty() && sum[i] < sum[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    printf("%d\n", maxs);
    system("pause");
    return 0;
}