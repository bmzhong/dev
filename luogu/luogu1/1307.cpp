#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    int pos = str.find_last_not_of("0");
    if (pos != string::npos)
    {
        str.erase(str.begin() + pos+1,str.end());
    }
    if (str[0] == '-')
    {
        reverse(str.begin()+1,str.end());
    }else{
        reverse(str.begin(),str.end());
    }
    cout<<str<<endl;
    system("pause");
    return 0;
}