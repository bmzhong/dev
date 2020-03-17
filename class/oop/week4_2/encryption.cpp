#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(int argc, char *argv[])
{
    if (argc <= 1)
        return 0;
    int len = strlen(argv[1]);
    string str;
    cin >> str;
    int str_len = str.size();
    if (!str_len)
        return 0;
    for (int i = 0; i < str_len; ++i)
    {
        char temp = str[i] ^ argv[1][i % len];
        cout<<temp;
    }
    cout<<endl;
    system("pause");
    return 0;
}
