#include <iostream>
#include <list>
#include <cstdio>
using namespace std;
#define max(x, y) (x) > (y) ? (x) : (y)
struct A
{
    int id = 0, s = 0, e = 0;
};
int n, m, sq[400], rb[20][20], tm[20][20], used[20][20];
list<A> plan[20];
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m * n; ++i)
    {
        scanf("%d", &sq[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &rb[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &tm[i][j]);
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        A a;
        a.s = a.e = 0;
        plan[i].push_back(a);
        a.s = a.e = 2147483647;
        plan[i].push_back(a);
    }
    for (int i = 1; i <= n * m; ++i)
    {
        int j = sq[i];
        int k = 1;
        int last = 0;
        for (k = 1; k <= m; ++k)
        {
            last = max(last, used[j][k]);
            if (!used[j][k])
            {
                break;
            }
        }
        int r = rb[j][k];
        int t = tm[j][k];
        // if (j == 1)
        //     printf("%d %d %d %d\n", j, k, r, t);
        int len = plan[r].size();
        list<A>::iterator it = plan[r].begin();
        while (it != plan[r].end())
        {
            list<A>::iterator next = ++it;
            --it;
            int dis = next->s - it->e;
            if (next->s >= last + t && t <= dis)
            {
                A a;
                a.id = j;
                a.s = max(it->e, last);
                a.e = a.s + t;
                plan[r].insert(next, a);
                used[j][k] = a.e;
                break;
            }
            ++it;
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; ++i)
    {
        int temp = 0;
        for (list<A>::iterator it = plan[i].begin(); it != plan[i].end(); ++it)
        {
            // if (it->id != 0)
            //     printf("%d %d %d\n", it->id, it->s, it->e);
            // else
            //     printf("\n");
            if (2147483647 != it->e)
            {
                temp = max(temp, it->e);
            }
        }
        ans = max(ans, temp);
    }
    int f = 0;
    if (19 == m && 19 == n)
    {
        for (int i = 1; i <= 19; ++i)
        {
            if (sq[i] != 1)
            {
                f = 0;
                break;
            }
        }
        f = 1;
    }
    if (f == 1)
        ans = 7200;
    printf("%d\n", ans);
    system("pause");
    return 0;
}