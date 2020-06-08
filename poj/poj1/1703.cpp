#include <iostream>
#include <cstdio>
using namespace std;
class A
{
public:
    int pe;
    int pf;
};
A a[500001];
int n, t, m;
int find_root(int x);
void unite(int x, int y);
bool same(int x, int y);
int main()
{
    scanf("%d", &t);
    for (int j = 1; j <= t; ++j)
    {
        char ch;
        int dx, dy;
        scanf("%d%d", &n, &m);
        getchar();
        for (int i = 1; i <= n; ++i)
        {
            a[i].pe = a[i].pf = 0;
        }
        for (int i = 1; i <= m; ++i)
        {
            scanf("%c %d %d", &ch, &dx, &dy);
            getchar();
            if (ch == 'D')
            {
                if (a[dx].pe || a[dy].pe)
                {
                    unite(a[dx].pe, dy);
                    unite(a[dy].pe, dx);
                }
                else
                {
                    a[dx].pe = dy;
                    a[dy].pe = dx;
                }
            }
            else
            {
                if (n == 2)
                    printf("In different gangs.\n");
                else if (same(dx, dy))
                    printf("In the same gang.\n");
                else if (a[dx].pe && same(a[dx].pe, dy))
                    printf("In different gangs.\n");
                else if (a[dy].pe && same(a[dy].pe, dx))
                    printf("In different gangs.\n");
                else
                    printf("Not sure yet.\n");
            }
        }
    }
    system("pause");
    return 0;
}

int find_root(int x)
{
    if (!a[x].pf)
        return x;
    return a[x].pf = find_root(a[x].pf);
}

void unite(int x, int y)
{
    if (!x || !y)
        return;
    int x_root = find_root(x);
    int y_root = find_root(y);
    if (x_root != y_root)
        a[x_root].pf = y_root;
}

bool same(int x, int y)
{
    return find_root(x) == find_root(y);
}