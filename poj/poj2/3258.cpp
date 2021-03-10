#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int L, M, N, A[50005];
int read()
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
    int sum = 0, res = 0;
    for (int i = 1; i <= N; ++i)
    {
        sum += A[i] - A[i - 1];
        if (sum < mid)
            ++res;
        else
            sum = 0;
    }
    if (res <= M)
        return true;
    return false;
}
int main()
{
    L = read();
    N = read();
    M = read();
    A[0] = 0;
    A[N + 1] = L;
    int low = L, high = L, mid;
    for (int i = 1; i <= N; ++i)
    {
        A[i] = read();
    }
    sort(A, A + N + 2);
    for (int i = 1; i <= N; ++i)
    {
        if ((A[i] - A[i - 1]) < low)
            low = A[i] - A[i - 1];
    }
    while (low <= high)
    {
        mid = ((low + high) >> 1);
        if (judge(mid))
        {
            low = mid+1;
        }
        else
            high = mid-1;
    }
    printf("%d\n", low-1);
    system("pause");
    return 0;
}