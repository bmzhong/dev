#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
bool cmp1(char &a)
{
    return a >= 'A' && a <= 'Z';
}

bool cmp2(char &a)
{
    return a >= 'a' && a <= 'z';
}

bool cmp3(char &a)
{
    return a >= '0' && a <= '9';
}

bool cmp4(char &a)
{
    return a == ' ';
}
int main()
{
    string str;
    map<int, int> m;
    getline(cin, str);
    m[0] = count_if(str.begin(), str.end(), cmp1);
    m[1] = count_if(str.begin(), str.end(), cmp2);
    m[2] = count_if(str.begin(), str.end(), cmp3);
    m[3] = count_if(str.begin(), str.end(), cmp4);
    cout << m[0] << " " << m[1] << " " << m[2] << " " << m[3] << endl;
    system("pause");
    return 0;
}
