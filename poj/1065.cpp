#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
pair<int, int> p[5001];
int use[5001];
bool cmp(const pair<int, int> p1, const pair<int, int> p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int y = 0; y < t; ++y)
    {
        int n,k = 0, flag = 1, res = 0;
        scanf("%d", &n);
        memset(use, 0, sizeof(use));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d", &p[i].first, &p[i].second);
        }
        sort(p, p + n, cmp);
        pair<int, int> temp = p[0];
        while (res < n && flag)
        {
            flag = 0, k = 0;
            while (use[k])
                ++k;
            temp = p[k];
            for (int i = 0; i < n; ++i)
            {

                if (!use[i] && p[i].first >= temp.first && p[i].second >= temp.second)
                {
                    use[i] = 1;
                    flag = 1;
                    temp = p[i];
                }
            }
            if (flag)
                ++res;
        }
        printf("%d\n", res);
    }

    system("pause");
    return 0;
}
