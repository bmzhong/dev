#include <iostream>
#include<cstdio>
using namespace std;
struct A
{
    int a, b, g, k;
};
A arr[100001];
int main()
{
    int res=-1,n, x, y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d%d%d", &arr[i].a, &arr[i].b, &arr[i].g, &arr[i].k);
    }
    scanf("%d%d", &x, &y);
    for(int i=1;i<=n;++i){
        if(x>=arr[i].a&&x<=arr[i].a+arr[i].g&&y>=arr[i].b&&y<=arr[i].b+arr[i].k)
            res=i;
    }
    printf("%d\n",res);
    system("pause");
    return 0;
}