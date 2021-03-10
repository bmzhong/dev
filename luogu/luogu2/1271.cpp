#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, A[2000001];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &A[i]);
    }
    sort(A, A + m);
    for (int i = 0; i < m; ++i)
    {
        printf("%d%c", A[i], i == m - 1 ? '\n' : ' ');
    }
    system("pause");
    return 0;
}