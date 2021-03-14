#include <iostream>
#include <cstdio>
using namespace std;
int n, a[2001] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, res, b[3];
void dfs(int k)
{
    for (int i = 0; i < 1000; ++i)
    {
        if (n - a[i] >= 0)
        {
            n -= a[i];
            b[k] = i;
            if (k == 2)
            {
                if (b[0] + b[1] == b[2] && n == 0)
                    ++res;
            }
            else
                dfs(k + 1);
            n += a[i];
        }
    }
}
int main()
{
    scanf("%d", &n);
    n -= 4;
    for (int i = 10; i < 2000; ++i)
    {
        a[i] = a[i / 10] + a[i % 10];
    }
    dfs(0);
    printf("%d\n", res);
    system("pause");
    return 0;
}
// #include <iostream>
// #include <cstdio>
// using namespace std;
// int n, a[2001] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6},res;
// int main()
// {
//     scanf("%d", &n);
//     n -= 4;
//     for (int i = 10; i < 2000; ++i)
//     {
//         a[i] = a[i / 10] + a[i % 10];
//     }
//     for (int i = 0; i < 1000; ++i)
//     {
//         for (int j = 0; j < 1000; ++j)
//         {
//             if (a[i] + a[j] + a[i + j] == n)
//             {
//                 ++res;
//             }
//         }
//     }
//     printf("%d\n", res);
//     system("pause");
//     return 0;
// }