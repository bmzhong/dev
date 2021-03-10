#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int m, n, A[1000000];
void solve();
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &A[i]);
    }
    solve();
    system("pause");
    return 0;
}
bool query(int h)
{
    long long res = 0;
    int s = upper_bound(A, A + n, h) - A;
    for (int i = s; i < n; ++i)
    {
        res += A[i] - h;
    }
    return res >= m;
}

void solve()
{
    sort(A, A + n);
    int ub = 1000000000, lb = 0;
    while (ub - lb > 1)
    {
        int md = (ub + lb) / 2;
        if (!query(md))
            ub = md;
        else
            lb = md;
    }
    printf("%d\n",lb);
}