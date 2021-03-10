#include <iostream>
using namespace std;
const int n = 600;
typedef int adjMatrix[n][n];
struct Graph
{
    adjMatrix arcs;
    int vexnum;
    int arcnum;
};
void dfs(Graph &G, int k, bool visited[]);
int main()
{
    Graph G;
    int a, b;
    while (cin >> G.vexnum >> G.arcnum && G.vexnum != 0)
    {
        for (int i = 1; i <= G.vexnum; ++i)
        {
            for (int j = 1; j <= G.vexnum; ++j)
            {
                G.arcs[i][j] = 0;
            }
        }
        bool visited[G.vexnum + 1] = {false};
        for (int i = 1; i <= G.arcnum; ++i)
        {
            cin >> a >> b;
            G.arcs[a][b] = 1;
            G.arcs[b][a] = 1;
        }
        dfs(G,1,visited);
        int flag=0;
        for(int i=1;i<=G.vexnum;++i){
            if(!visited[i]){
                cout<<"NO"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"YES"<<endl;
        }
    }
    system("pause");
    return 0;
}

void dfs(Graph &G, int k, bool visited[])
{
    visited[k] = true;
    for (int i = 1; i <= G.vexnum; ++i)
    {
        if (!visited[i] && G.arcs[k][i])
        {
            dfs(G, i, visited);
        }
    }
}
