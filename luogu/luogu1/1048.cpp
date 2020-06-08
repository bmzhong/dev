#include <iostream>
#include <algorithm>
using namespace std;
int dp[101][1001], t[101], v[101], T, M;
int main()
{
    cin >> T >> M;
    for (int i = 1; i <= M; ++i)
    {
        cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= T; ++j)
        {
            if (j >= t[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]);
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[M][T]<<endl;
    system("pause");
    return 0;
}