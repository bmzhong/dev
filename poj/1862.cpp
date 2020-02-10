#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int main()
{
    int n;
    double ans = 0, a;
    scanf("%d", &n);
    priority_queue<double> q;
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf", &a);
        q.push(a);
    }
    while (q.size() > 1)
    {
        double a1 = q.top();
        q.pop();
        double a2 = q.top();
        q.pop();
        double r = (double)sqrt(a1 * a2) * 2;
        q.push(r);
    }
    printf("%.3lf\n",q.top());
    system("pause");
    return 0;
}