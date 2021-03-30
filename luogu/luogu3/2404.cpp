#include <iostream>
#include <cstdio>
using namespace std;
int n, a[9] = {1};
void dfs(int s, int t)
{
    for (int i = a[t - 1]; i <= s; ++i)
    {
        if (i < n)
        {
            a[t] = i;
            s -= i;
            if (s == 0)
            {
                for (int i = 1; i < t; ++i)
                {
                    printf("%d+", a[i]);
                }
                printf("%d\n", a[t]);
            }
            else
                dfs(s, t + 1);
            s += i;
        }
    }
}
int main()
{
    scanf("%d", &n);
    dfs(n, 1);
    system("pause");
    return 0;
}