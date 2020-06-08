#include <iostream>
#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, temp, res = 0;
    scanf("%d%d", &m, &n);
    list<int> li;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &temp);
        list<int>::iterator it = find(li.begin(), li.end(), temp);
        if (it == li.end())
        {
            ++res;
            if (li.size()>=m)
                li.erase(li.begin());
            li.push_back(temp);
        }
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}