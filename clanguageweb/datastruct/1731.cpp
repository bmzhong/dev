#include <stdio.h>
void func(int *sum, int m, int n);
int main()
{
    int m, n;
    while (scanf("%d %d",&m,&n)!=EOF&& !(m == 0 && n == 0))
    {
        int sum = 0;
        func(&sum, m, n);
        printf("%d\n",sum);
    }
    return 0;
}

void func(int *sum, int m, int n)
{
    if (m <= n)
    {
        *sum+=1;
        func(sum, 2 * m, n);
        func(sum, 2 * m + 1, n);
    }
}