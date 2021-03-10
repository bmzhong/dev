#include <iostream>
#include <cstdio>
using namespace std;
int n, m, A[1000001];
int query(int q);
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &A[i]);
    }
    int q;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &q);
        printf("%d%c", query(q), i == m - 1 ? '\n' : ' ');
    }
    system("pause");
    return 0;
}
int query(int q)
{
    int lb = -1, ub = n - 1;
    while (ub - lb > 1)
    {
        int md = (lb + ub) / 2;
        int x = A[md];
        if (x >= q)
            ub = md;
        else
            lb = md;
    }
    return A[ub] == q ? ub+1 : -1;
}
