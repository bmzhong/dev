#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n, m, c;
    scanf("%d", &n);
    multiset<int> s, v;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &c);
        s.insert(c);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d", &c);
        v.insert(c);
    }
    vector<int> v1(m + 1), v2(m + n + 1), v3(m + 1);
    v1.assign(m + 1, 99999999);
    v2.assign(m + n + 1, 99999999);
    v3.assign(m + 1, 99999999);
    set_intersection(s.begin(), s.end(), v.begin(), v.end(), v1.begin());
    set_union(s.begin(), s.end(), v.begin(), v.end(), v2.begin());
    set_difference(s.begin(), s.end(), v.begin(), v.end(), v3.begin());
    int len1 = v1.size(), len2 = v2.size(), len3 = v3.size();
    if (v1[0] == 99999999)
    {
        printf("\n");
    }
    else
    {
        for (int i = 0; i < len1 - 1; ++i)
        {
            if (v1[i + 1] == 99999999 && v1[i] != 99999999)
            {
                printf("%d\n", v1[i]);
                break;
            }
            else 
                printf("%d ", v1[i]);
        }
    }

    if (v2[0] == 99999999)
    {
        printf("\n");
    }
    else
    {
        for (int i = 0; i < len2 - 1; ++i)
        {
            if (v2[i + 1] == 99999999 && v2[i] != 99999999)
            {
                printf("%d\n", v2[i]);
                break;
            }
            else 
                printf("%d ", v2[i]);
        }
    }

    if (v3[0] == 99999999)
    {
        printf("\n");
    }
    else
    {
        for (int i = 0; i < len3 - 1; ++i)
        {
            if (v3[i + 1] == 99999999 && v3[i] != 99999999)
            {
                printf("%d\n", v3[i]);
                break;
            }
            else 
                printf("%d ", v3[i]);
        }
    }

    system("pause");
    return 0;
}
