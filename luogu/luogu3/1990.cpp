#include <iostream>
#include <cstdio>
using namespace std;
int n, F[1000001], H[2][1000001];
int main()
{
    scanf("%d", &n);
    F[1] = 1;
    F[2] = 2;
    H[0][1] = H[1][1] = 0;
    H[0][2] = H[1][2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        F[i] = (F[i - 1] + F[i - 2] + H[0][i - 1] + H[1][i - 1]) % 10000; //注意不是 +2*F[i-1]
        H[0][i] = (F[i - 2] + H[1][i - 1]) % 10000;
        H[1][i] = (F[i - 2] + H[0][i - 1]) % 10000;
    }
    printf("%d\n", F[n]);
    system("pause");
    return 0;
}
//取后面4位就是模10000;