#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> v, v1;
    vector<vector<string>> h;
    string str, str1;
    int a;
    while (getline(cin, str))
    {
        if (str.find("insert") != string::npos)
        {
            a = str[7] - '0';
            str1 = str.substr(9);
            v.insert(v.begin() + a - 1, str1);
        }
        else if (str.find("delete") != string::npos)
        {
            str1 = str.substr(7);
            v.erase(remove(v.begin(), v.end(), str1), v.end());
        }
        else if (str.find("search") != string::npos)
        {
            str1 = str.substr(7);
            auto it = find(v.begin(), v.end(), str1);
            int b = distance(v.begin(), it);
            a = b + 1;
            str1 = to_string(a);
            v1.push_back(str1);
            h.push_back(v1);
        }
        else if (str == "show")
        {
            h.push_back(v);
        }
        v1.clear();
    }
    for (int i = 0; i < h.size(); ++i)
    {
        if (h[i].size() == 1)
        {
            if (isdigit(h[i][0][0]))
            {
                cout << h[i][0] << endl;
            }
            else
            {
                cout << *h[i].begin() << endl;
            }
        }
        else if (h[i].size() != 0)
        {
            for (int j = 0; j < h[i].size() - 1; ++j)
            {
                cout << h[i][j] << " ";
            }
            cout << *h[i].rbegin() << endl;
        }
        else if (h[i].size() == 0)
        {
            cout << endl;
        }
    }
    system("pause");
    return 0;
}