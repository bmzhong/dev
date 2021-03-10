#include <iostream>
#include <map>
#include <vector>
using namespace std;
void func(int x, int y, int e, int &sum, map<int, int> m);
struct A
{
    int x;
    int y;
    int e;
};
int main()
{
    int n;
    cin >> n;
    n -= 4;
    vector<A> v;
    A a;
    map<int, int> m = {{6, 0}, {2, 1}, {5, 2}, {4, 4}, {6, 6}, {3, 7}, {7, 8}};
    for (int i = 2; i <= 7; ++i)
    {
        for (int j = 2; j <= 7; ++j)
        {
            for (int k = 2; k <= 7; ++k)
            {
                if (i + j + k == n)
                {
                    a.x = i;
                    a.y = j;
                    a.y = k;
                    v.push_back(a);
                }
                else if (i + j + k > n)
                {
                    break;
                }
            }
            if (i + j + 2 > n)
            {
                break;
            }
        }
    }
    int sum = 0;
    int len = v.size();
    for (int i = 0; i < len; ++i)
    {
        int x = v[i].x;
        int y = v[i].y;
        int e = v[i].e;
        if (x != 5 && y != 5 && e != 5 && x != 6 && y != 6 && e != 6)
        {
            func(x,y,e,sum,m);
        }
        else if (x == 5 && y == 5 && e == 5)
        {
            ++sum;
        }
        else if (x == 5 && y == 5 && e != 5 )
        {
        }
    }
}

void func(int x, int y, int e, int &sum, map<int, int> m)
{
    if (m[x] + m[y] == m[e])
    {
        if (m[x] == m[y])
        {
            sum += 2;
        }
        else
        {
            ++sum;
        }
    }
    else if (m[x] + m[e] == m[y])
    {
        if (m[x] == m[e])
        {
            sum += 2;
        }
        else
        {
            ++sum;
        }
    }
    else if (m[y] + m[e] == m[x])
    {
        if (m[y] == m[e])
        {
            sum += 2;
        }
        else
        {
            ++sum;
        }
    }
}