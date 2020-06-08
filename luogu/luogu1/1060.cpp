#include <iostream>
#include <algorithm>
using namespace std;
int dp[26][30001], n, m, v[26], w[26];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (j >= v[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i] * w[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout<<dp[m][n]<<endl;
    system("pause");
    return 0;
}
