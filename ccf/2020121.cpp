#include <iostream>
#include <cstdio>
using namespace std;
int n, res;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int main()
{
    n = read();
    for (int i = 0; i < n; ++i)
    {
        res += read() * read();
    }
    if (res < 0)
        res = 0;
    printf("%d\n", res);
    system("pause");
    return 0;
}
