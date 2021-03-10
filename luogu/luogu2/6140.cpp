#include <iostream>
#include <cstdio>
using namespace std;
char name[2001];
int n;
void solve();
int main()
{
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i)
    {
        name[i] = getchar();
        getchar();
    }
    solve();
    system("pause");
    return 0;
}
void solve()
{
    int lb = 0, ub = n - 1;
    int cnt = 0;
    while (lb <= ub)
    {
        bool ju = false;
        for (int i = 0; i + lb < n; ++i)
        {
            if (name[lb + i] < name[ub - i])
            {
                ju = true;
                break;
            }
            else if (name[lb + i] > name[ub - i])
            {
                ju = false;
                break;
            }
        }
        if (ju)
        {
            printf("%c", name[lb++]);
            ++cnt;
            if(cnt==80){
                cnt=0;
                printf("\n");
            }
        }
        else
        {
            printf("%c", name[ub--]);
            ++cnt;
            if(cnt==80){
                cnt=0;
                printf("\n");
            }
        }
    }
    printf("\n");
}