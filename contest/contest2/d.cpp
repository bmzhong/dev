#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct S
{
    string name;
    int score;
    int age;
};

bool cmp(const S &s1, const S &s2)
{
    if (s1.score != s2.score)
        return s1.score < s2.score;
    if (s1.name != s2.name)
        return s1.name < s2.name;
    return s1.age < s2.age;
}

int main()
{

    S s;
    int n;
    while (cin >> n)
    {
        vector<S> v;
        for (int i = 0; i < n; ++i)
        {
            cin >> s.name >> s.age >> s.score;
            v.push_back(s);
        }
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < n; ++i)
        {
            cout << v[i].name << " " << v[i].age << " " << v[i].score << endl;
        }
    }

    system("pause");
    return 0;
}