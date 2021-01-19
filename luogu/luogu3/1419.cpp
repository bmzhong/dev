#include <iostream>
#include <queue>
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
int S, T, n, a[100001];
double b[100001], sum[100001] = {0};
bool judge(double x)
{
    for (int i = 1; i <= n; ++i)
    {
        b[i] = a[i - 1] - x;
        sum[i] = sum[i - 1] + b[i];
    }
    deque<int> dq;
    double maxs = -2e9;
    dq.push_back(0);
    for (int i = S; i <= n; ++i)
    {
        while (!dq.empty() && i - T > dq.front())
        {
            dq.pop_front();
        }
        maxs = maxs > (sum[i] - sum[dq.front()]) ? maxs : (sum[i] - sum[dq.front()]);
        if (maxs >= 0)
            return true;
        while (!dq.empty() && sum[i - S + 1] <= sum[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i - S + 1);
    }
    return false;
}
int main()
{
    n = read();
    S = read();
    T = read();
    for (int i = 0; i < n; ++i)
    {
        a[i] = read();
    }
    double lb = -2e9, ub = 2e9, mid = 0;
    while (ub - lb >= 0.000001)
    {
        mid = (lb + ub) / 2;
        if (judge(mid))
            lb = mid + 0.000001;
        else
            ub = mid - 0.000001;
    }
    printf("%.3f\n", mid);
    system("pause");
    return 0;
}