#include <iostream>
using namespace std;
int partition(int a[], int x, int y)
{
    int d = a[x];
    while (x < y)
    {
        while (x < y && a[y] > d)
            --y;
        a[x] = a[y];
        while (x < y && a[x] < d)
            ++x;
        a[y] = a[x];
    }
    a[x] = d;
    return x;
}

void sort(int a[], int x, int y)
{
    int m = partition(a, x, y);
    if (m - 1 > x)
    {
        sort(a, x, m - 1);
    }
    if (m + 1 < y)
    {
        sort(a, m + 1, y);
    }
}
int main()
{
    int n, c;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d",&c);
        a[i] = c;
    }
    sort(a, 0, n - 1);
    for (int i = 0; i < n - 1; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
    system("pause");
    return 0;
}