#include <iostream>
#include <stdio.h>
void func1(int x, int y, int *sum);
int v[500000];
int main()
{
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        v[i] = x;
    }
    int sum = 0;
    func1(0, n - 1, &sum);
    printf("%d\n", sum);
    system("pause");
    return 0;
}

void func1(int x, int y, int *sum)
{
    if (y == x)
    {
        return;
    }
    int m;
    if (y - x > 1)
    {
        m = x + (y - x) / 2;
        func1(x, m - 1, sum);
        func1(m, y, sum);
        for (int i = m; i <= y; ++i)
        {
            for (int j = x; j < m; ++j)
            {
                if (v[j] > v[i])
                {
                    ++(*sum);
                }
            }
        }
    }
    else if (y - x == 1)
    {
        if (v[x] > v[y])
        {
            ++(*sum);
        }
    }
}