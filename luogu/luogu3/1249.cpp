#include <iostream>
#include <cstdio>
using namespace std;
int n, used[10001], x[2][10001], len1 = 0, len2 = 0;
int fun(int b, int g)
{
    if (b <= 4)
        return 0;
    for (int p = b / 2; p > 1; --p)
    {
        len1 = fun(p, 0);
        if (used[p] == 1 && len1 == 0)
            return 0;
        else if (used[p] == 0 && len1 == 0)
        {
            x[g][] = 1;
        }
    }
}
int main()
{
    scanf("%d", &n);
}