#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int A[62][62], B[62][62], C[62][62];
int k, n, m;
void pow(int k);
void mul(int D[62][62], int S[62][62]);
int large = sizeof(A);
int main()
{
    scanf("%d%d%d", &n, &k, &m);
    int t;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &t);
            B[i][j] = t % m;
        }
        B[n + i][i] = B[n + i][n + i] = 1;
    }
    pow(k + 1);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j)
                printf("%d%c", (A[n + i][j] - 1 + m) % m, j == n - 1 ? '\n' : ' ');
            else
                printf("%d%c", (A[n + i][j]) % m, j == n - 1 ? '\n' : ' ');
        }
    }
    system("pause");
    return 0;
}
void mul(int D[62][62], int S[62][62])
{
    memset(D, 0, large);
    for (int i = 0; i < 2 * n; ++i)
    {
        for (int j = 0; j < 2 * n; ++j)
        {
            for (int k = 0; k < 2 * n; ++k)
            {
                D[i][j] = (D[i][j] + C[i][k] * S[k][j]) % m;
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
            memcpy(C, A, large);
            mul(A, B);
        }
        memcpy(C, B, large);
        mul(B, C);
        k >>= 1;
    }
}
