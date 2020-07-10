#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int T, N, A[41][41], a[41];
int main()
{
    scanf("%d", &T);
    for (int x = 1; x <= T; ++x)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
        {
            a[i] = -1;
            for (int j = 0; j < N; ++j)
            {
                char ch;
                scanf(" %c", &ch);
                if (ch == '1')
                    A[i][j] = 1;
                else
                    A[i][j] = 0;
                if (A[i][j])
                    a[i] = j;
            }
        }
        int res = 0;
        for (int i = 0; i < N; ++i)
        {
            int pos = -1;
            for (int j = i; j < N; ++j)
            {
                if (a[j] <= i)
                {
                    pos = j;
                    break;
                }
            }
            for (int j = pos; j > i; --j)
            {
                swap(a[j], a[j - 1]);
                ++res;
            }
        }
        printf("Case #%d: %d\n", x, res);
    }
    system("pause");
    return 0;
}