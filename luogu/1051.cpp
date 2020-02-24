#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
struct A
{
    string name;
    int score, overall, paper, sch, id;
    char leader, west;
};
A a[101];
int n, res;
bool cmp(const A &a1, const A &a2)
{
    if (a1.sch == a2.sch)
        return a1.id < a2.id;
    return a1.sch > a2.sch;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].name >> a[i].score >> a[i].overall >> a[i].leader >> a[i].west >> a[i].paper;
        if (a[i].score > 80 && a[i].paper > 0)
            a[i].sch += 8000;
        if (a[i].score > 85 && a[i].overall > 80)
            a[i].sch += 4000;
        if (a[i].score > 90)
            a[i].sch += 2000;
        if (a[i].score > 85 && a[i].west == 'Y')
            a[i].sch += 1000;
        if (a[i].overall> 80 && a[i].leader == 'Y')
            a[i].sch += 850;
        res += a[i].sch;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    cout<<a[1].name<<endl;
    cout<<a[1].sch<<endl;
    cout<<res<<endl;
    system("pause");
    return 0;
}