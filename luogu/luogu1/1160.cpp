#include <iostream>
#include <cstdio>
#include <algorithm>
#include <list>
#include <set>
using namespace std;
int main()
{
    list<int> v;
    int n, a, b, m;
    scanf("%d", &n);
    v.resize(n);
    *v.begin() = 1;
    int arr[n + 10];
    for (int i = 2; i <= n; ++i)
    {
        scanf("%d%d", &a, &b);
        list<int>::iterator it = find(v.begin(), v.end(), a);
        if (b == 0)
        {
            v.insert(it, i);
        }
        else
        {
            v.insert(++it, i);
        }
    }
    scanf("%d", &m);
    set<int> st;

    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &a);
        set<int>::iterator p = st.find(a);
        if (p == st.end())
        {
            list<int>::iterator it = find(v.begin(), v.end(), a);
            if (it != v.end())
            {
                st.insert(a);
                v.erase(it);
                --n;
            }
        }
    }
    int i = 0;
    for (list<int>::iterator it = v.begin(); it != v.end(); ++it)
    {
        if (i == n)
        {
            break;
        }
        printf("%d ", *it);
        ++i;
    }
    printf("\n");
    system("pause");
    return 0;
}