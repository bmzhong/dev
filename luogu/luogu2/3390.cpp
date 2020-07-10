#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long A[101][101], B[101][101], C[101][101];
long long k;
int n, large = sizeof(A);
const int mod = 1000000007;
void pow(long long k);
int main()
{
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%lld", &B[i][j]);
            A[i][j] = 0;
        }
        A[i][i] = 1;
    }
    pow(k);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%lld%c", A[i][j], j == n - 1 ? '\n' : ' ');
        }
    }
    system("pause");
    return 0;
}
void mul(long long D[101][101], long long S[101][101])
{
    memset(D, 0, large);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                D[i][j] = (D[i][j] + C[i][k] * S[k][j] % mod) % mod;
            }
        }
    }
}
void pow(long long k)
{
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