#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    int pos1, pos2;
    int count = 0;
    int len = str1.size();
    while (str1 != str2)
    {
        pair<string::iterator, string::iterator> p = mismatch(str1.begin(), str1.end(), str2.begin());
        pos1 = distance(str1.begin(), p.first);
        str1[pos1] = str2[pos1];
        if (pos1 + 1 < len)
        {
            str1[pos1 + 1] = str2[pos1 + 1];
            ++count;
        }else{
            cout<<"false"<<endl;
            break;
        }
    }
    cout<<count<<endl;
    system("pause");
    return 0;
}