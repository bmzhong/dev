#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, q, query;
    int a[10000];
    int sum;
    int index = 0;
    while (scanf("%d%d", &n, &q) == 2 && n)
    {
        printf("CASE# %d:\n", ++index);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < q; ++i)
        {
            scanf("%d", &query);
            int *d = lower_bound(a, a + n, query);
            if (*d == query)
            {
                printf("%d found at %d\n", query, d - a + 1);
            }
            else
            {
                printf("%d not found\n", &query);
            }
        }
    }
    system("pause");
    return 0;
}