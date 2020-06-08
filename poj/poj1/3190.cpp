#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int use[50005], n, stall = 1;
struct Cow
{
    int l, r, p;
    bool operator<(const Cow &cow) const
    {
        if (r == cow.r)
            return l > cow.l;
        return r > cow.r;
    }
};
Cow cow[50005];
bool cmp(const Cow cow1, const Cow cow2)
{
    if (cow1.l == cow2.l)
        return cow1.r < cow2.r;
    return cow1.l < cow2.l;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &cow[i].l, &cow[i].r);
        cow[i].p = i;
    }
    sort(cow, cow + n, cmp);
    priority_queue<Cow> q;
    use[cow[0].p] = 1;
    q.push(cow[0]);
    for (int i = 1; i < n; ++i)
    {
        Cow c = q.top();
        if (cow[i].l > c.r)
        {
            use[cow[i].p] = use[c.p];
            q.pop();
            q.push(cow[i]);
        }
        else
        {
            ++stall;
            use[cow[i].p] = stall;
            q.push(cow[i]);
        }
    }
    printf("%d\n", stall);
    for (int i = 0; i < n; ++i)
    {
        printf("%d\n", use[i]);
    }
    system("pause");
    return 0;
}
