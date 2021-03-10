#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Info
{
    string name;
    int age;
    double score;
};

bool cmp(Info &s1, Info &s2)
{
    if (s1.score != s2.score)
        return s1.score < s2.score;
    if (s1.name.compare(s2.name) != 0)
        return s1.name.compare(s2.name) < 0;
    return s1.age < s2.age;
}

int main()
{
    int n;
    Info in;
    vector<Info> v;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> in.name >> in.age >> in.score;
            v.push_back(in);
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < n; ++i)
        {
            cout << v[i].name << " " << v[i].age << " " << v[i].score << endl;
        }
        v.clear();
    }
    system("pause");
    return 0;
}
