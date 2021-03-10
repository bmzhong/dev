#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, r, A[1001], res;
int main()
{
    while (scanf("%d%d", &r, &n) != EOF)
    {
        res = 0;
        if (r == -1 && n == -1)
            break;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &A[i]);
        }
        sort(A, A + n);
        int i = 0;
        while (i < n)
        {
            int s = A[i++];
            while (i < n && A[i] <= s + r)
                ++i;
            int p = A[i - 1];
            while (i < n && A[i] <= p + r)
                ++i;
            ++res;
        }
        printf("%d\n", res);
    }
    system("pause");
    return 0;
}