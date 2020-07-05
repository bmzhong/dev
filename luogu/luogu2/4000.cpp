#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int A[2][2], p, B[2][2], C[2][2];
long long n;
void pow(int n);
int main()
{
    scanf("%ld%d", &n, &p);
    pow(n);
    printf("%d\n", A[1][0]);
    system("pause");
    return 0;
}
void pow(int n)
{
    B[0][0] = B[0][1] = B[1][0] = 1;
    B[1][1] = 0;
    A[0][0] = A[1][1] = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            memcpy(C, A, sizeof(A));
            A[0][0] = (C[0][0] * B[0][0] + C[0][1] * B[1][0]) % p;
            A[0][1] = (C[0][0] * B[0][1] + C[0][1] * B[1][1]) % p;
            A[1][0] = (C[1][0] * B[0][0] + C[1][1] * B[1][0]) % p;
            A[1][1] = (C[1][0] * B[0][1] + C[1][1] * B[1][1]) % p;
        }
        memcpy(C, B, sizeof(B));
        B[0][0] = (C[0][0] * C[0][0] + C[0][1] * C[1][0]) % p;
        B[0][1] = (C[0][0] * C[0][1] + C[0][1] * C[1][1]) % p;
        B[1][0] = (C[1][0] * C[0][0] + C[1][1] * C[1][0]) % p;
        B[1][1] = (C[1][0] * C[0][1] + C[1][1] * C[1][1]) % p;
        n >>= 1;
    }
}