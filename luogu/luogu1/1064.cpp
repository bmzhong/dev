#include <iostream>
#include <algorithm>
using namespace std;
int dp[61][32001], z[61][2], f1[61][2]={0}, f2[61][2]={0};
int N, M;
int main()
{
    cin >> N >> M;
    int a, b, c;
    for (int i = 1; i <= M; ++i)
    {
        cin >> a >> b >> c;
        if (c == 0)
        {
            z[i][0] = a;
            z[i][1] = b;
        }
        else
        {
            if (f1[c][0] == 0)
            {
                f1[c][0] = a;
                f1[c][1] = b;
            }
            else
            {
                f2[c][0] = a;
                f2[c][1] = b;
            }
        }
    }
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (j >= z[i][0])
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - z[i][0]] + z[i][0] * z[i][1]);
                if (j >= z[i][0] + f1[i][0])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - z[i][0] - f1[i][0]] + z[i][0] * z[i][1] + f1[i][0] * f1[i][1]);
                }
                if (j >= z[i][0] + f2[i][0])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - z[i][0] - f2[i][0]] + z[i][0] * z[i][1] + f2[i][0] * f2[i][1]);
                }
                if (j >= z[i][0] + f1[i][0] + f2[i][0])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - z[i][0] - f1[i][0] - f2[i][0]] + z[i][0] * z[i][1] + f1[i][0] * f1[i][1] + f2[i][0] * f2[i][1]);
                }
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout<<dp[M][N]<<endl;
    system("pause");
    return 0;
}