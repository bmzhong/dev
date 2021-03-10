#include <iostream>
#include <cstdio>
using namespace std;
int n, dp[201][201], a[202], res;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int p = 1; p < n; ++p)
    {
        for (int i = 1; i <= 2 * n - p; ++i)
        {
            int j = i + p;
            for (int k = i; k < j; ++k)
            {
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + a[i] * a[k + 1] * a[j+1]);
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        res = max(res, dp[i][i + n-1]);
    }
    cout << res << endl;
    system("pause");
    return 0;
}