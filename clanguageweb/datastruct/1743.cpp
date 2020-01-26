#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
bool cmp(string &str1, string &str2)
{
    int len1 = str1.length(), len2 = str2.length();
    if (len1 == len2)
    {
        return str1 < str2;
    }
    else
    {
        return len1 < len2;
    }
}
int main()
{
    string str;
    int n;
    vector<string> v;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> str;
            v.push_back(str);
        }
        sort(v.begin(),v.end(),cmp);
        for(auto it:v){
            cout<<it<<endl;
        }
        vector<string>().swap(v);
    }
    system("pause");
    return 0;
}