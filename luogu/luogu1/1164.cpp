#include <iostream>
using namespace std;
int dp[101][10001], v[101], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (j > v[i])
            {
                dp[i][j] = dp[i - 1][j - v[i]] + dp[i - 1][j];
            }
             if (j == v[i])
            {
                dp[i][j] = dp[i - 1][j] + 1;
            }
            if(j<v[i])
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][m] << endl;
    system("pause");
    return 0;
}
