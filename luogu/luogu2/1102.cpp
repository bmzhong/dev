#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int A[200001], n, c;
void solve();
int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &A[i]);
    }
    solve();
    system("pause");
    return 0;
}
void solve()
{
    sort(A, A + n);
    long long res = 0;
    for (int i = 0; i < n; ++i)
    {
        int q = A[i] + c;
        res += upper_bound(A, A + n, q) - lower_bound(A, A + n, q);
    }
    printf("%lld\n",res);
}