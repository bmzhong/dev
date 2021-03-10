#include <iostream>
using namespace std;
int dp[5][5], a[201], b[201], ra, rb;
int main()
{
    dp[0][1] = dp[0][4] = dp[1][2] = dp[1][4] = dp[2][3] = -1;
    dp[0][2] = dp[0][3] = dp[1][3] = dp[2][4] = dp[3][4] = 1;
    for (int i = 0; i <= 4; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            dp[i][j] = -dp[j][i];
        }
    }
    int n, na, nb;
    cin >> n >> na >> nb;
    for (int i = 0; i < na; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < nb; ++i)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (dp[a[i % na]][b[i % nb]] == 1)
        {
            ++ra;
        }
        else if (dp[a[i % na]][b[i % nb]] == -1)
        {
            ++rb;
        }
    }
    cout << ra << " " << rb << endl;
    system("pause");
    return 0;
}