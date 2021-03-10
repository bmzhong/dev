#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int a, m, n;
    vector<int> v1, v2, v;
    vector<vector<int>> h;
    while (cin >> m)
    {
        for (int i = 0; i < m; ++i)
        {
            cin >> a;
            v1.push_back(a);
        }
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            v2.push_back(a);
        }
        v.insert(v.begin(), v1.begin(), v1.end());
        v.insert(v.begin(), v2.begin(), v2.end());
        sort(v.begin(), v.end());
        h.push_back(v);
        v.clear();
        v1.clear();
        v2.clear();
    }
    for (int i = 0; i < h.size(); ++i)
    {
        for (int j = 0; j < h[i].size() - 1; ++j)
        {
            cout << h[i][j] << " ";
        }
        if (h[i].size() != 0)
        {
            cout << *h[i].rbegin() << endl;
        }
    }
    system("pause");
    return 0;
}