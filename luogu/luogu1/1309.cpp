#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct A
{
    int first, second, id;
};
A p[200003];
int n, r, q;
bool cmp(const A &a1, const A &a2)
{
    if (a1.first == a2.first)
        return a1.id < a2.id;
    return a1.first > a2.first;
}
int main()
{
    scanf("%d%d%d", &n, &r, &q);
    for (int i = 1; i <= 2 * n; ++i)
    {
        cin >> p[i].first;
        p[i].id = i;
    }
    for (int i = 1; i <= 2 * n; ++i)
    {
        cin >> p[i].second;
    }
    for (int j = 1;j <= r; ++j)
    {
        sort(p + 1, p + 1 + 2 * n, cmp);
        for (int i = 1; i < 2 * n; i += 2)
        {
            if (p[i].second > p[i + 1].second)
                p[i].first += 1;
            else
                p[i + 1].first += 1;
        }
    }
    sort(p + 1, p + 1 + 2 * n, cmp);
    cout << p[q].id << endl;
    system("pause");
    return 0;
}