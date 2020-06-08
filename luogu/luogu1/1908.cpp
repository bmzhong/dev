#include <iostream>
#include <stdio.h>
using namespace std;
int a[1000000], b[1000000];
int n;
long long sum = 0;
void merge_sort(int x, int y);
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    merge_sort(0, n);
    printf("%lld\n", sum);
    system("pause");
    return 0;
}

void merge_sort(int x, int y)
{
    if (y - x > 1)
    {
        int m = x + (y - x) / 2;
        merge_sort(x, m);
        merge_sort(m, y);
        int i = x, j = m, k = x;
        while (i < m || j < y)
        {
            if (j >= y || (i < m && a[i] <= a[j]))
                b[k++] = a[i++];
            else
            {
                b[k++] = a[j++];
                sum += m - i;
            }
        }
        k = x;
        while (k < y)
        {
            a[k] = b[k];
            ++k;
        }
    }
}
