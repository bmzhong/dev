#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int dp[1005], N, M, R, res;
struct A
{
    int start, end, effi;
};
A p[1005];
bool cmp(const A p1, const A p2)
{
    if (p1.end == p2.end)
        return p1.start < p2.start;
    return p1.end < p2.end;
}
int main()
{
    scanf("%d%d%d", &N, &M, &R);
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &p[i].start, &p[i].end, &p[i].effi);
    }
    sort(p, p + M, cmp);
    for (int i = 0; i < M; ++i)
    {
        dp[i] = p[i].effi;
        for (int j = 0; j < i; ++j)
        {
            if (p[j].end + R <= p[i].start)
                dp[i] = max(dp[i], dp[j] + p[i].effi);
        }
        res = max(res, dp[i]);
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}