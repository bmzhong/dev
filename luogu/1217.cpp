#include <iostream>
#include <cmath>
using namespace std;
bool func1(int a);
bool func2(int a);
int arr[10];
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i)
    {
        if (func1(i))
        {
            if (func2(i))
            {
                cout << i << endl;
            }
        }
    }
    system("pause");
    return 0;
}

bool func1(int a)
{

    if (a % 2 == 1 && a % 3 != 0)
    {
        if (a < 12 || (a % 5 != 0 && a % 7 != 0))
        {
            int j = 0;
            while (a != 0)
            {
                arr[j] = a % 10;
                a /= 10;
                ++j;
            }
            int k = (j - 1) / 2;
            for (int i = 0; i <= k; ++i)
            {
                if (arr[i] != arr[j - 1 - i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    return false;
}

bool func2(int a)
{
    int b = int(sqrt(a));
    for (int i = 2; i <= b; ++i)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}