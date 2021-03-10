#include <iostream>
using namespace std;
int dp[21][1001], n, t, a[21];
int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 1;
        for (int j = 1; j <= t; ++j)
        {
            if (j >= a[i])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][t] << endl;
    system("pause");
    return 0;
}