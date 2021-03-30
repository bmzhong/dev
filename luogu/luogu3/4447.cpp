#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct A
{
    int v = 0, cnt = 0;
};
int n, b[100001], ans = 2147483647;
A a[100001];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &b[i]);
    }
    sort(b, b + n);
    int cnt = 1, m = 0;
    for (int i = 1; i < n; ++i)
    {

        if (b[i] == b[i - 1])
            ++cnt;
        else
        {
            a[m].v = b[i - 1];
            a[m++].cnt = cnt;
            cnt = 1;
        }
    }
    a[m].v = b[n - 1];
    a[m++].cnt = cnt;
    cnt = 1;
    int i = 0;
    while (i < m)
    {
        cnt = 1;
        --a[i].cnt;
        while (i + 1 < m && a[i + 1].v == a[i].v + 1 && a[i + 1].cnt > a[i].cnt)
        {
            --a[i + 1].cnt;
            ++cnt;
            ++i;
        }
        if (cnt < ans)
            ans = cnt;
        int j = i - cnt + 1;
        for (; j <= i; ++j)
        {
            if (a[j].cnt > 0) //应该找第一个非0的位置，而不是0的位置。
            {
                i = j;
                break;
            }
        }
        //注意应该判断是否会死循环
        if (j == i + 1) //不能写成j=i+1
            ++i;
    }
    if (ans == 2147483647)
        ans = cnt;
    printf("%d\n", ans);
    system("pause");
    return 0;
}