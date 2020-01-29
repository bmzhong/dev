#include <iostream>
using namespace std;
void func(int a, int &sum);
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int sum = 0, count = 0;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum = 0;
            func(a[i], sum);
            count += sum;
        }
        cout << count << endl;
    }
    system("pause");
    return 0;
}

void func(int a, int &sum)
{
    if (a >= 100)
    {
        sum += a / 100;
        a = a % 100;
    }
    if (a < 100 & a >= 50)
    {
        sum += a / 50;
        a = a % 50;
    }
    if (a < 50 && a >= 10)
    {
        sum += a / 10;
        a = a % 10;
    }
    if (a < 10 && a >= 5)
    {
        sum += a / 5;
        a = a % 5;
    }
    if (a < 5 && a >= 2)
    {
        sum += a / 2;
        a = a % 2;
    }

    if (a < 2 && a >= 1)
    {
        sum += a;
    }
}
