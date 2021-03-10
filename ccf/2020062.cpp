#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int n, a, b;
struct P
{
    int index, value;

    P() = default;
    P(int _value, int _index)
    {
        value = _value;
        index = _index;
    }
    bool operator<(const P &p) const
    {
        return index > p.index;
    }
};
priority_queue<P> A, B;
P p;
long long res = 0;
inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    return x * f;
}
int main()
{
    n = read();
    a = read();
    b = read();
    for (int i = 0; i < a; ++i)
    {
        p.index = read();
        p.value = read();
        A.push(p);
    }
    for (int i = 0; i < b; ++i)
    {
        p.index = read();
        p.value = read();
        B.push(p);
    }
    P Ap(0, 0), Bp(0, 0);
    while (!A.empty() && !B.empty())
    {
        Ap = A.top();
        A.pop();
        while (!B.empty() && Bp.index < Ap.index)
        {
            Bp = B.top();
            B.pop();
        }
        if (Bp.index == Ap.index)
            res += (long long)Ap.value * Bp.value;
    }
    while (!A.empty())
    {
        Ap = A.top();
        A.pop();
        if (Bp.index == Ap.index)
            res += (long long)Ap.value * Bp.value;
    }
    printf("%lld\n", res);
    system("pause");
    return 0;
}