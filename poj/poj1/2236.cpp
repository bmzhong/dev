#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
struct A
{
    int x, y, p;
};
A a[1010];
int n, d;
void repair(int x);
int find_root(int x);
bool same(int x, int y);
void unite(int x, int y);
int main()
{
    char ch;
    int dx, dy;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        a[i].p = 0;
    }
    while (cin >> ch)
    {
        if (ch == 'O')
        {
            cin >> dx;
            repair(dx);
        }
        else
        {
            cin >> dx >> dy;
            if (a[dx].p && a[dy].p && same(dx, dy))
                cout << "SUCCESS\n";
            else
            {
                cout << "FAIL\n";
            }
        }
    }
    system("pause");
    return 0;
}

int find_root(int x)
{
    if (a[x].p == x)
        return x;
    else
        return a[x].p = find_root(a[x].p);
}

bool same(int x, int y)
{
    return find_root(x) == find_root(y);
}

void unite(int x, int y)
{
    int x_root = find_root(x);
    int y_root = find_root(y);
    if (x_root != y_root)
        a[x_root].p = y_root;
}

void repair(int x)
{
    int flag = 0;
    if (a[x].p)
        return;
    for (int i = 1; i <= n; ++i)
    {
        if (a[i].p)
        {
            double dx = (a[i].x - a[x].x) * (a[i].x - a[x].x) + (a[i].y - a[x].y) * (a[i].y - a[x].y);
            if (!same(x, i) && sqrt(dx)<=d)
            {
                unite(x, i);
                flag = 1;
            }
        }
    }
    if (!flag)
        a[x].p = x;
}