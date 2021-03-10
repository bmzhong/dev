#include <iostream>
using namespace std;
const int n = 52;
typedef int adjMatrix[n][n];
struct Graph
{
    int vexnum;
    adjMatrix arcs;
};
struct Node
{
    int data;
    struct Node *lchild = NULL;
    struct Node *sibling = NULL;
};
typedef Node *PNode;
bool visited[n] = {false};
void DFSTree(Graph &pg, PNode &p, int k);
void create(Graph &pg);
void DFSForest(Graph &pg, PNode &T);
void preTran(PNode &p);
int main()
{
    Graph pg;
    PNode T;
    create(pg);
    DFSForest(pg, T);
    system("pause");
    return 0;
}
void create(Graph &pg)
{
    cin >> pg.vexnum;
    for (int i = 0; i < pg.vexnum; ++i)
    {
        for (int j = 0; j < pg.vexnum; ++j)
        {
            cin >> pg.arcs[i][j];
        }
    }
}

void DFSForest(Graph &pg, PNode &T)
{
    PNode p, q;
    for (int i = 0; i < pg.vexnum; ++i)
    {
        if (!visited[i])
        {
            p = new Node;
            p->data = i;
            if (!T)
            {
                T = p;
            }
            else
            {
                q->sibling = p;
            }
            q = p;
            DFSTree(pg, p, i);
            preTran(p);
            cout << endl;
        }
    }
}

void DFSTree(Graph &pg, PNode &T, int k)
{
    int flag = 0;
    PNode q, p;
    visited[k] = true;
    for (int j = 0; j < pg.vexnum; ++j)
    {
        if (!visited[j] && pg.arcs[k][j])
        {
            p = new Node;
            p->data = j;
            if (flag == 0)
            {
                T->lchild = p;
                flag = 1;
            }
            else
            {
                q->sibling = p;
            }
            q = p;
            DFSTree(pg, q, j);
        }
    }
}

void preTran(PNode &p)
{
    if (p)
    {
        cout << p->data << " ";
        preTran(p->lchild);
        preTran(p->sibling);
    }
}