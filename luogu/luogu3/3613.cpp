#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int n, q, p, x, y, k;
struct A
{
    int in = 0, v = 0;
    A(int _in, int _v)
    {
        in = _in;
        v = _v;
    }
};
vector<A> v[100001];
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; ++i)
    {
        scanf("%d", &p);
        if (p == 1)
        {
            scanf("%d%d%d", &x, &y, &k);
            int len = v[x].size();
            int j = 0;
            for (; j < len; ++j)
            {
                if (v[x][j].in == y)
                {
                    v[x][j].v = k;
                    break;
                }
            }
            if (j == len)
                v[x].push_back(A(y, k));
        }
        else
        {
            scanf("%d%d", &x, &y);
            int len = v[x].size();
            for (int j = 0; j < len; ++j)
            {
                if (v[x][j].in == y)
                {
                    printf("%d\n", v[x][j].v);
                }
            }
        }
    }
    system("pause");
    return 0;
}