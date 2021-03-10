#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 9999999;
int n, m, dist = 0, d[5002], graph[5002][5002], visited[5002];
void init();
void prime();
int main()
{
    int a1, a2, a3;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i)
    {
        cin >> a1 >> a2 >> a3;
        if (a1 != a2)
            graph[a1][a2] = graph[a2][a1] = min(a3, graph[a1][a2]);
    }
    prime();
    int k = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (visited[i] == 0)
        {
            k = 1;
            break;
        }
    }
    if (k)
    {
        cout << "orz" << endl;
    }
    else
    {
        cout << dist << endl;
    }
    system("pause");
    return 0;
}

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        d[i] = inf;
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            graph[i][j] = inf;
        }
    }
}

void prime()
{
    for (int i = 1; i <= n; ++i)
    {
        if (graph[1][i] != 0)
        {
            d[i] = graph[1][i];
        }
    }
    visited[1] = 1;
    int last = 1;
    for (int i = 1; i < n; ++i)
    {
        int mins = inf, k = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (!visited[j] && d[j] < mins)
            {
                mins = d[j];
                k = j;
            }
        }
        visited[k] = 1;
        dist += d[k];
        for (int j = 1; j <= n; ++j)
        {
            if (!visited[j] && d[j] > d[k] + graph[k][j])
            {
                d[j] = graph[k][j];
            }
        }
    }
}