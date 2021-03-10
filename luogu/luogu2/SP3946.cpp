#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int n, m, B = 1000, A[100001], num[100001], L[5001], R[5001], K[5001];
vector<int> v[200];
void solve();
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &A[i]);
    }
    int ll, rr, kk;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &ll, &rr, &kk);
        L[i] = ll - 1;
        R[i] = rr - 1;
        K[i] = kk;
    }
    solve();
    system("pause");
    return 0;
}
void solve()
{
    for (int i = 0; i < n; ++i)
    {
        v[i / B].push_back(A[i]);
        num[i] = A[i];
    }
    sort(num, num + n);
    for (int i = 0; i < n / B; ++i)
    {
        sort(v[i].begin(), v[i].end());
    }
    for (int i = 0; i < m; ++i)
    {
        int l = L[i], r = R[i] + 1, k = K[i];
        int lb = -1, ub = n - 1;
        while (ub - lb > 1)
        {
            int md = (lb + ub) / 2;
            int x = num[md];
            int tl = l, tr = r, c = 0;
            while (tl < tr && tl % B != 0)
                if (A[tl++] <= x)
                    ++c;
            while (tl < tr && tr % B != 0)
                if (A[--tr] <= x)
                    ++c;
            while (tl < tr)
            {
                int b = tl / B;
                c += upper_bound(v[b].begin(), v[b].end(), x) - v[b].begin();
                tl += B;
            }
            if (c >= k)
                ub = md;
            else
                lb = md;
        }
        printf("%d\n", num[ub]);
    }
}