#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string mid, post;
void rec(int ml, int mr, int pl, int pr);
int main()
{
    cin >> mid;
    cin >> post;
    int len = mid.length();
    rec(0, len - 1, 0, len - 1);
    cout << endl;
    system("pause");
    return 0;
}
void rec(int ml, int mr, int pl, int pr)
{
    cout << post[pr];
    if(pr==pl)
        return;
    int pos1 = -1;
    for (int i = ml; i <= mr; ++i)
    {
        if (mid[i] == post[pr])
        {
            pos1 = i;
            break;
        }
    }
    if (pos1 == ml)
    {
        rec(ml + 1, mr, pl, pr - 1);
        return;
    }
    if (pos1 == mr)
    {
        rec(ml, mr - 1, pl, pr - 1);
        return;
    }
    int pos2 = -1;
    for (int i = pl; i <= pr; ++i)
    {
        if (post[i] == mid[pos1 - 1])
        {
            pos2 = i;
            break;
        }
    }
    rec(ml, pos1 - 1, pl, pos2);
    rec(pos1 + 1, mr, pos2 + 1, pr - 1);
}