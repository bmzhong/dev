// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// using namespace std;
// inline int read()
// {
//     int x = 0, f = 1;
//     char ch = getchar();
//     while (ch < '0' || ch > '9')
//     {
//         if (ch == '-')
//             f = -1;
//         ch = getchar();
//     }
//     while (ch >= '0' && ch <= '9')
//     {
//         x = (x << 3) + (x << 1) + (ch ^ 48);
//         ch = getchar();
//     }
//     return x * f;
// }
// int s[4], a[4][21], ans, dp[1201];
// int main()
// {
//     for (int i = 0; i < 4; ++i)
//     {
//         s[i] = read();
//     }
//     for (int i = 0; i < 4; ++i)
//     {
//         int sum = 0;
//         for (int j = 0; j < s[i]; ++j)
//         {
//             a[i][j] = read();
//             sum += a[i][j];
//         }
//         for (int j = 0; j < s[i]; ++j)
//         {
//             for (int k = sum / 2; k >= a[i][j]; --k)
//             {
//                 dp[k] = max(dp[k], dp[k - a[i][j]] + a[i][j]);
//             }
//         }
//         ans += sum - dp[sum / 2];
//         for (int k = sum / 2; k >= 0; --k)
//         {
//             dp[k] = 0;
//         }
//     }
//     printf("%d\n", ans);
//     system("pause");
//     return 0;
// }
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int s[4], a[4][21], ans, dp[1201], lef, rig, mins = 2147483647;
void dfs(int i, int k)
{
    if (k == s[i])
        mins = min(max(lef, rig), mins);
    else
    {
        lef += a[i][k];
        dfs(i, k + 1);
        lef -= a[i][k];
        rig += a[i][k];
        dfs(i, k + 1);
        rig -= a[i][k];
    }
}
int main()
{
    for (int i = 0; i < 4; ++i)
    {
        s[i] = read();
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < s[i]; ++j)
        {
            a[i][j] = read();
        }
        dfs(i, 0);
        ans += mins;
        mins = 2147483647;
        lef = rig = 0;
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}
