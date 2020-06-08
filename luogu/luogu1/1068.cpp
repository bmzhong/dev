#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
pair<string, int> p[5001];
int m, n, score, num, id;
bool cmp(const pair<string, int> &p1, const pair<string, int> &p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    return p1.second > p2.second;
}
bool cmp1(const pair<string, int> &p1, const pair<string, int> &p2)
{
    return p1.second > p2.second;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n, cmp);
    id = int(m * 1.5);
    score = p[id - 1].second;
    pair<string, int> temp(" ", score);
    int dis = upper_bound(p, p + n, temp, cmp1) - p;
    cout << score << " " << dis << endl;
    for (int i = 0; i < dis; ++i)
    {
        cout << p[i].first << " " << p[i].second << endl;
    }
    system("pause");
    return 0;
}