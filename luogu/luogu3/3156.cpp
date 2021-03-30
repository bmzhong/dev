#include <iostream>
using namespace std;
int n, m, a[2000001];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        int t;
        scanf("%d", &t);
        printf("%d\n", a[t]);
    }
    system("pause");
    return 0;
}