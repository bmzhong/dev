#include <iostream>
#include <cstdio>
using namespace std;
int k, x, y;
void solve(int x, int y, int a, int b, int n)
{
    if (n == 1)
        return;
    if (x - a + 1 <= n / 2 && y - b + 1 <= n / 2)
    {
        printf("%d %d 1\n", a + n / 2, b + n / 2);
        solve(x, y, a, b, n / 2);
        solve(a + n / 2 - 1, b + n / 2, a, b + n / 2, n / 2);
        solve(a + n / 2, b + n / 2 - 1, a + n / 2, b, n / 2);
        solve(a + n / 2, b + n / 2, a + n / 2, b + n / 2, n / 2);
    }
    else if (x - a + 1 <= n / 2 && y - b + 1 > n / 2)
    {
        printf("%d %d 2\n", a + n / 2, b + n / 2 - 1);
        solve(a + n / 2 - 1, b + n / 2 - 1, a, b, n / 2);
        solve(x, y, a, b + n / 2, n / 2);
        solve(a + n / 2, b + n / 2 - 1, a + n / 2, b, n / 2);
        solve(a + n / 2, b + n / 2, a + n / 2, b + n / 2, n / 2);
    }
    else if (x - a + 1 > n / 2 && y - b + 1 <= n / 2)
    {
        printf("%d %d 3\n", a + n / 2 - 1, b + n / 2);
        solve(a + n / 2 - 1, b + n / 2 - 1, a, b, n / 2);
        solve(a + n / 2 - 1, b + n / 2, a, b + n / 2, n / 2);
        solve(x, y, a + n / 2, b, n / 2);
        solve(a + n / 2, b + n / 2, a + n / 2, b + n / 2, n / 2);
    }
    else
    {
        printf("%d %d 4\n", a + n / 2 - 1, b + n / 2 - 1);
        solve(a + n / 2 - 1, b + n / 2 - 1, a, b, n / 2);
        solve(a + n / 2 - 1, b + n / 2, a, b + n / 2, n / 2);
        solve(a + n / 2, b + n / 2 - 1, a + n / 2, b, n / 2);
        solve(x, y, a + n / 2, b + n / 2, n / 2);
    }
}
int main()
{
    scanf("%d%d%d", &k, &x, &y);
    solve(x, y, 1, 1, 1 << k);
    system("pause");
    return 0;
}
