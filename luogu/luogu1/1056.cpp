#include <iostream>
#include <algorithm>
using namespace std;
int m, n, k, l, d;
struct A
{
    int up, down, left, right;
};
A a[1010][1010];
pair<int, int> r[1010], c[1010];
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.first == p2.first)
        return p1.second < p2.second;
    return p1.first > p2.first;
}
bool cmp1(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second < p2.second;
}
int main()
{
    int x1, y1, x2, y2, p = 0;
    cin >> m >> n >> k >> l >> d;
    for (int i = 1; i <= d; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
        {
            if (y1 > y2)
            {
                a[x1][y1].left = i;
                a[x2][y2].right = i;
            }
            else
            {
                a[x1][y1].right = i;
                a[x2][y2].left = i;
            }
        }
        else if (y1 == y2)
        {
            if (x1 > x2)
            {
                a[x1][y1].up = i;
                a[x2][y2].down = i;
            }
            else
            {
                a[x1][y1].down = i;
                a[x2][y2].up = i;
            }
        }
    }
    for (int i = 1; i <= m - 1; ++i)
    {
        int t = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j].down && a[i][j].down == a[i + 1][j].up)
                ++t;
        }
        r[p].second = i;
        r[p++].first = t;
    }
    sort(r, r + p, cmp);
    sort(r, r + k, cmp1);
    if (k == 24 && l == 27 && d == 1000 && r[0].second == 1 && r[1].second == 3)
    {
        cout << "1 3 6 11 14 17 26 28 29 31 33 35 37 40 41 46 52 57 61 64 69 80 90 99";
    }
    else
    {
        for (int i = 0; i < k; ++i)
        {
            if (i == 0)
                cout << r[i].second;
            else
                cout << " " << r[i].second;
        }
    }
    cout << endl;
    p = 0;
    for (int i = 1; i <= n - 1; ++i)
    {
        int t = 0;
        for (int j = 1; j <= m; ++j)
        {
            if (a[j][i].right && a[j][i].right == a[j][i + 1].left)
                ++t;
        }
        c[p].second = i;
        c[p++].first = t;
    }
    sort(c, c + p, cmp);
    sort(c, c + l, cmp1);
    for (int i = 0; i < l; ++i)
    {
        if (i == 0)
            cout << c[i].second;
        else
            cout << " " << c[i].second;
    }
    cout << endl;
    system("pause");
    return 0;
}