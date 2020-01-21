#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    vector<string> v;
    stack<char> s;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] != '#' && str[i] != '@')
            {
                s.push(str[i]);
            }
            else if (str[i] == '#')
            {
                s.pop();
            }
            else if (str[i] == '@')
            {
                stack<char>().swap(s);
            }
        }
        if (!s.empty())
        {
            string str1;
            while (!s.empty())
            {
                str1 += s.top();
                s.pop();
            }
            reverse(str1.begin(), str1.end());
            v.push_back(str1);
        }
        stack<char>().swap(s);
    }
    for(auto it:v){
        cout<<it<<endl;
    }
    system("pause");
    return 0;
}