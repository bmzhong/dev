#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct A
{
    long long aa, bb, cc;
};
int main()
{
    long long a[21][21][21] = {0};
    for (int i = 0; i < 21; ++i)
    {
        for (int j = 0; j < 21; ++j)
        {
            a[0][i][j] = 1;
            a[i][0][j] = 1;
            a[i][j][0] = 1;
        }
    }
    for (int i = 1; i < 21; ++i)
    {
        for (int j = 1; j < 21; ++j)
        {
            for (int k = 1; k < 21; ++k)
            {
                if (i < j && j < k)
                {
                    a[i][j][k] = a[i][j][k - 1] + a[i][j - 1][k - 1] - a[i][j - 1][k];
                }
                else
                {
                    a[i][j][k] = a[i - 1][j][k] + a[i - 1][j - 1][k] + a[i - 1][j][k - 1] - a[i - 1][j - 1][k - 1];
                }
            }
        }
    }
    long long aa, bb, cc;
    vector<long long> v;
    vector<A> h;
    A aaa;
    while (cin >> aa >> bb >> cc && !(aa == -1 && bb == -1 && cc == -1))
    {
        if (aa <= 0 || bb <= 0 || cc <= 0)
        {
            v.push_back(1);
        }
        else if (aa > 20 || bb > 20 || cc > 20)
        {
            v.push_back(a[20][20][20]);
        }
        else
        {
            v.push_back(a[aa][bb][cc]);
        }
        aaa.aa = aa;
        aaa.bb = bb;
        aaa.cc = cc;
        h.push_back(aaa);
    }
    int len = v.size();
    for (int i = 0; i < len; ++i)
    {
        cout << "w(" << h[i].aa << ", " << h[i].bb << ", " << h[i].cc << ") = " << v[i] << endl;
    }
    system("pause");
    return 0;
}