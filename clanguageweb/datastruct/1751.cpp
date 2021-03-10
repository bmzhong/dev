#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    int b;
    vector<int> a;
    vector<vector<vector<int>>> h;
    vector<vector<int>> v;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> b;
                a.push_back(b);
            }
            v.push_back(a);
            a.clear();
        }
        h.push_back(v);
        v.clear();
    }
    for (int k = 0; k < h.size(); ++k)
    {
        for (int j = 0; j < h[k].size(); ++j)
        {
            for (int i = 0; i < h[k][j].size(); ++i)
            {
                if (i == h[k][j].size() - 1)
                {
                    cout << h[k][i][j] << endl;
                }
                else
                {
                    cout << h[k][i][j] << " ";
                }
            }
        }
    }

    system("pause");
    return 0;
}
