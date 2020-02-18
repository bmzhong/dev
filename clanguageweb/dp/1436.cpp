#include <iostream>
#include <algorithm>
using namespace std;
int dp[51][51][13][14], a[51][51], n, m, o, res;
int main()
{
    cin >> n >> m >> o;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
            ++a[i][j];
        }
    }
    dp[1][1][0][0] = 1;
    dp[1][1][1][a[1][1]] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int cnt = 0; cnt <= o; ++cnt)
            {
                for (int k = 0; k <= 14; ++k)
                {
                    dp[i][j][cnt][k] = (dp[i][j][cnt][k] + dp[i - 1][j][cnt][k]) % 1000000007;
                    dp[i][j][cnt][k] = (dp[i][j][cnt][k] + dp[i][j - 1][cnt][k]) % 1000000007;
                    if (cnt > 0 && k == a[i][j])
                    {
                        for (int p = 0; p < a[i][j]; ++p)
                        {
                            dp[i][j][cnt][k] = (dp[i][j][cnt][k] + dp[i - 1][j][cnt - 1][p]) % 1000000007;
                            dp[i][j][cnt][k] = (dp[i][j][cnt][k] + dp[i][j - 1][cnt - 1][p]) % 1000000007;
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= 14; ++i)
    {
        res = (res + dp[n][m][o][i]) % 1000000007;
    }
    cout << res << endl;
    system("pause");
    return 0;
}