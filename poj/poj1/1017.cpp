#include <iostream>
using namespace std;
int a[7];
int main()
{
    while (1)
    {
        int ans = 0;
        for (int i = 1; i <= 6; ++i)
        {
            cin >> a[i];
        }
        if (a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0 && a[6] == 0)
            break;
        for (int i = 6; i >= 0; --i)
        {
            if (i == 6 && a[i])
                ans += a[i];
            if (i == 5 && a[i])
            {
                ans += a[i];
                a[1] = a[1] - 11 * a[i] < 0 ? 0 : a[1] - 11 * a[i];
            }
            if (i == 4 && a[i])
            {
                ans += a[i];
                int re1 = a[2];
                a[2] = a[2] - 5 * a[i] < 0 ? 0 : a[2] - 5 * a[i];
                int re2 = 20 * a[i] - 4 * (re1 - a[2]);
                a[1] = a[1] - re2 < 0 ? 0 : a[1] - re2;
            }
            if (i == 3 && a[i])
            {
                if (a[i] % 4 == 0)
                    ans += a[i] / 4;
                else
                {
                    ans += a[i] / 4 + 1;
                    int re1 = a[2];
                    int k = a[i] % 4;
                    if (k == 1)
                    {
                        a[2] = a[2] - 5 < 0 ? 0 : a[2] - 5;
                        int re2 = 27 - 4 * (re1 - a[2]);
                        a[1] = a[1] - re2 < 0 ? 0 : a[1] - re2;
                    }
                    if (k == 2)
                    {
                        a[2] = a[2] - 3 < 0 ? 0 : a[2] - 3;
                        int re2 = 18 - 4 * (re1 - a[2]);
                        a[1] = a[1] - re2 < 0 ? 0 : a[1] - re2;
                    }
                    if (k == 3)
                    {
                        a[2] = a[2] - 1 < 0 ? 0 : a[2] - 1;
                        int re2 = 9 - 4 * (re1 - a[2]);
                        a[1] = a[1] - re2 < 0 ? 0 : a[1] - re2;
                    }
                }
            }
            if (i == 2 && a[i])
            {
                if (a[i] % 9 == 0)
                {
                    ans += a[i] / 9;
                }
                else
                {
                    ans += a[i] / 9 + 1;
                    int re1 = 36 - 4 * (a[i] % 9);
                    a[1] = a[1] - re1 < 0 ? 0 : a[1] - re1;
                }
            }
            if (i == 1 && a[i])
            {
                if (a[i] % 36 == 0)
                {
                    ans += a[i] / 36;
                }
                else
                {
                    ans += a[i] / 36 + 1;
                }
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}