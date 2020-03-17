#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string s[3][2];
    string str1, str2, str3;
    vector<string> v;
    vector<int> h;
    for (int k = 0; k < 3; ++k)
    {
        cin >> str1 >> str2;
        int i = 0, j = 0;
        int len1 = str1.length();
        int len2 = str2.length();
        str3 = "";
        while (i < len1)
        {
            str3 += str1[i];
            if (str1[i] == str2[j])
            {
                ++i;
                ++j;
            }
            else
            {
                i=i-j+1;
                j = 0;
            }
            if (j == len2)
            {
                h.push_back(i - len2 + 1);
                break;
            }
        }
        if (j != len2)
        {
            h.push_back(0);
        }
        v.push_back(str3);
    }
    for (int i = 0; i < 3; ++i)
    {
        cout << v[i] << endl;
        cout << h[i] << endl;
    }
    return 0;
}