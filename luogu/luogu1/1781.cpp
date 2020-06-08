#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
pair<string, int> p[21];
int n;
bool cmp(const pair<string, int> &p1, const pair<string, int> &p2)
{
    if (p1.first.size() == p2.first.size())
        return p1.first > p2.first;
    return p1.first.length() > p2.first.length();
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].first;
        p[i].second = i + 1;
    }
    sort(p, p + n, cmp);
    cout << p[0].second << endl;
    cout << p[0].first << endl;
    system("pause");
    return 0;
}