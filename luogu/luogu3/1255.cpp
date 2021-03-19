#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, f[5001][5000], len[5001];
void mutiply(int x, int y, int z)
{
    len[z] = max(len[x], len[y]);
    int jw = 0;
    for (int i = 0; i < len[z]; ++i)
    {
        if (f[z][i])
            cout << "f[" << z << "][" << i << "] " << f[z][i] << endl;
        f[z][i] = f[x][i] + f[y][i] + jw;
        jw = f[z][i] / 10;
        f[z][i] %= 10;
    }
    if (jw)
    {
        // if (jw > 1)
        //     cout << x << "  jw>1" << endl;
        f[z][len[z]++] = jw;
    }
}
int main()
{
    scanf("%d", &n);
    f[1][0] = 1;
    f[2][0] = 2;
    len[1] = len[2] = 1;
    for (int i = 3; i <= n; ++i)
    {
        mutiply(i - 2, i - 1, i);
    }
    for (int i = len[n] - 1; i >= 0; --i)
    {
        printf("%d", f[n][i]);
    }
    if (n == 0)
        printf("0");
    printf("\n");
    system("pause");
    return 0;
}