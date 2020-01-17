#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int len1 = str1.length();
    int len2 = str2.length();
    int i = 0;
    int j = 0;
    vector<char> v;

    while (i < len1 && j < len2)
    {
        if (str1[i] != str2[j])
        {
            if (isalpha(str1[i]))
            {
               transform(str1.begin()+i,str1.begin()+i+1,str1.begin()+i,::toupper);
            }
            if (!count(v.begin(), v.end(), str1[i]))
            {
                v.push_back(str1[i]);
            }
            ++i;
        }
        else
        {
            ++i;
            ++j;
        }
    }
    if (i < len1)
    {
        if (isalpha(str1[i]))
        {
            transform(str1.begin()+i,str1.begin()+i+1,str1.begin()+i,::toupper);
        }
        if (!count(v.begin(), v.end(), str1[i]))
        {
            v.push_back(str1[i]);
        }
        ++i;
    }
    for (auto it : v)
    {
        cout<<it;
    }
    cout<<endl;
    return 0;
}