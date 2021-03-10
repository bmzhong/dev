#include <iostream>
#include <stack>
using namespace std;
int n, a[3000001], res[3000001];
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
stack<int> s;
int main()
{
    n = read();
    for (int i = 1; i <= n; ++i)
    {
        a[i] = read();
    }
    for (int i = 1; i <= n; ++i)
    {
        while (!s.empty() && a[s.top()] < a[i])
        {
            res[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        res[s.top()] = 0;
        s.pop();
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%d%c", res[i], i == n ? '\n' : ' ');
    }
    system("pause");
    return 0;
}