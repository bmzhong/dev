#include <iostream>
#include <ctype.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string str1, str, str2, str3;
    getline(cin, str1);
    vector<string> v;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    int len = str1.size();
    while (getline(cin, str2))
    {
        int i;
        str2.erase(remove(str2.begin(), str2.end(), ' '), str2.end());
        str3 = str2;
        transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
        while ((i = str2.find(str1)) != string::npos)
        {
            str2.erase(i, len);
            str3.erase(i, len);
        }
        v.push_back(str3);
    }

    for (auto it : v)
    {
        cout << it << endl;
    }
    system("pause");
    return 0;
}