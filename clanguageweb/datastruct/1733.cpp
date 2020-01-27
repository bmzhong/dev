#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        stack<int> s;
        for (int i = 0; i < n; ++i)
        {
            char ch;
            cin >> ch;
            if (ch == 'P')
            {
                int b;
                cin >> b;
                s.push(b);
            }
            if (ch == 'O')
            {
                if (!s.empty())
                {
                    s.pop();
                }
            }
            if (ch == 'A')
            {
                if (s.empty())
                {
                    cout << "E" << endl;
                }
                else
                {
                    cout << s.top() << endl;
                }
            }
        }
        cout << endl;
    }
    system("pause");
    return 0;
}