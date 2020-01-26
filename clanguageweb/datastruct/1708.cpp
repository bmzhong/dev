#include <iostream>
using namespace std;
const int inf = 999999;
const int n = 50;
typedef int adjMatrix[n][n];
struct Graph
{
    adjMatrix arcs;
    int vexnum;
};
void init(Graph &G, int &x);
void dijskra(Graph &G, int x);
int main()
{
    Graph G;
    int x;
    init(G, x);
    dijskra(G, x);
    system("pause");
    return 0;
}

void init(Graph &G, int &x)
{
    cin >> G.vexnum;
    cin >> x;
    int a;
    for (int i = 0; i < G.vexnum; ++i)
    {
        for (int j = 0; j < G.vexnum; ++j)
        {
            cin >> a;
            if (a != 0)
            {
                G.arcs[i][j] = a;
            }
            else
            {
                G.arcs[i][j] = inf;
            }
        }
    }
}

void dijskra(Graph &G, int x)
{
    bool visited[G.vexnum] = {false};
    int weight[G.vexnum] = {0};
    for (int i = 0; i < G.vexnum; ++i)
    {
        weight[i] = G.arcs[x][i];
    }
    visited[x] = true;
    for (int i = 0; i < G.vexnum; ++i)
    {
        int min = inf;
        int p;
        for (int j = 0; j < G.vexnum; ++j)
        {
            if (!visited[j] && weight[j] < min)
            {
                min = weight[j];
                p = j;
            }
        }
        visited[p] = true;
        for (int j = 0; j < G.vexnum; ++j)
        {
            if (!visited[j] && weight[j] > (weight[p] + G.arcs[p][j]))//不要写成了!weight[j]
            {
                weight[j] = weight[p] + G.arcs[p][j];
            }
        }
    }
    for (int i = 0; i < G.vexnum; ++i)
    {
        if (i != x)
        {
            if (weight[i] == inf)
            {
                cout << "-1 ";
            }
            else
            {
                cout << weight[i] << " ";
            }
        }
    }
    cout << endl;
}