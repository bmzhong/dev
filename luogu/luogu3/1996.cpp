#include <iostream>
#include <cstdio>
using namespace std;
int a[201], n, m;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        a[i] = i;
    }
    int j = 1, c = 0;
    while (true)
    {
        int i = j, cnt = 0;
        for (; i <= n + 1; ++i)
        {
            if (i > n)
                i = 1;
            if (a[i] != 0)
                ++cnt;
            if (cnt == m)
                break;
        }
        ++c;
        printf("%d%c", i, c == n ? '\n' : ' ');
        a[i] = 0;
        int k = i + 1;
        for (; k <= n + 1; ++k)
        {
            if (k > n)
                k = 1;
            if (a[k] != 0)
                break;
            if (k == i)
                break;
        }
        if (k == i)
            break;
        else
            j = k;
    }
    system("pause");
    return 0;
}