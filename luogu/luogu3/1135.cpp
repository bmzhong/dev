#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n, a, b, h[201], cnt[201];
queue<int> que;
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &h[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        cnt[i] = 2147483647;
    }
    cnt[a] = 0;
    que.push(a);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        if (u + h[u] <= n && cnt[u + h[u]] > cnt[u] + 1)
        {
            cnt[u + h[u]] = cnt[u] + 1;
            que.push(u + h[u]);
        }
        if (u - h[u] >= 1 && cnt[u - h[u]] > cnt[u] + 1)
        {
            cnt[u - h[u]] = cnt[u] + 1;
            que.push(u - h[u]);
        }
    }
    if (cnt[b] == 2147483647)
        cnt[b] = -1;
    printf("%d\n", cnt[b]);
    system("pause");
    return 0;
}