#include <stdio.h>
int main()
{
    int n, x;
    scanf("%d", &n);
    int v[n + 1],h[n+1]={0};
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x);
        v[i] = x;
    }
    int sum = 0;
    int max=n-1;
    for (int i = n - 2; i >= 0; --i)
    {
        if(v[i]>v[max]){
            h[i]+=h[max]+1;
        }else{
            
        }
        sum += h[i];
    }
    printf("%d\n", sum);
    return 0;
}