#include <iostream>
#include <cstdio>
using namespace std;
int n;
int res[10000][10], a[10], ans;
void dfs(int total, int cnt)
{
    if (cnt >= 10)
    {
        if (total == n) //不要写成了total==10
        {
            for (int i = 0; i < 10; ++i)
            {
                res[ans][i] = a[i];
            }
            ans++;
        }
    }
    else
    {
        for (int i = 1; i <= 3; ++i)
        {
            a[cnt] = i;
            dfs(total + i, cnt + 1);
            a[cnt] = 0;
        }
    }
}
int main()
{
    scanf("%d", &n);
    dfs(0, 0);
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            printf("%d%c", res[i][j], j == 9 ? '\n' : ' ');
        }
    }
    system("pause");
    return 0;
}