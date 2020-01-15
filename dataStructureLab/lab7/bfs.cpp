#include<iostream>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<iterator>
#define n 30
#define infinity 0
using namespace std;
int visited[n] = {0};
int visitedList[n] = {0};
typedef int adjMatrix[n][n];
typedef struct Graph {
    int vexnum;
    int arcnum;
    adjMatrix arcs;
} Graph, *PGraph;
typedef struct EdgeNode {
    int adjvex;
    double weight;
    struct EdgeNode *next;
} EdgeNode, *PEdgeNode;
typedef struct VexNode {
    int data;
    PEdgeNode firstArc;
} VexNode, *PVexNode;
typedef VexNode AdjList[n];
typedef struct LGraph {
    int vexnum;
    int arcnum;
    AdjList vertices;
} LGraph, *PLGraph;

void init(PGraph &Pg);
void bfsMatrix(PGraph &Pg,queue<int> &q, int s) ;
void initListMatrix(PLGraph &PL);
void tranverse(PGraph &Pg,queue<int> &q);
void bfsList(PLGraph &PL,queue<int> &q,int s);
void tranverseList(PLGraph &PL,queue<int> &q);
int main() {
    PGraph Pg;
    PLGraph PL;
    queue<int> q;
    init(Pg);
    tranverse(Pg,q);
    initListMatrix(PL);
    tranverseList(PL,q);
    return 0;
}

void tranverseList(PLGraph &PL,queue<int> &q) {
    for (int i = 0; i < PL->vexnum; ++i) {
        bfsList(PL, q, i);
    }
}

void tranverse(PGraph &Pg,queue<int> &q) {
    for (int i = 1; i <= Pg->vexnum; ++i) {
        bfsMatrix(Pg, q, i);
    }
    cout<<endl<<endl;
}

void bfsMatrix(PGraph &Pg,queue<int> &q,int s) {
    if (visited[s]==0) {
        visited[s]=1;
        q.push(s);
    }
    while(!q.empty()) {
        int k=q.front();
        cout<<k<<"  ";
        q.pop();
        for(int i=1; i<=Pg->vexnum; ++i) {
            if(Pg->arcs[k][i]!=0&&visited[i]==0) {
                visited[i]=1;
                q.push(i);
            }
        }
    }
}

void bfsList(PLGraph &PL,queue<int> &q,int s) {
    if(visitedList[s]==0) {
        visitedList[s]=1;
        q.push(s);
    }
    while(!q.empty()) {
        int k=q.front();
        q.pop();
        cout<<"v"<<k<<"  ";
        PEdgeNode p=PL->vertices[k].firstArc;
        while(p) {
            if(visitedList[p->adjvex]==0) {
                visitedList[p->adjvex]=1;
                q.push(p->adjvex);
            }
            p=p->next;
        }
    }
}

void init(PGraph &Pg) {
    Pg = new Graph;
    cin >> Pg->vexnum >> Pg->arcnum;
    for (int i = 1; i <= Pg->vexnum; ++i) {
        for (int j = 1; j <= Pg->vexnum; ++j) {
            cin>>Pg->arcs[i][j];
        }
    }
}

void initListMatrix(PLGraph &PL) {
    PL= new LGraph;
    cin>>PL->vexnum>>PL->arcnum;
    for(int i=0; i<PL->vexnum; ++i) {
        PL->vertices[i].data=i;
        PL->vertices[i].firstArc=NULL;
    }
    int start,end,weight;
    for(int i=0; i<PL->arcnum; ++i) {
        cin>>start>>end>>weight;
        PEdgeNode p=new EdgeNode;
        p->adjvex=end;
        p->weight=weight;
        if(PL->vertices[start].firstArc!=NULL) {
            p->next=PL->vertices[start].firstArc;
        } else {
            p->next=NULL;
        }
        PL->vertices[start].firstArc=p;

        PEdgeNode q=new EdgeNode;
        q->adjvex=start;
        q->weight=weight;
        if(PL->vertices[end].firstArc!=NULL) {
            q->next=PL->vertices[end].firstArc;
        } else {
            q->next=NULL;
        }
        PL->vertices[end].firstArc=q;
    }
}

