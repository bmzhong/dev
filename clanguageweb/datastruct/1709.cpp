#include <iostream>
#include <string.h>
using namespace std;
const int inf = 999999;
const int n = 50;
typedef int adjMatrix[n][n];
struct Graph
{
    adjMatrix arcs;
    int vexnum;
};
void init(Graph &G);
void floyd(Graph &G);
void disp(Graph &G);
int main()
{
    Graph G;
    init(G);
    floyd(G);
    disp(G);
    system("pause");
    return 0;
}

void init(Graph &G)
{
    int a;
    cin >> G.vexnum;
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

void floyd(Graph &G)
{
    for (int k = 0; k < G.vexnum; ++k)
    {

        for (int i = 0; i < G.vexnum; ++i)
        {
            for (int j = 0; j < G.vexnum; ++j)
            {
                if (G.arcs[i][j] > G.arcs[i][k] + G.arcs[k][j])
                {
                    G.arcs[i][j] = G.arcs[i][k] + G.arcs[k][j];
                }
            }
        }
    }
}

void disp(Graph &G)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        for (int j = 0; j < G.vexnum; ++j)
        {
            if (i == j)
            {
                cout << "0 ";
            }
            else if (G.arcs[i][j] == inf)
            {
                cout << "-1 ";
            }
            else
            {
                cout << G.arcs[i][j] << " ";
            }
        }
        cout << endl;
    }
}