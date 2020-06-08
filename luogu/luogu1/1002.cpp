#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
long long dp[21][21];
int m, n, bx, by, res;

int main()
{
    cin >> n >> m >> bx >> by;
    set<pair<int, int> > s;
    s.insert(pair<int, int>(bx, by));
    if (bx - 1 >= 0 && by - 2 >= 0)
    {
        s.insert(pair<int, int>(bx - 1, by - 2));
    }
    if (bx - 2 >= 0 && by - 1 >= 0)
    {
        s.insert(pair<int, int>(bx - 2, by - 1));
    }
    if (bx - 2 >= 0 && by + 1 <= m)
    {
        s.insert(pair<int, int>(bx -2, by + 1));
    }
    if (bx - 1 >= 0 && by + 2 <= m)
    {
        s.insert(pair<int, int>(bx - 1, by + 2));
    }
    if (bx + 1 <= n && by + 2 <= m)
    {
        s.insert(pair<int, int>(bx + 1, by + 2));
    }
    if (bx + 2 <= n && by + 1 <= m)
    {
        s.insert(pair<int, int>(bx + 2, by + 1));
    }
    if (bx + 2 <= n && by - 1 >= 0)
    {
        s.insert(pair<int, int>(bx + 2, by - 1));
    }
    if (bx + 1 <= n && by - 2 >= 0)
    {
        s.insert(pair<int, int>(bx + 1, by - 2));
    }
    for (int i = 0; i <= n; ++i)
    {
        if (s.count(pair<int, int>(i, 0)) == 0)
        {
            if (!i)
                dp[i][0] = 1;
            else
                dp[i][0] = dp[i - 1][0];
        }
        else
            dp[i][0] = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (s.count(pair<int, int>(i, j)) == 1)
            {
                dp[i][j] = 0;
                continue;
            }
            if (i == 0)
            {
                dp[i][j] = dp[i][j-1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n][m] << endl;
    system("pause");
    return 0;
}