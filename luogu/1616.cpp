#include <iostream>
#include<algorithm>
#include <cstdio>
using namespace std;
int dp[100001], T, M, v, t;
int main()
{
    cin >> T >> M;
    for (int i = 1; i <= M; ++i)
    {
        cin >> t >> v;
        for (int j = t; j <= T; ++j)
        {
            dp[j] = max(dp[j] ,dp[j - t] + v);
        }
    }
    cout<<dp[T]<<endl;
    system("pause");
    return 0;
}