#include <iostream>
using namespace std;
int dp[1000002];
int main()
{
    int n;
    dp[1] = 1;
    dp[2] = 2;
    cin >> n;
    int i = 3;
    while (i <= n)
    {
        dp[i++] = dp[i - 1];
        dp[i++] = (dp[i - 1] + dp[i >> 1]) % 1000000000;
    }
    cout<<dp[n]<<endl;
    system("pause");
    return 0;
}
