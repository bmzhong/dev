#include <iostream>
using namespace std;
long long dp[1001][1001];
int lose[1001], win[1001], use[1001], n, x;
#define MAX(x, y) (x) > (y) ? (x) : (y)
int main()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> lose[i] >> win[i] >> use[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= x; ++j)
        {
            if (j >= use[i])
            {
                dp[i][j] = MAX(dp[i - 1][j] + lose[i], win[i] + dp[i - 1][j - use[i]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j] + lose[i];
            }
        }
    }
    cout<<dp[n][x]*5<<endl;
    system("pause");
    return 0;
}