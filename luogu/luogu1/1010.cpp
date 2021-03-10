#include <iostream>
#include <string>
#include <stack>
#include <cmath>
using namespace std;
void bi(int n, string &str);
void tran(int n, string &deter);
int main()
{
    int n;
    string deter = "";
    cin >> n;
    tran(n, deter);
    cout << deter << endl;
    system("pause");
    return 0;
}

void tran(int n, string &deter)
{
    string str, str1;
    bi(n, str);
    int len = str.size();
    int a;
    int pos = str.find_last_not_of('0');
    for (int i = 0; i < len; ++i)
    {
        str1="";
        if (str[i] == '1')
        {
            a = len - 1 - i;
            if (a >= 2)
            {
                tran(a, str1);
                if (i != pos)
                {
                    deter += "2(" + str1 + ")+";
                }
                else
                {
                    deter += "2(" + str1 + ")";
                }
            }
            else if (a == 1)
            {
                if (i != pos)
                {
                    deter += "2+";
                }
                else
                {
                    deter += "2";
                }
            }
            else if (a == 0){
                deter+="2(0)";
            }
        }
    }
}

void bi(int n, string &str)
{
    stack<int> s;
    while (n != 0)
    {
        s.push(n % 2);
        n /= 2;
    }
    str = "";
    int a;
    while (!s.empty())
    {
        a = s.top();
        a += 48;
        str += (char)a;
        s.pop();
    }
}