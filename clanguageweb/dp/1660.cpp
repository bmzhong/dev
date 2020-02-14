#include <iostream>
#include <algorithm>
using namespace std;
int dp[20001], a[31];
int main()
{
    int n, v;
    cin >> v >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = v; j >= a[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    cout << v - dp[v] << endl;
    system("pause");
    return 0;
}
