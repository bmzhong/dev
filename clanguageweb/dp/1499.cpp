#include <iostream>
using namespace std;
int rank_t[1001], a[1001], n, maxs = 1;
void find_root(int x, int height);
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        find_root(i, 1);
    }
    printf("%d\n",maxs);
    system("pause");
    return 0;
}

void find_root(int x, int height)
{
    if (a[x] == 0)
    {
        rank_t[x] = max(height, rank_t[x]);
        maxs = max(maxs, rank_t[x]);
    }
    else
    {
        find_root(a[x], height + 1);
    }
}