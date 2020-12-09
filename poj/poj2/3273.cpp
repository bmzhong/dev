#include <iostream>
#include <cstdio>
using namespace std;
int N, M, K, A[100000];
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
bool judge(int mid)
{
    int sum = 0, cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        sum += A[i];
        if (sum <= mid)
            ++cnt;
        else
            sum = 0;
        if (sum > mid)
            --cnt;
    }
    if (cnt <= K)
        return true;
    return false;
}
int main()
{
    N = read();
    M = read();
    K = N - M;
    for (int i = 0; i < N; ++i)
    {
        A[i] = read();
    }
    int lb = 0, ub = 2147483647, mid;
    while (lb <= ub)
    {
        mid = ((lb + ub) >> 1);
        if (judge(mid))
            lb = mid + 1;
        else
            ub = mid - 1;
    }
    printf("%d\n", lb - 1);
    system("pause");
    return 0;
}