#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
struct P
{
    string name;
    int type;
    int id;
    int num;
    int dj;
};
string name, job;
int n, num, dj, c = 0;
P bz, fbz[2];
P p[111];
map<string, int> si;
map<int, string> is;
vector<P> v;
void init()
{
    si["BangZhu"] = 0;
    si["FuBangZhu"] = 1;
    si["HuFa"] = 2;
    si["ZhangLao"] = 3;
    si["TangZhu"] = 4;
    si["JingYing"] = 5;
    si["BangZhong"] = 6;
    is[0] = "BangZhu";
    is[1] = "FuBangZhu";
    is[2] = "HuFa";
    is[3] = "ZhangLao";
    is[4] = "TangZhu";
    is[5] = "JingYing";
    is[6] = "BangZhong";
}
bool cmp(const P &p1, const P &p2)
{
    if (p1.num == p2.num)
        return p1.id < p2.id;
    return p1.num > p2.num;
}
bool cmp1(const P &p1, const P &p2)
{
    if (p1.type == p2.type)
    {
        if (p1.dj == p2.dj)
            return p1.id < p2.id;
        return p1.dj > p2.dj;
    }
    return p1.type < p2.type;
}
int main()
{
    init();
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> name >> job >> num >> dj;
        if (job == "FuBangZhu")
        {
            fbz[c].type = 1;
            fbz[c].dj = dj;
            fbz[c].id = i;
            fbz[c].name = name;
            fbz[c].num = num;
            ++c;
        }
        else if (job == "BangZhu")
        {
            bz.dj = dj;
            bz.id = i;
            bz.name = name;
            bz.num = num;
            bz.type = 0;
        }
        else
        {
            P p;
            p.dj = dj;
            p.id = i;
            p.name = name;
            p.num = num;
            p.type = si[job];
            v.push_back(p);
        }
    }
    sort(v.begin(), v.end(), cmp);
    int hfi = 0, zli = 0, tzi = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (i < 2)
            v[i].type = 2;
        else if (i >= 2 && i < 6)
            v[i].type = 3;
        else if (i >= 6 && i < 13)
            v[i].type = 4;
        else if (i >= 13 && i < 38)
            v[i].type = 5;
        else
            v[i].type = 6;
    }
    sort(v.begin(), v.end(), cmp1);
    sort(fbz, fbz + 2, cmp1);
    cout << bz.name << " " << is[bz.type] << " " << bz.dj << endl;
    for (int i = 0; i < 2; ++i)
    {
        cout << fbz[i].name << " " << is[fbz[i].type] << " " << fbz[i].dj << endl;
    }
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i].name << " " << is[v[i].type] << " " << v[i].dj << endl;
    }
    system("pause");
    return 0;
}