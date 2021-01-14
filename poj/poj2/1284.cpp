#include <iostream>
#include <cstdio>
using namespace std;
int p;
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
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
bool solve(int x)
{
    int res = 1;
    int temp = x % p;
    for (int i = 1; i < p - 1; ++i)
    {
        res = (res * temp) % p;
        if (res == 1)
            return false;
    }
    res = (res * temp) % p;
    if (res == 1)
        return true;
    return false;
}

int main()
{

    while (scanf("%d", &p) != EOF)
    {
        int cnt = 0;
        for (int x = 1; x < p; ++x)
        {
            if (solve(x))
                ++cnt;
        }
        printf("%d\n", cnt);
    }
    system("pause");
    return 0;
}