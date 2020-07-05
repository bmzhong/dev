#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int A[82][82], B[82][82], C[82][82], k, n;
void pow(int k);
void mul(int D[82][82], int S[82][82]);
int main()
{
    while (true)
    {
        scanf("%d%d", &n, &k);
        if (!n)
            break;
        int t;
        for (int i = 0; i < 2 * n; ++i)
        {
            for (int j = 0; j < 2 * n; ++j)
            {
                if (i < n && j < n)
                {
                    scanf("%d", &t);
                    B[i][j] = t % 10;
                }
                else if (i < n && j >= n)
                    B[i][j] = 0;
                else if (i >= n && j < n)
                {
                    if (i - j == n)
                        B[i][j] = 1;
                    else
                        B[i][j] = 0;
                }
                else
                {
                    if (i == j)
                        B[i][j] = 1;
                    else
                        B[i][j] = 0;
                }
            }
        }
        pow(k + 1);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    printf("%d%c", (A[n + i][j] - 1 + 10) % 10, j == n - 1 ? '\n' : ' ');
                else
                    printf("%d%c", A[n + i][j] % 10, j == n - 1 ? '\n' : ' ');
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
void mul(int D[82][82], int S[82][82])
{
    memset(D, 0, sizeof(A));
    for (int i = 0; i < 2 * n; ++i)
    {
        for (int j = 0; j < 2 * n; ++j)
        {
            for (int k = 0; k < 2 * n; ++k)
            {
                D[i][j] = (D[i][j] + C[i][k] * S[k][j]) % 10;
            }
        }
    }
}

void pow(int k)
{
    for (int i = 0; i < 2 * n; ++i)
    {
        for (int j = 0; j < 2 * n; ++j)
        {
            if (i == j)
                A[i][j] = 1;
            else
                A[i][j] = 0;
        }
    }
    while (k > 0)
    {
        if (k & 1)
        {
            memcpy(C, A, sizeof(A));
            mul(A, B);
        }
        memcpy(C, B, sizeof(B));
        mul(B, C);
        k >>= 1;
    }
}
