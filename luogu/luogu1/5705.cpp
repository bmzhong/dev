#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int len = str.size();
    for (int i = len-1; i >= 0; --i)
    {
        cout<<str[i];
    }
    cout<<endl;
    system("pause");
    return 0;
}