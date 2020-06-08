#include <iostream>
using namespace std;
int a[1001];
void func(int n, int i)
{
    if (i > n)
    {
        return;
    }
    else if (i % 2 == 1)
    {
        a[i] = a[i - 1];
    }
    else
    {
        for (int j = 1; j <= i / 2; ++j)
        {
            a[i] += a[j];
        }
        ++a[i];
    }
    ++i;
    func(n, i);
}
int main()
{
    int n;
    a[1] = 1;
    cin >> n;
    func(n, 2);
    cout << a[n] << endl;
    system("pause");
    return 0;
}