#include <iostream>
#include <cstdio>
using namespace std;
int n, a[300];
void print()
{
    for (int i = 1; i <= 2 * n + 2; ++i)
    {
        if (a[i] == 0)
            printf("o");
        else if (1 == a[i])
            printf("*");
        else
            printf("-");
    }
    printf("\n");
}
void dfs(int k)
{
    if (k > 4)
    {
        print();
        a[k] = a[k + 1] = -1;
        a[2 * k + 1] = 0;
        a[2 * k + 2] = 1;
        print();
        a[k] = a[k + 1] = 1;
        a[2 * k] = a[2 * k - 1] = -1;
        dfs(k - 1);
    }
    else
    {
        print();
        a[k] = a[k + 1] = -1;
        a[2 * k + 1] = 0;
        a[2 * k + 2] = 1;
        print();
        a[2 * k] = a[2 * k + 1] = -1;
        a[k] = 1;
        a[k + 1] = 0;
        print();
        a[2] = a[3] = -1;
        a[2 * k] = a[2 * k + 1] = 0;
        print();
        a[7] = a[8] = -1;
        a[2] = 1;
        a[3] = 0;
        print();
        a[7] = 0;
        a[8] = 1;
        a[1] = a[2] = -1;
        print();
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; ++i)
    {
        if (i <= n)
            a[i] = 0;
        else
            a[i] = 1;
    }
    a[2 * n + 1] = a[2 * n + 2] = -1;
    dfs(n);
    system("pause");
    return 0;
}