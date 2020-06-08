#include <iostream>
using namespace std;
int a[100000], n;
int partition(int x, int y);
void quick_sort(int x, int y);
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    quick_sort(1, n);
    for (int i = 1; i <= n - 1; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n]);
    system("pause");
    return 0;
}

int partition(int x, int y)
{
    int m = (x + y) / 2;
    a[0] = a[m];
    int low = x, high = y;
    a[m] = a[low];
    while (low < high)
    {
        while (low < high && a[high] >= a[0])
            --high;
        a[low] = a[high];
        while (low < high && a[low] <= a[0])
            ++low;
        a[high] = a[low];
    }
    a[low] = a[0];
    return low;
}

void quick_sort(int x, int y)
{
    int m = partition(x, y);
    if (m > x)
        quick_sort(x, m - 1);
    if (y > m)
        quick_sort(m + 1, y);
}