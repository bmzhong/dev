#include <iostream>
#include <cstdio>
using namespace std;
int n, r, a[22], b[22], used[22];
void dfs(int cnt)
{
    if (cnt == r)
    {
        for (int i = 0; i < r; ++i)
        {
            printf("%3d", b[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
            {
                if (cnt == 0 || a[i] > b[cnt - 1])
                {
                    used[i] = 1;
                    b[cnt] = a[i];
                    dfs(cnt + 1);
                    used[i] = 0;
                }
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; ++i)
    {
        a[i] = i + 1;
    }
    dfs(0);
    system("pause");
    return 0;
}