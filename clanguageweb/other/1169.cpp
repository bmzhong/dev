#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct cmp
{
    bool operator()(const int &a, const int &b)
    {
        return !(abs(a) < abs(b));
    }
};
int main()
{
    int n, a;
    set<int, cmp> s;
    vector<set<int, cmp>> v;
    while (cin >> n && n != 0)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            s.insert(a);
        }
        v.push_back(s);
        s.clear();
    }

    for (int i = 0; i < v.size(); ++i)
    {
        for (auto j = v[i].begin(); j != v[i].end(); ++j)
        {
            if ((*j) != *v[i].rbegin())
            {
                cout << *j << " ";
            }
            else
            {
                cout << *j << endl;;
            }
        }
    }
    system("pause");
    return 0;
}