#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int C, H, R, T, N;
double res[101];
const double g = 10.0;
void solve();
int main()
{
    scanf("%d", &C);
    for (int x = 0; x < C; ++x)
    {
        scanf("%d%d%d%d", &N, &H, &R, &T);
        solve();
    }
    system("pause");
    return 0;
}
double calcu(int T)
{
    if (T <= 0)
        return H;
    double t = sqrt(2 * H / g);
    int k = (int)T / t;
    double y;
    if (k & 1)
        y = H - 0.5 * g * (k * t + t - T) * (k * t + t - T);
    else
        y = H - 0.5 * g * (T - k * t) * (T - k * t);
    return y;
}
void solve()
{
    for (int i = 0; i < N; ++i)
    {
        res[i] = calcu(T - i);
    }
    sort(res, res + N);
    for (int i = 0; i < N; ++i)
    {
        printf("%.2lf%c", res[i] + 2 * R * i / 100.0, i == N - 1 ? '\n' : ' ');
    }
}