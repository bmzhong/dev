#include <iostream>
#include <cstdio>
using namespace std;
int n, a[10], b[10], used[10];
void dfs(int k)
{
    if (k == n)
    {
        for (int i = 0; i < n; ++i)
        {
            printf("%5d", b[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            if (!used[i])
            {
                used[i] = 1;
                b[k] = a[i];
                dfs(k + 1);
                used[i] = 0;
            }
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = i + 1;
    }
    dfs(0);
    system("pause");
    return 0;
}