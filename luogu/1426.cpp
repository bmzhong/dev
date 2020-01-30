#include <iostream>
using namespace std;
int main()
{
    double s, x;
    cin >> s >> x;
    double d1 = s - x, d2 = s + x, m = 0;
    double speed = 7.0;
    if (s <= x)
    {
        if (7 > d2)
        {
            cout << "n" << endl;
        }
        else
        {
            cout << "y" << endl;
        }
    }
    else
    {
        while (true)
        {
            m += speed;
            if (m < d1)
            {
            }
            else if (m >= d1 && m <= d2)
            {
                double yd = m - d1;
                double yt = yd / speed;
                speed *= 0.98;
                double f = (1 - yt) * speed;
                if (m + f > d2)
                {
                    cout << "n" << endl;
                }
                else
                {
                    cout << "y" << endl;
                }
                break;
            }
            else
            {
                cout << "n" << endl;
            }
            speed *= 0.98;
        }
    }

    system("pause");
    return 0;
}