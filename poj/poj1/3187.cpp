#include <iostream>
#include <algorithm>
using namespace std;
int a[10], b[10], c[10] = {9, 9};
int n, sum;
bool func();
void func2();
int main()
{
    cin >> n >> sum;
    for (int i = 1; i <= n; ++i)
    {
        a[i - 1] = i;
    }
    do
    {
        int p = 0;
        while (a[p] == c[p])
        {
            ++p;
        }
        if (a[p] > c[p])
        {
            break;
        }
        if (func())
        {
            func2();
        }
    } while (next_permutation(a, a + n));
    for (int i = 0; i < n; ++i)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
bool func()
{

    int i = 0, k = n - 1;
    for (int i = 0; i < n; ++i)
    {
        b[i] = a[i];
    }
    while (k > 0)
    {
        for (int i = 0; i < k; ++i)
        {
            b[i] = b[i] + b[i + 1];
        }
        --k;
    }
    return b[0] == sum;
}
void func2()
{
    int f = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] < c[i])
        {
            f = 1;
            break;
        }
        else if (a[i] > c[i])
        {
            return;
        }
    }
    if (f)
    {
        for (int i = 0; i < n; ++i)
        {
            c[i] = a[i];
        }
    }
}