#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int main()
{
    string str1;
    getline(cin, str1);
    char a = str1[0];
    int pos1 = str1.find_last_of("+-");
    char b = str1[pos1];
    string str2 = str1.substr(pos1 + 1);
    int pos2 = str2.find_first_not_of("0");
    string str3 = str2.substr(pos2);
    stringstream s;
    s << str3;
    int k;
    s >> k;
    string str4 = str1.substr(1, pos1 - 2);
    str4.erase(1,1);
    if (b == '-')
    {
        str4.insert(0, k, '0');
        str4.insert(1, ".");
        if (a == '-')
        {
            str4.insert(0, "-");
        }
    }
    if(b=='+'){
        str4.append(k,'0');
        if(a=='-'){
             str4.insert(0, "-");
        }
    }
    cout << str4 << endl;
    system("pause");
    return 0;
}
