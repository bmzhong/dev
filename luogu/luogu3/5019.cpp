#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int n, a[100005];
long long ans = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
        if (a[i] > a[i - 1])
            ans += a[i] - a[i - 1];
    cout << ans + a[1];
    system("pause");
    return 0;
}
// #include <iostream>
// #include <cstdio>
// #include <algorithm>

// using namespace std;
// int n, a[100010], ans = 0;

// void binary(int x, int y) {
//     if (x > y)
//         return;
//     int s = -1, f = 0, e = -1, mins = 214748347;
//     for (int i = x; i <= y; ++i) {
//         if (a[i] < mins)
//             mins = a[i];
//         if (a[i] != 0) {
//             if (s == -1)
//                 s = i;
//             if (i == y) {
//                 e = y;
//                 if (s == x) {
//                     for (int j = s; j <= e; ++j) {
//                         a[j] -= mins;
//                     }
//                     ans += mins;
//                     f = 1;
//                 }
//                 binary(s, y);
//             }
//         } else {
//             f = 1;
//             if (s != -1) {
//                 e = i - 1;
//                 binary(s, e);
//                 s = e = -1;
//             }
//         }
//     }
//     if (f == 0) {
//         for (int i = x; i <= y; ++i) {
//             a[i] -= mins;
//         }
//         ans += mins;
//     }
// }

// int main() {
//     scanf("%d", &n);
//     for (int i = 0; i < n; ++i) {
//         scanf("%d", &a[i]);
//     }
//     binary(0, n - 1);
//     printf("%d\n", ans);
//     system("pause");
//     return 0;
// }