#include <iostream>
#include <cstdio>
using namespace std;
int n;
long long mod_pow(long long x, long long m);
bool primer(int a);
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (!n)
            break;
        long long res = 0, change = 0;
        if (primer(n))
        {
            printf("%d is normal.\n", n);
            continue;
        }
        for (int i = 2; i < n; ++i)
        {
            res = mod_pow(i, n);
            change = (res == i % n);
            if (!change)
            {
                printf("%d is normal.\n", n);
                break;
            }
        }
        if (change)
            printf("The number %d is a Carmichael number.\n", n);
    }
    system("pause");
    return 0;
}
bool primer(int a)
{
    for (int i = 2; i * i < a; ++i)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

long long mod_pow(long long x, long long m)
{
    long long y = 1;
    while (m > 0)
    {
        if (m & 1)
            y = (y * x) % n;
        x = (x * x) % n;
        m >>= 1;
    }
    return y;
}
