#include <iostream>
using namespace std;
const int mod = 1000000007;
long long a[1001], b[1001], res;
int main()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << 2 << endl;
    else if (n == 2)
        cout << 8 << endl;
    else
    {
        a[1] = 1;
        b[1] = 1;
        a[2] = 6;
        b[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            b[i] = 2 * b[i - 1] % mod;
            a[i] = (2 * a[i - 1] + b[i] + 4 * a[i - 2]) % mod;
        }
        res = 4 * a[n] % mod;
        for (int i = 2; i < n; ++i)
        {
            res = (res + 2 * (2 * b[i - 1] * 2 * a[n - i])) % mod;
            res = (res + 2 * (2 * b[n - i] * 2 * a[i - 1])) % mod;
        }
        cout << res << endl;
        system("pause");
        return 0;
    }
}