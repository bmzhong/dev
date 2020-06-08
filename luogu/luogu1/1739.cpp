#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string str;
    stack<char> s;
    cin >> str;
    int len = str.size();
    int k = 1;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '@')
        {
            break;
        }
        if (str[i] == '(')
        {
            s.push(str[i]);
        }
        if (str[i] == ')')
        {
            if (s.empty())
            {
                k = 0;
                break;
            }
            else
            {
                if (s.top() == '(')
                    s.pop();
                else
                {
                    k = 0;
                    break;
                }
            }
        }
    }
    if (s.empty()&&k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    system("pause");
    return 0;
}