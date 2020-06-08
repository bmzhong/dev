#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
int main()
{
    string str1, str2, str3, res;
    set<char> value;
    map<char, char> m;
    cin >> str1;
    cin.get();
    cin >> str2;
    cin.get();
    cin >> str3;
    int len = str1.length();
    for (int i = 0; i < len; ++i)
    {
        pair<set<char>::iterator, bool> p = value.insert(str2[i]);
        if (!p.second)
        {
            map<char, char>::iterator it=m.begin();
            for (it; it != m.end(); ++it)
            {
                if ((*it).second == str2[i])
                    break;
            }
            if (it != m.end())
            {
                if ((*it).first != str1[i])
                {
                    res = "Failed";
                    break;
                }
            }
        }
        else
            m[str1[i]] = str2[i];
    }
    if (value.size() != 26)
        res = "Failed";
    if (res != "Failed")
    {
        res = "";
        len = str3.length();
        for (int i = 0; i < len; ++i)
        {
            res += m[str3[i]];
        }
    }
    cout << res << endl;
    system("pause");
    return 0;
}