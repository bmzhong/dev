#include <iostream>
#include <algorithm>
using namespace std;
int a[10003], n;
int main()
{
    cin >> n;
    for (int i = 1; i <= 10000; ++i)
    {
        a[i] = i * (i - 1) / 2 + 1;
    }
    int k = lower_bound(a + 1, a + 10001, n) - a;
    if (a[k] != n)
        --k;
    if (k & 1)
    {
        cout << k - (n - a[k]) << "/" << 1 + n - a[k] << endl;
    }
    else
    {
        cout << 1 + n - a[k] << "/" << k - (n - a[k]) << endl;
    }
    system("pause");
    return 0;
}