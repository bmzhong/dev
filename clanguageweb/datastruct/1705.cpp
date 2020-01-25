#include <iostream>
using namespace std;
const int n = 50;
const int inf = 999999;
typedef int adjMatrix[n][n];
struct Graph
{
    int vexnum;
    adjMatrix arcs;
};
bool visited[n] = {false};
void prime(Graph &pg, int &sum);
void init(Graph &pg);
int main()
{
    Graph pg;
    init(pg);
    int sum;
    prime(pg,sum);
    cout<<sum<<endl;
    system("pause");
    return 0;
}

void init(Graph &pg)
{
    int b;
    cin >> pg.vexnum;
    for (int i = 0; i < pg.vexnum; ++i)
    {
        for (int j = 0; j < pg.vexnum; ++j)
        {
            cin >> b;
            if (b != 0)
            {
                pg.arcs[i][j] = b;
            }
            else
            {
                pg.arcs[i][j] = inf;
            }
        }
    }
}

void prime(Graph &pg, int &sum)
{
    sum = 0;
    int weiht[pg.vexnum];
    for (int i = 0; i < pg.vexnum; ++i)
    {
        weiht[i] = pg.arcs[0][i];
    }
    visited[0] = true;
    for (int i = 1; i < pg.vexnum; ++i)
    {
        int min = inf;
        int p;
        for (int j = 0; j < pg.vexnum; ++j)
        {
            if (!visited[j] && weiht[j] < min)
            {
                min = weiht[j];
                p = j;
            }
        }
        sum += weiht[p];
        visited[p] = true;
        for (int j = 0; j < pg.vexnum; ++j)
        {
            if (!visited[j] && pg.arcs[p][j] < weiht[j])
            {
                weiht[j] = pg.arcs[p][j];
            }
        }
    }
}