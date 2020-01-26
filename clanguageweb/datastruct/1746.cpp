#include <iostream>
using namespace std;
int main()
{
    int a[2][3], b[3][2];
    int c[2][2];
    while (cin >> a[0][0])
    {
        cin >> a[0][1] >> a[0][2] >> a[1][0] >> a[1][1] >> a[1][2];
        for (int i = 0; i < 3; ++i)
        {
            cin >> b[i][0] >> b[i][1];
        }
        for (int i = 0; i < 2; ++i)
        {
            for (int k = 0; k < 2; ++k)
            {
                c[i][k] = 0;
                for (int j = 0; j < 3; ++j)
                {
                    c[i][k] += a[i][j] * b[j][k];
                }
            }
        }
        for (int i = 0; i < 2; ++i)
        {
            cout << c[i][0] << " " << c[i][1] << endl;
        }
    }

    system("pause");
    return 0;
}