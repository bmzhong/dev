#include <iostream>
#include <cstdio>
using namespace std;
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
int n, m, a[10001], b[10001], used[10001], ans;
void dfs(int cnt)
{
    if (cnt == n + 1)
    {
        ++ans;
    }
    else
    {
        for (int i = 1; i <= n; ++i)
        {
            if (!ans)
                i = a[cnt];
            if (!used[i])
            {
                used[i] = 1;
                b[cnt] = i;
                dfs(cnt + 1);
                used[i] = 0;
                if (ans == m + 1)
                    return;
            }
        }
    }
}
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        printf("%d%c", b[i], i == n ? '\n' : ' ');
    }
    system("pause");
    return 0;
}