#include <iostream>
#include <string>
#include <vector>
#include<cstring>
#include <algorithm>
#include<sstream>
using namespace std;
bool func(int a, int b);
int main()
{
    int a, b, c;
    vector<int> v;
    vector<vector<int> > h;
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            if (j == i)
                continue;
            for (int k = 1; k <= 9; ++k)
            {
                if (k == j || k == i)
                    continue;
                a = i * 100 + j * 10 + k;
                b = a * 2;
                if (func(a, b))
                {
                    c = a * 3;
                    if (func(a, c))
                    {
                        if (func(b, c))
                        {
                            v.push_back(a);
                            v.push_back(b);
                            v.push_back(c);
                            h.push_back(v);
                            v.clear();
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < h.size(); ++i)
    {
        cout << h[i][0] << " " << h[i][1] << " " << h[i][2] << endl;
    }
    system("pause");
    return 0;
}

bool func(int a, int b)
{   
    string str1 ;
    string str2 ;
    stringstream s;
    s<<a;
    s>>str1;
    s.clear();
    s<<b;
    s>>str2;
    s.clear();
    if (str1.size() > 3 || str2.size() > 3)
        return false;
    if(str1.find("0")!=string::npos||str2.find("0")!=string::npos) return false;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {

            if (str2[i] == str1[j])
            {
                return false;
            }
        }
    }
    return true;
}