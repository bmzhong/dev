#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string read()
{
    char ch;
    string s;
    while (cin >> ch)
    {
        if (ch == '[')
        {
            int n;
            cin >> n;
            string sub = read();
            while (n--)
                s += sub;
        }
        else if (ch == ']')
            return s;
        else
            s += ch;
    }
}
int main()
{
    cout<<read()<<endl;
    system("pause");
    return 0;
}