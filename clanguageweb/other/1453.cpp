#include <iostream>
#include <string>
using namespace std;
string init, aim;
int dis[1001], len;
void fun();
int main()
{
    cin >> init >> aim;
    len = init.length();
    for (int i = 0; i < len; ++i)
    {
        if (init[i] == aim[i])
            dis[i] = 0;
        else
            dis[i] = 1;
    }
    fun();
    system("pause");
    return 0;
}

void fun()
{
    int res = 0, st = 0;
    for (int i = 0; i < len; ++i)
    {
        if (st + dis[i] == 1)
        {
            ++res;
            st = 1;
        }
        else
            st = 0;
    }
    cout << res << endl;
}