#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
bool func(string str);
int main()
{
    int n;
    cin >> n;
    string str;
    vector<string> v;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        if (func(str))
        {
            v.push_back("Yes");
        }else{
             v.push_back("No");
        }
    }
    for(int i=0;i<n;++i){
        cout<<v[i]<<endl;
    }
    system("pause");
    return 0;
}

bool func(string str)
{
    stack<char> s;
    char ch;
    int len = str.length();
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == '(' || str[i] == '[')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (!s.empty())
            {
                ch = s.top();
                if (ch == '(')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else if (str[i] == ']')
        {
            if (!s.empty())
            {
                ch = s.top();
                if (ch == '[')
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
}