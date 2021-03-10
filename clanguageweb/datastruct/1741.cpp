#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
struct Student
{
    string id;
    string name;
    int score;
};

struct A
{
    bool operator()(const Student &s1, const Student &s2)
    {
        return s1.id < s2.id;
    }
};
struct B
{
    bool operator()(const Student &s1, const Student &s2)
    {
        if (s1.name != s2.name)
            return s1.name < s2.name;
        return s1.id < s2.id;
    }
};

struct C
{
    bool operator()(const Student &s1, const Student &s2)
    {
        if (s1.score != s2.score)
            return s1.score < s2.score;
        return s1.id < s2.id;
    }
};

int main()
{
    Student s;
    int n, m;
    int k = 1;

    while (cin >> n >> m && n != 0)
    {
        set<Student, A> s1;
        set<Student, B> s2;
        set<Student, C> s3;
        if (m == 1)
        {
            for (int i = 0; i < n; ++i)
            {
                cin >> s.id >> s.name >> s.score;
                s1.insert(s);
            }
            cout << "Case " << k << ":" << endl;
            ++k;
            for (auto it : s1)
            {
                cout << it.id << " " << it.name << " " << it.score << endl;
            }
           
        }
        if (m == 2)
        {
            for (int i = 0; i < n; ++i)
            {
                cin >> s.id >> s.name >> s.score;
                s2.insert(s);
            }
            cout << "Case " << k << ":" << endl;
            ++k;
            for (auto it : s2)
            {
                cout << it.id << " " << it.name << " " << it.score << endl;
            }
            
        }
        if (m == 3)
        {
            for (int i = 0; i < n; ++i)
            {
                cin >> s.id >> s.name >> s.score;
                s3.insert(s);
            }
            cout << "Case " << k << ":" << endl;
            ++k;
            for (auto it : s3)
            {
                cout << it.id << " " << it.name << " " << it.score << endl;
            }
        }
    }
    system("pause");
    return 0;
}