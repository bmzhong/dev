#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    while (getline(cin, str))
    {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
        cout << str << endl;
    }
    system("pause");
    return 0;
}