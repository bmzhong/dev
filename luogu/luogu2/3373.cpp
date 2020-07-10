#include <iostream>
#include <cstdio>
using namespace std;
#define min(x, y) (x) > (y) ? (y) : (x)
#define max(x, y) (x) > (y) ? (x) : (y)
int n, m, p, A[200001], S[200001], M[200001];
int main()
{
    scanf("%d", &n, &m, &p);
}
void add(int a, int b, int x, int k, int l, int r)
{
    if (a <= l && r <= b)
        A[k] = (A[k] % p + x % p) % p;
    else if (l < b && a < r)
    {
        S[k] += ((min(b, r) - max(a, l)) * x) % p;
        add(a, b, x, 2 * k, l, (l + r) / 2);
        add(a, b, x, 2 * k + 1, (l + r) / 2, r);
    }
}

void mul(int a, int b, int x, int k, int l, int r)
{
    if (a <= l && r <= b)
        A[k] = (A[k] % p + x % p) % p;
    else if (l < b && a < r)
    {
        S[k] += ((min(b, r) - max(a, l)) * x) % p;
        add(a, b, x, 2 * k, l, (l + r) / 2);
        add(a, b, x, 2 * k + 1, (l + r) / 2, r);
    }
}
int sum(int a, int b, int k, int l, int r)
{
    if (b <= l || r <= a)
        return 0;
    else if (a <= l && b <= r)
        return (S[k] + A[k] * (r - l)) % p;
    else
    {
        int res = (A[k] * (min(b, r) - max(a, l))) % p;
        res = (res + sum(a, b, 2 * k, l, (l + r) / 2)) % p;
        res = (res + sum(a, b, 2 * k + 1, (l + r) / 2, r)) % p;
        return res;
    }
}