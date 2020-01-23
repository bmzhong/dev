#include <iostream>
#include <queue>
using namespace std;
bool visited[50] = {false};
typedef int adjMatrix[50][50];
struct Graph
{
    int vexnum;
    int arcnum;
    adjMatrix arcs;
};
typedef Graph *PG;
void bfs(PG &pg, int k);
void init(PG &pg);
int main()
{
    PG pg;
    init(pg);
    for(int k=0;k<pg->vexnum;++k){
        bfs(pg,k);
    }
    system("pause");
    return 0;
}
void init(PG &pg)
{
    pg = new Graph;
    cin >> pg->vexnum;
    for (int i = 0; i < pg->vexnum; ++i)
    {
        for (int j = 0; j < pg->vexnum; ++j)
        {
            cin >> pg->arcs[i][j];
        }
    }
}

void bfs(PG &pg, int k)
{
    queue<int> q;
    if (!visited[k])
    {
        q.push(k);
        visited[k] = true;
    }
    while (!q.empty())
    {
        int k = q.front();
        cout << k << " ";
        q.pop();
        for (int i = 0; i < pg->vexnum; ++i)
        {
            if (!visited[i] && pg->arcs[k][i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}