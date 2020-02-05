#include <iostream>
#include <stdio.h>
using namespace std;
int a[100000001], n, q, c[1000001];
void init();
void delete_num();
int main()
{
    int t;
    scanf("%d%d", &n, &q);
    init();
    delete_num();
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &t);
        printf("%d\n", c[t]);
    }
    system("pause");
    return 0;
}
void init()
{
    for (int i = 2; i <= n; ++i)
    {
        a[i] = i;
    }
}
void delete_num()
{
    int p = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i])
        {
            c[p++] = i;
            if(p>1000000){
                break;
            }
            for (int j = 2 * i; j <= n; j += i)
            {
                a[j] = 0;
            }
        }
    }
}
