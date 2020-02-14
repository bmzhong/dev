#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
    map<string, char> m1, m2;
    int n, m;
    string name, id;
    char gender;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> name >> id >> gender;
        m1[name] = gender;
        m2[id] = gender;
    }
    cin >> m;
    string info1, info2;
    char g1, g2;
    for (int i = 0; i < m; ++i)
    {
        cin >> info1 >> info2;
        if (isdigit(info1[0]))
            g1 = m2[info1];
        else
            g1 = m1[info1];
        if (isdigit(info2[0]))
            g2 = m2[info2];
        else
            g2 = m1[info2];
        if(g1==g2)
            cout<<"N"<<endl;
        else
            cout<<"Y"<<endl;
    }
    system("pause");
    return 0;
}