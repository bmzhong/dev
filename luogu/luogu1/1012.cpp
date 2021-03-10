#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(const string str1, const string str2)
{
    string str3 = str1 + str2;
    string str4 = str2 + str1;
    return str3 > str4;
}

int main()
{
    int n;
    cin >> n;
    string str;
    vector<string> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        v.push_back(str);
    }
    sort(v.begin(), v.end(), cmp);
    string s;
    int len = v.size();
    for (int i = 0; i < len; ++i)
    {
        s += v[i];
    }
    cout << s << endl;
    system("pause");
    return 0;
}