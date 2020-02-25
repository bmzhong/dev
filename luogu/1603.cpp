#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;
vector<string> v;
void f();
long long res=9999999999999;
int main()
{

    map<string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13}, {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17}, {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"a", 1}, {"both", 2}, {"another", 2}, {"first", 1}, {"second", 2}, {"third", 3}};
    string str;
    for (int i = 0; i <= 6; ++i)
    {
        cin >> str;
        if (m[str] > 0)
        {
            int r = (m[str] * m[str]) % 100;
            stringstream ss;
            ss << r;
            ss >> str;
            ss.clear();
            if (r < 10)
                str = "0" + str;
            v.push_back(str);
        }
    }
    if (v.size() != 0)
    {
        sort(v.begin(), v.end());
        f();
        while (next_permutation(v.begin(), v.end()))
        {
            f();
        }
    }else
        res=0;
    cout << res << endl;
    system("pause");
    return 0;
}
void f()
{
    string str, t;
    int len = v.size();
    for (int i = 0; i < len; ++i)
    {
        str += v[i];
    }
    len = str.size();
    int pos = 0;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] != '0')
        {
            pos = i;
            break;
        }
    }
    t = str.substr(pos);
    stringstream ss;
    long long temp;
    ss << t;
    ss >> temp;
    ss.clear();
    res = res > temp ? temp : res;
}