#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int dp[101];
pair<int, int> p[101];
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.first == p2.first)
        return p1.second > p2.second;
    return p1.first > p2.first;
}
int main()
{
    int n, sum = 0, ss = 0, sf = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p + 1, p + n + 1, cmp);
    if (p[1].first > 0 && p[0].second > 0){
        
    }
        for (int i = 1; i <= n; ++i)
        {
            if ()
        }
}