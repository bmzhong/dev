#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, int> p1, const pair<int, int> p2)
{
    return p1.second < p2.second;
}
int main()
{
    int n, s;
    cin >> n >> s;
    int a, b;
    cin >> a >> b;
    int x, y;
    int sum = 0;
    int height = a + b;
    pair<int, int> p[n], p1;
    for (int i = 0; i < n; ++i)
    {
        cin >> x >> y;
        p1.first = x;
        p1.second = y;
        p[i] = p1;
    }
    sort(p, p + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        if (p[i].first <= height)
        {
            if (s >= p[i].second)
            {
                ++sum;
                s -= p[i].second;
            }
        }
    }
    cout << sum << endl;
    system("pause");
    return 0;
}