#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, L, P, res;
pair<int, int> A[10001];
void solve();
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &A[i].first, &A[i].second);
    }
    scanf("%d%d", &L, &P);
    for (int i = 0; i < n; ++i)
    {
        A[i].first = L - A[i].first;
    }
    sort(A, A + n);
    solve();
    system("pause");
    return 0;
}
void solve()
{
    priority_queue<int, vector<int>, less<int>> pq;
    int i = 0, j = 0;
    pq.push(P);
    res = -1;
    while (i < L)
    {
        if (pq.empty())
            break;
        int f = pq.top();
        pq.pop();
        i += f;
        while (j < n && A[j].first <= i)
            pq.push(A[j++].second);
        ++res;
    }
    if (i < L)
        printf("-1\n");
    else
        printf("%d\n", res);
}