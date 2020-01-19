#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int n, m, d, a;
    cin >> n;
    stringstream st;
    vector<vector<int>> h;
    stack<int> s;
    vector<int> v, v1;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        s.push(a);
    }
    while (!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    cin >> n;
    cin.get();
    string str, str1, str2;
    for (int i = 0; i < n; ++i)
    {
        getline(cin, str);
        if (str == "show")
        {
            h.push_back(v);
        }
        else if (str.find("delete") != string::npos)
        {
            str1 = str.substr(7);
            st << str1;
            st >> a;
            st.clear();
            a = a - 1;
            if (a >= v.size())
            {
                v1.push_back(-111);
            }
            else
            {
                v.erase(v.begin() + a);
                v1.push_back(-222);
            }
            h.push_back(v1);
            v1.clear();
        }
        else if (str.find("insert") != string::npos)
        {
            int f = str.find(" ", 7);
            str1 = str.substr(7, f - 7);
            str2 = str.substr(f + 1);
            st << str1;
            st >> a;
            st.clear();
            st << str2;
            st >> d;
            st.clear();
            if (a > v.size() + 1)
            {
                v1.push_back(-333);
                h.push_back(v1);
            }
            else
            {
                v.insert(v.begin() + a - 1, d);
                v1.push_back(-444);
                h.push_back(v1);
            }
            v1.clear();
        }
        else if (str.find("get") != string::npos)
        {
            str1 = str.substr(4);
            st << str1;
            st >> a;
            st.clear();
            if (a > v.size())
            {
                v1.push_back(-555);
                h.push_back(v1);
            }
            else
            {
                v1.push_back(-666);
                v1.push_back(v[a - 1]);
                h.push_back(v1);
            }
            v1.clear();
        }
    }
    for (int i = 0; i < h.size(); ++i)
    {
        if (h[i].size() == 1)
        {
            if (h[i][0] == -111)
            {
                cout << "delete fail" << endl;
            }
            else if (h[i][0] == -222)
            {
                cout << "delete OK" << endl;
            }
            else if (h[i][0] == -333)
            {
                cout << "insert fail" << endl;
            }
            else if (h[i][0] == -444)
            {
                cout << "insert OK" << endl;
            }
            else if (h[i][0] == -555)
            {
                cout << "get fail" << endl;
            }
            else
            {
                cout << h[i][0] << endl;
            }
        }
        else if (h[i].size() == 0)
        {
            cout << "Link list is empty" << endl;
        }
        else if (h[i].size() == 2)
        {
            if (h[i][0] == -666)
            {
                cout << h[i][1] << endl;
            }
            else
            {
                cout << h[i][0] << " " << h[i][1] << endl;
            }
        }
        else
        {
            for (int j = 0; j < h[i].size(); ++j)
            {

                if (j == h[i].size() - 1)
                {
                    cout << *h[i].rbegin() << endl;
                }
                else
                {
                    cout << h[i][j] << " ";
                }
            }
        }
    }
    system("pause");
    return 0;
}