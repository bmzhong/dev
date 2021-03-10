// #include <iostream>
// using namespace std;
// int partition(int a[], int x, int y);
// void sort(int a[], int x, int y);
// int main()
// {
//     int n;
//     while (scanf("%d", &n) != EOF)
//     {
//         int a[n + 1];
//         for (int i = 1; i <= n; ++i)
//         {
//             scanf("%d", &a[i]);
//         }
//         sort(a, 1, n);
//         for (int i = 1; i <= n - 1; ++i)
//         {
//             printf("%d ", a[i]);
//         }
//         printf("%d\n", a[n]);
//     }
//     return 0;
// }
// int partition(int a[], int x, int y)
// {
//     a[0] = a[x];
//     while (x < y)
//     {
//         while (x < y && a[y] > a[0])
//             --y;
//         a[x] = a[y];
//         while (x < y && a[x] < a[0])
//             ++x;
//         a[y] = a[x];
//     }
//     a[x] = a[0];
//     return x;
// }

// void sort(int a[], int x, int y)
// {
//     if (y > x)
//     {
//         int m = partition(a, x, y);
//         sort(a, x, m - 1);
//         sort(a, m + 1, y);
//     }
// }
#include <iostream>
#include <set>
using namespace std;
int main()
{
    int n, a;
    multiset<int> s;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        s.insert(a);
    }
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;
    multiset<int>().swap(s);
    system("pause");
    return 0;
}