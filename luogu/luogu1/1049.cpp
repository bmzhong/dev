#include <iostream>
#include <algorithm>
using namespace std;
int dp[31][20001], v[31], n, m;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (j >= v[i])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout<<m-dp[n][m]<<endl;
    system("pause");
    return 0;
}