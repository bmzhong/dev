#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> p[250005];
int N, T, ans=0;
int main()
{
    scanf("%d%d", &N, &T);
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p + 1, p + N+1);
    int r = 0, i = 0;
    while (r < T)
    {
        int maxs = -1;
        while (p[++i].first <= r + 1&&i<=N)
            maxs = p[i].second > maxs ? p[i].second : maxs;
        if (maxs == -1)
        {
            ans = -1;
            break;
        }
        ++ans;
        --i;
        r = maxs;
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}