#include <iostream>
#include <map>
using namespace std;
int m, n, num, A[1000001];
map<int, int> mp;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}
int main()
{
    n = read();
    m = read();
    for (int i = 1; i <= n; ++i)
    {
        A[i] = read();
    }
    int a = 1, b = n, l = 1, r = 0;
    while (true)
    {
        if (num != m)
        {
            for (r = r + 1; r <= n; ++r)
            {
                mp[A[r]]++;
                if (mp[A[r]] == 1)
                {
                    ++num;
                    if (num == m)
                        break;
                }
            }
        }
        while (l <= r)
        {
            --mp[A[l]];
            if (!mp[A[l++]])
            {
                --num;
                break;
            }
        }
        if (num == m - 1 && !mp[A[l - 1]] && r - l + 1 < b - a)
        {
            a = l - 1;
            b = r;
        }
        if (r > n)
            break;
    }
    printf("%d %d\n", a, b);
    system("pause");
    return 0;
}
