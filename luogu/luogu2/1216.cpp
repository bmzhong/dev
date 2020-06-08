#include <iostream>
using namespace std;
int dp[1001][1001], a[1001][1001];
int n;
#define MAX(x, y) (x) > (y) ? (x) : (y)
int res = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            dp[i][j] = MAX(dp[i - 1][j - 1] + a[i][j], dp[i - 1][j] + a[i][j]);
            res = MAX(dp[i][j], res);
        }
    }
    cout << res << endl;
    system("pause");
    return 0;
}
