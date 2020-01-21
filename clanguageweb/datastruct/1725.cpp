#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    string str1, str2;
    vector<pair<char, int>> v1;
    map<char,int> m;
    vector<vector<pair<char, int>>> v;
    while (getline(cin, str1) && str1 != "#")
    {
        for (int i = 0; i < str1.size(); ++i)
        {
            m[str1[i]]=0;
            pair<char, int> p = make_pair(str1[i], 0);
            v1.push_back(p);
        }
        getline(cin, str2);
        for (int i = 0; i < str2.size(); ++i)
        {
            if (str1.find(str2[i]) != string::npos)
            {                
                m[str2[i]]++;
            }
        }
        for(int i=0;i<v1.size();++i){
            v1[i].second=m[v1[i].first];
        }
        v.push_back(v1);
        v1.clear();
        m.clear();
    }
    for (auto it : v)
    {
        for (auto it1 : it)
        {
            cout << it1.first << " " << it1.second << endl;
        }
    }
    system("pause");
    return 0;
}