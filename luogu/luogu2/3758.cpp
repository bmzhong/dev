#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int G[32][32], A[32][32], B[32][32], C[32][32];
int u, v, n, m, t, res;
const int mod = 2017;
void pow(int k);
int large=sizeof(G);
int main()
{
    scanf("%d%d", &n, &m);
    ++n;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &u, &v);
        G[u-1][v-1] = G[v-1][u-1] = 1;
    }
    scanf("%d", &t);
    for (int i = 0; i <= n-1; ++i)
    {
        G[i][n-1] = 1;
        G[i][i] = 1;
        A[i][i] = 1;
    }
    pow(t);
    for (int i = 0; i < n; ++i)
    {
        res = (res + A[0][i]) % mod;
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}
void mul(int D[32][32], int S[32][32])
{
    memset(D, 0, large);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                D[i][j] = (D[i][j] + C[i][k] * S[k][j]) % mod;
            }
        }
    }
}

void pow(int k)
{
    memcpy(B, G, sizeof(G));
    while (k > 0)
    {
        if (k & 1)
        {
            memcpy(C, A, sizeof(G));
            mul(A, B);
        }
        memcpy(C, B, sizeof(G));
        mul(B, C);
        k >>= 1;
    }
}
