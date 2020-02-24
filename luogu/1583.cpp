#include <iostream>
#include <algorithm>
using namespace std;
int b[11], n, k;
pair<int, int> p[20001];
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first > p2.first;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= 10; ++i)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
    {
        p[i].first += b[(i - 1) % 10 + 1];
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= k; ++i)
    {
        cout << p[i].second << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}