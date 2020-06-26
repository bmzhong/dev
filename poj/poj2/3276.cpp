#include <iostream>
#include <cstring>
using namespace std;
int n, a[5001], f[5001];
void fun();
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        char ch;
        cin >> ch;
        if (ch == 'B')
            a[i] = 1;
        else
            a[i] = 0;
    }
    fun();
    system("pause");
    return 0;
}

int cal(int k)
{
    int sum = 0;
    int res = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i + k - 1 <= n; ++i)
    {
        if ((a[i] + sum) % 2 == 1)
        {
            f[i] = 1;
            ++res;
        }
        sum += f[i];
        if (i - k + 1 > 0)
        {
            sum -= f[i - k + 1];
        }
    }
    for (int i = n - k + 2; i <= n; ++i)
    {
        if ((a[i] + sum) % 2 == 1)
        {
            return -1;
        }
        if (i - k + 1 > 0)
        {
            sum -= f[i - k + 1];
        }
    }
    return res;
}

void fun()
{
    int m = n, k = 1;
    for (int i = 1; i <= n; ++i)
    {
        int t = cal(i);
        if (t != -1 && t < m)
        {
            m = t;
            k = i;
        }
    }
    cout << k << " " << m << endl;
}