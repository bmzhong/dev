#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n, m;
long long z, c;
int main()
{
    scanf("%d%d", &n, &m);
    long long q = min(n, m);
    for (int i = 1; i < q; ++i)
    {
        z += i * i;
    }
    z = z + q * m * n - ((q - 1) * q / 2) * n - ((q - 1) * q / 2) * m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            c += (n - i + 1) * (m - j + 1);
        }
    }
    printf("%lld %lld\n", z, c - z);
    system("pause");
    return 0;
}