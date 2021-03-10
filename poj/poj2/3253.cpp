#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n;
long long res = 0;
int main()
{
    scanf("%d", &n);
    int t;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &t);
        pq.push(t);
    }
    while (pq.size() > 1)
    {
        int m1 = pq.top();
        pq.pop();
        int m2 = pq.top();
        pq.pop();
        int m = m1 + m2;
        res += m;
        pq.push(m);
    }
    printf("%lld\n",res);
    system("pause");
    return 0;
}