#include <iostream>
using namespace std;
void select(int a[], int n);
int main()
{
    int n, c;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &c);
        a[i] = c;
    }
    select(a,n);
    for(int i=0;i<n;++i){
        printf("%d ",a[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}

void select(int a[], int n)
{
    int t;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (a[j] < a[i])
            {
                t = a[j];
                a[j] = a[i];
                a[i] = t;
            }
        }
    }
}