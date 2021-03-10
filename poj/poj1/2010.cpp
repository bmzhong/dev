#include <iostream>
#include <queue>
#include<cstdio>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
pair<int, int> p[100001];
int lower[100001], upper[100001], c, n, f, res = -1;
priority_queue<int> q1, q2;
int main()
{
    scanf("%d%d%d", &n, &c, &f);
    for (int i = 1; i <= c; ++i)
    {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    int total1 = 0, total2 = 0;
    sort(p + 1, p + c + 1);
    for (int i = 1; i <= c; ++i)
    {
        if (q1.size() == n / 2)
            lower[i] = total1;
        else
            lower[i] = inf;
        if (q2.size() == n / 2)
            upper[c - i+1] = total2;
        else
            upper[c - i+1] = inf;
        q1.push(p[i].second);
        total1 += p[i].second;
        if (q1.size() > n / 2)
        {
            total1 -= q1.top();
            q1.pop();
        }
        q2.push(p[c - i+1].second);
        total2 += p[c - i+1].second;
        if (q2.size() > n / 2)
        {
            total2 -= q2.top();
            q2.pop();
        }
    }
    for (int i = c; i > 0; --i)
    {
        if (upper[i] != inf && lower[i] != inf && upper[i] + lower[i] + p[i].second <= f)
        {
            res = p[i].first;
            break;
        }
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}