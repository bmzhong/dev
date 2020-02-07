#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;
int main()
{
    string str;
    stringstream ss;
    stack<int> s;
    cin >> str;
    int len = str.size(), r, x, y, i;
    while (i < len)
    {
        if (str[i] == '@')
        {
            break;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            int pos = str.find('.', i);
            string sub = str.substr(i, pos - i);
            ss << sub;
            int num;
            ss >> num;
            ss.clear();
            s.push(num);
            i = pos + 1;
        }
        else
        {
            if (!s.empty())
            {
                y = s.top();
                s.pop();
            }
            if (!s.empty())
            {
                x = s.top();
                s.pop();
            }
            if (str[i] == '-')
            {
                r = x - y;
            }
            else if (str[i] == '+')
            {
                r = x + y;
            }
            else if (str[i] == '*')
            {
                r = x * y;
            }
            else if (str[i] == '/')
            {
                r = x / y;
            }
            s.push(r);
            ++i;
        }
    }

    cout << s.top() << endl;

    system("pause");
    return 0;
}