#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

map<string, int> m;

void init()
{
    ifstream in("data.txt");
    if (!in.is_open())
        cout << "open file failed" << endl;
    string name;
    int votes;
    while (in >> name >> votes)
    {
        m[name] += votes;
    }
}

void output()
{
    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
}

void search(string name)
{
    map<string, int>::iterator it = m.find(name);
    if (it == m.end())
        cout << "none" << endl;
    else
        cout << it->first << " " << it->second << endl;
}

int main()
{
    init();
    output();
    string name;
    while (cin >> name && name != "Quit")
    {
        search(name);
    }
    system("pause");
    return 0;
}
