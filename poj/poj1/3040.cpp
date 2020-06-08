#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include<functional>
using namespace std;
int n, c, ans = 0, use[25];
pair<int, int> p[21];
int main()
{
    scanf("%d%d", &n, &c);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p, p + n, greater<pair<int, int> >() );
    for (int i = 0; i < n; ++i)
    {
        if (p[i].first >= c)
        {
            ans += p[i].second;
            p[i].second = 0;
        }
    }
    while (true)
    {
        memset(use, 0, sizeof(use));
        int cnt = c, flag = 0;
        for (int i = 0; i < n; ++i)
        {
            int k = cnt / p[i].first;
            int mins = min(k, p[i].second);
            use[i] = mins;
            cnt -= mins * p[i].first;
            if (cnt == 0)
            {
                flag = 1;
                break;
            }
        }
        if (cnt > 0)
        {
            for (int i = n - 1; i >= 0; --i)
            {
                while (p[i].second > use[i])
                {
                    cnt -= p[i].first;
                    use[i]++;
                    if (cnt <= 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
        if (!flag)
            break;
        int small = 99999999;
        for (int i = 0; i < n; ++i)
        {
            if (use[i])
            {
                small = min(small, p[i].second / use[i]);
            }
        }
        ans += small;
        for (int i = 0; i < n; ++i)
        {
            p[i].second -= small * use[i];
        }
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}