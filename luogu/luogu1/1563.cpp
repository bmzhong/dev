#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int n, m;
pair<int, string> p[300005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> p[i].first >> p[i].second;
        p[i + 2 * n].first = p[i + n].first = p[i].first;
        p[i + 2 * n].second = p[i + n].second = p[i].second;
    }
    int pos = n + 1, step, dir;
    for (int i = 1; i <= m; ++i)
    {
        cin >> dir >> step;
        if (p[pos].first == 0)
        {
            if (dir == 0)
                pos -= step;
            else
                pos += step;
        }
        else
        {
            if (dir == 0)
                pos += step;
            else
                pos -= step;
        }
        if (pos < n + 1)
            pos += n;
        else if (pos > 2 * n)
            pos -= n;
    }
    cout<<p[pos].second<<endl;
    system("pause");
    return 0;
}