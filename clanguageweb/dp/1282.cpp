#include <iostream>
#include <algorithm>
using namespace std;
int dp[101], a[11];
int main()
{
    for (int i = 1; i <= 10; ++i)
    {
        cin >> a[i];
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] + a[1];
        for (int j = 1; j <= i && j <= 10; ++j)
        {
            dp[i] = min(dp[i - j] + a[j], dp[i]);
        }
    }
    cout << dp[n] << endl;
    system("pause");
    return 0;
}