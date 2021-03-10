#include <iostream>
#include <algorithm>
using namespace std;
long long dp[101][101], n;
int main()
{
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = 1;
        for (int j = 0; j <= n; ++j)
        {

            dp[i][j] = dp[i - 1][j];
            if (j >= i)
                dp[i][j] += dp[i][j - i];
        }
    }
    cout << dp[n][n] << endl;
    system("pause");
    return 0;
}