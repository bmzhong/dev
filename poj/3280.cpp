#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int n, m, ans, cost[27], dp[2020][2020];
string str;
int main()
{
    cin >> n >> m;
    cin >> str;
    char t;
    int c, d;
    for (int i = 0; i < n; ++i)
    {
        cin >> t >> c >> d;
        cost[t - 'a'] = min(c, d);
    }
    for (int i = m - 1; i >= 0; --i)
    {
        for (int j = i + 1; j < m; ++j)
        {
            if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = min(dp[i + 1][j] + cost[str[i] - 'a'], dp[i][j - 1] + cost[str[j] - 'a']);
        }
    }
    cout<<dp[0][m-1]<<endl;
    system("pause");
    return 0;
}