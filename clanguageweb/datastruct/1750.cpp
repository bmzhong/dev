#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<vector<int> > > h;
    vector<vector<int> > v;
    int m, n;
    while (cin >> m >> n)
    {
        vector<vector<int>>().swap(v);
        for (int i = 0; i < m; ++i)
        {
            int sum = 0;
            vector<int> p;

            v.push_back(p);
            for (int j = 0; j < n; ++j)
            {
                int a;
                cin >> a;
                sum += a;
                v[i].push_back(a);
            }
            int temp = v[i][n - 1];
            int pos = n - 1;
            int k;
            for (k = n - 1; k >= 0; --k)
            {
                if (v[i][k] >= temp)
                {
                    temp = v[i][k];
                    pos = k;
                }
            }
            v[i][k] = sum;
        }
        h.push_back(v);
    }
    for (int i = 0; i < h.size(); ++i)
    {
        for (int j = 0; j < h[i].size(); ++j)
        {
            for (int k = 0; k < h[i][j].size() - 1; ++k)
            {
                cout << h[i][j][k] << " ";
            }
            cout << *h[i][j].rbegin() << endl;
        }
    }
    system("pause");
    return 0;
}