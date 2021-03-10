#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
struct A
{
    string name;
    int year, month, day, id;
};
A st[100];
bool cmp(const A &a1, const A &a2)
{
    if (a1.year == a2.year)
    {
        if (a1.month == a2.month)
        {
            if (a1.day == a2.day)
            {
                return a1.id > a2.id;
            }
            return a1.day < a2.day;
        }

        return a1.month < a2.month;
    }
    return a1.year < a2.year;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> st[i].name >> st[i].year >> st[i].month >> st[i].day;
        st[i].id = i;
    }
    sort(st, st + n, cmp);
    for (int i = 0; i < n; ++i)
    {
        cout << st[i].name << endl;
    }
    system("pause");
    return 0;
}