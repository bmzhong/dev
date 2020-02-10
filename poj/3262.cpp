#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct A
{
    pair<int, int> p;
    bool operator<(const A &a) const
    {
        return (double)p.second / p.first < (double)a.p.second / a.p.first;
    }
};
int main()
{
    long long ans = 0, sumd = 0;
    int n;
    pair<int, int> p;
    scanf("%d", &n);
    priority_queue<A> q;
    A a;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &a.p.first, &a.p.second);
        q.push(a);
        sumd += a.p.second;
    }
    while (!q.empty())
    {
        a = q.top();
        q.pop();
        sumd -= a.p.second;
        ans += 2 * sumd * a.p.first;
    }
    printf("%lld\n", ans);
    system("pause");
    return 0;
}