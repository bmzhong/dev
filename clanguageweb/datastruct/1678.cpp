#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int a, b, c, n;
    vector<int> v;
    vector<vector<int>> h;
    while (cin >> a)
    {
        if (a == 0)
        {
            h.push_back(v);
        }
        else if (a == 1)
        {
            cin >> b >> c;
            v.insert(v.begin() + b - 1, c);
        }
        else if (a == 2)
        {
            cin >> b;
            v.erase(v.begin() + b - 1);
        }
    }
    for (int i = 0; i < h.size(); ++i)
    {
        for (int j = 0; j < h[i].size() - 1; ++j)
        {
            cout << h[i][j] << " ";
        }
        if (h[i].size() != 0)
        {
            cout << *h[i].rbegin()<<endl;
        }
    }
    system("pause");
    return 0;
}