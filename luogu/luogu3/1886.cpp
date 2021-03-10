#include <iostream>
#include <queue>
using namespace std;
int n, k, a[1000002], maxs[1000002], mins[1000002];
deque<int> maxdq, mindq;
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
    k = read();
    for (int i = 0; i < n; ++i)
    {
        a[i] = read();
    }
    int maxi = 0, mini = 0;
    for (int i = 0; i < n; ++i)
    {
        while (!maxdq.empty() && i - k >= maxdq.front())
        {
            maxdq.pop_front();
        }
        while (!mindq.empty() && i - k >= mindq.front())
        {
            mindq.pop_front();
        }
        while (!maxdq.empty() && a[maxdq.back()] <= a[i])
        {
            maxdq.pop_back();
        }
        while (!mindq.empty() && a[mindq.back()] >= a[i])
        {
            mindq.pop_back();
        }
        maxdq.push_back(i);
        mindq.push_back(i);
        if (i >= k - 1)
        {
            maxs[maxi++] = a[maxdq.front()];
            mins[mini++] = a[mindq.front()];
        }
    }
    
    for (int i = 0; i < mini - 1; ++i)
    {
        printf("%d ", mins[i]);
    }
    printf("%d\n", mins[mini - 1]);

    for (int i = 0; i < maxi - 1; ++i)
    {
        printf("%d ", maxs[i]);
    }
    printf("%d\n", maxs[maxi - 1]);

    system("pause");
    return 0;
}