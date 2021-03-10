#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool jud(string str);
int main()
{
    string str;
    getline(cin, str);
    int k = str.length();
    if (k % 2 == 0 || k == 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        string str1 = str.substr(0, (k - 1) / 2);
        string str2 = str.substr((k - 1) / 2 + 1);
        reverse(str2.begin(), str2.end());
        if (str1 == str2 && str[(k - 1) / 2] == '&'&&jud(str1)&&jud(str2)&&str1.length()<1000)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    system("pause");
    return 0;
}

bool jud(string str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] < 'a' || str[i] > 'z')
            return false;
    }
    return true;
}