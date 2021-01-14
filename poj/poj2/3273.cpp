// logu p2884 p1182
#include <iostream>
#include <cstdio>
using namespace std;
int N, M, MAX = 0, A[100000];
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
bool judge(long long mid)
{
    long long sum = 0;
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += A[i];
        if (sum > mid)
        {
            sum = A[i];
            ++cnt;
        }
    }
    ++cnt;
    if (cnt <= M)
        return true;
    return false;
}

int main()
{
    N = read();
    M = read();
    for (int i = 0; i < N; ++i)
    {
        A[i] = read();
        MAX = A[i] > MAX ? A[i] : MAX;
    }
    long long lb = MAX - 1, ub = 10e13+1, mid = 0;
    while (ub - lb > 1)
    {
        mid = (lb + ub) >> 1;
        if (judge(mid))
        {
            ub = mid;
        }
        else
        {
            lb = mid;
        }
    }
    printf("%lld\n", ub);
    system("pause");
    return 0;
}
