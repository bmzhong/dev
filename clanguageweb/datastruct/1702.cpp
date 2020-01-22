#include <iostream>
using namespace std;
bool visited[50] = {false};
const int n = 50;
typedef int adjMatrix[50][50];
struct Graph
{
    int vexnum = 0;
    int arcnum = 0;
    adjMatrix arcs;
};
typedef Graph *PG;
void init(PG &pg);
void dfs(PG &pg, int k);
int main()
{
    PG pg;
    init(pg);
    for (int i = 0; i < pg->vexnum; ++i)
    {
        if (!visited[i])
        {
            dfs(pg, i);
        }
    }
    cout<<endl;
    system("pause");
    return 0;
}

void init(PG &pg)
{
    int a;
    cin >> a;
    pg=new Graph;
    pg->vexnum = a;
    for (int i = 0; i < pg->vexnum; ++i)
    {
        for (int j = 0; j < pg->vexnum; ++j)
        {
            cin >> a;
            pg->arcs[i][j] = a;
        }
    }
}

void dfs(PG &pg, int k)
{
    visited[k] = true;
    cout << k << " ";
    for (int i = 0; i < pg->vexnum; ++i)
    {
        if (pg->arcs[k][i] != 0 && !visited[i])
        {
            dfs(pg, i);
        }
    }
}
//34row 使用pg之前先new 一个。