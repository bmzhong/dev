#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include <map>
using namespace std;
int main()
{
    string str;
    stack<char> s;
    stack<int> s1;
    vector<int> v;
    char a;
    int b, c;
    map<char, int> m;
    m['('] = 0;
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;
    m[')'] = 3;
    while (getline(cin, str))
    {
        string str1;
        for (int i = 0; i < str.size() - 1;)
        {
            char y = str[i];
            if (isdigit(str[i]))
            {
                int p = str.find_first_not_of("0123456789", i);
                string str2 = str.substr(i, p - i) + " ";
                str1 += str2;
                i =p;
            }
            else if (str[i] == '(' || str[i] == ')' || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                if (!s.empty())
                {
                    a = s.top();
                    c = m[a];
                }
                b = m[str[i]];
                if (str[i] == '(')
                    s.push(str[i]);
                else if (str[i] == ')')
                {
                    while (a != '(')
                    {
                        str1 += a;
                        s.pop();
                        a = s.top();
                    }
                    s.pop();
                }
                else if (b > c)
                    s.push(str[i]);
                else
                {
                    while (b <= c && !s.empty())
                    {
                        str1 += a;
                        s.pop();
                        if (!s.empty())
                        {
                            a = s.top();
                        }
                        else
                        {
                            break;
                        }
                        c = m[a];
                    }
                    s.push(str[i]);
                }
                ++i;
            }
        }
        while (!s.empty())
        {
            str1 += s.top();
            s.pop();
        }
        stack<char>().swap(s);
        for (int i = 0; i < str1.size();)
        {
            if (isdigit(str1[i]))
            {
                int p = str1.find_first_not_of("0123456789", i);
                string str2 = str1.substr(i, p - i);
                stringstream s;
                s<<str2;
                int q;
                s>>q;
                s.clear();
                s1.push(q);
                i=p;
            }else if(str1[i]==' '){
                ++i;
                continue;
            }
            else
            {
                int y = s1.top();
                s1.pop();
                int x = s1.top();
                s1.pop();
                int r;
                switch (str1[i])
                {
                case '+':
                    r = x + y;
                    s1.push(r);
                    break;
                case '-':
                    r = x - y;
                    s1.push(r);
                    break;
                case '*':
                    r = x * y;
                    s1.push(r);
                    break;
                case '/':
                    r = x / y;
                    s1.push(r);
                    break;
                }
                ++i;
            }
        }
        int re = s1.top();
        s1.pop();
        v.push_back(re);
        stack<int>().swap(s1);
    }
    for (auto it : v)
    {
        cout << it << endl;
    }
    system("pause");
    return 0;
}

//注意char类型数字相加和int类型数字相加的结果不同。