#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T, N, A[3][3], B[3][3], C[3][3];
void pow(int n);
int unit = sizeof(int);
int main()
{
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        scanf("%d", &N);
        pow(N);
        printf("%d\n", A[0][0]);
    }
    system("pause");
    return 0;
}
void mul(int D[3][3], int S[3][3])
{
    memset(D, 0, 9 * unit);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                D[i][j] = (D[i][j] + C[i][k] * S[k][j]) % 10007;
            }
        }
    }
}

void pow(int n)
{
    A[0][0] = A[1][1] = A[2][2] = 1;
    A[0][1] = A[0][2] = A[1][0] = A[1][2] = A[2][0] = A[2][1] = 0;
    B[0][0] = B[1][0] = B[1][1] = B[1][2] = B[2][2] = 2;
    B[0][1] = B[2][1] = 1;
    B[0][2] = B[2][0] = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            memcpy(C, A, sizeof(A));
            mul(A, B);
        }
        memcpy(C, B, sizeof(B));
        mul(B, C);
        n >>= 1;
    }
}