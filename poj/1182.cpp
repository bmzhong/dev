#include <iostream>
#include <cstdio>
using namespace std;
void unite(int x, int y);
int find_root(int x);
bool same(int x, int y);
void solve();
int a[100001], b[100001], c[100001], t[150001];
int n, k, res;
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k; ++i)
    {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
    }
    solve();
    printf("%d\n", res);
    system("pause");
    return 0;
}

void solve()
{
    for (int i = 1; i <= k; ++i)
    {
        int x = b[i], y = c[i];
        if (x < 0 || x > n || y < 0 || y > n)
        {
            ++res;
            continue;
        }
        if (a[i] == 1)
        {
            if (same(x, y + n) || same(y, x + n))
                ++res;
            else
            {
                unite(x, y);
                unite(x + n, y + n);
                unite(x + 2 * n, y + 2 * n);
            }
        }
        else
        {
            if (same(x, y) || same(y, x + n))
            {
                ++res;
            }
            else
            {
                unite(x, y + n);
                unite(x + n, y + 2 * n);
                unite(x + 2 * n, y);
            }
        }
    }
}

int find_root(int x)
{
    if (t[x] == 0)
        return x;
    else
        return t[x] = find_root(t[x]);
}

void unite(int x, int y)
{
    int x_root = find_root(x);
    int y_root = find_root(y);
    if (x_root != y_root)
        t[x_root] = y_root;
}

bool same(int x, int y)
{
    return find_root(x) == find_root(y);
}