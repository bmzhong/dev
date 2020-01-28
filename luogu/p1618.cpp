#include <iostream>
using namespace std;
bool func(int a);
bool func1(int a, int b);
bool func2(int a);
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int max = 999 * a / c;
    int h[999], r[500];
    int m, n, k = 0;
    int is = (b % a == 0 && c % a == 0);
    if (!is)
    {
        for (int i = 123; i <= max; ++i)
        {
            if (i % a == 0 && func(i))
            {
                m = (i / a) * b;
                n = (i / a) * c;
                if (func2(i) && func2(m) && func2(n) && func(m) && func(n) && func1(i, m) && func1(i, n) && func1(m, n))
                {
                    r[k++] = i;
                }
            }
        }
    }
    else
    {
        for (int i = 123; i <= max; ++i)
        {
            if (func(i))
            {
                m = i * (b / a);
                n = i * (c / a);
                if (func2(i) && func2(m) && func2(n) && func(m) && func(n) && func1(i, m) && func1(i, n) && func1(m, n))
                {
                    r[k++] = i;
                }
            }
        }
    }
    if (k == 0)
    {
        cout << "No!!!" << endl;
    }
    else
    {
        for (int i = 0; i < k; ++i)
        {
            if (!is)
            {
                m = (r[i] / a) * b;
                n = (r[i] / a) * c;
                cout << r[i] << " " << m << " " << n << endl;
            }
            else
            {
                m = r[i] * (b / a);
                n = r[i] * (c / a);
                cout << r[i] << " " << m << " " << n << endl;
            }
        }
    }

    system("pause");
    return 0;
}

bool func1(int a, int b)
{
    int x[3], y[3];
    int i = 0;
    while (a != 0)
    {
        x[i] = a % 10;
        a /= 10;
        ++i;
    }
    i = 0;
    while (b != 0)
    {
        y[i] = b % 10;
        b /= 10;
        for (int j = 0; j < 3; ++j)
        {
            if (y[i] == x[j])
            {
                return false;
            }
        }
        ++i;
    }
    return true;
}

bool func(int a)
{
    int x[3];
    int i = 0;
    while (a != 0)
    {
        x[i] = a % 10;
        a /= 10;
        ++i;
    }
    return (x[0] != x[1] && x[0] != x[2] && x[1] != x[2]);
}

bool func2(int a)
{
    int i = 0;
    while (a != 0)
    {
        if (a % 10 == 0)
        {
            return false;
        }
        a /= 10;
    }
    return true;
}