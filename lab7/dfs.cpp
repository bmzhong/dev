#include<iostream>
#include<cstdlib>
#define n 30
#define infinity 0
using namespace std;
int visited[n]= {0};
typedef int adjMatrix[n][n];
typedef struct Graph {
	int vexnum;
	int arcnum;
	adjMatrix arcs;
} Graph,*PGraph;
typedef struct EdgeNode {
	int adjvex;
	double weight;
	struct EdgeNode * next;
} EdgeNode,*PEdgeNode;
typedef struct VexNode {
	double data;
	PEdgeNode firstArc;
} VexNode,*PVexNode;
typedef VextNode AdjList[n];
typedef struct LGraph {
	int vexnum;
	int arcnum;
	AdjList vertices;
} LGraph,*PGraph;
void init(PGraph &Pg);
void tranvese(PGraph &Pg);
void dfs(PGraph &Pg,int k);
int main() {
	PGraph Pg;
//	init(Pg);

	return 0;
}

void init(PGraph &Pg) {
	Pg = new Graph;
	cin>>Pg->vexnum>>Pg->arcnum;
	for(int i=1; i<=Pg->vexnum; ++i) {
		for(int j=1; j<=Pg->vexnum; ++j) {
			Pg->arcs[i][j]=infinity;
		}
	}
	Pg->arcs[1][3]=1;
	Pg->arcs[2][1]=1;
	Pg->arcs[3][2]=1;
	Pg->arcs[3][6]=1;
	Pg->arcs[4][2]=1;
	Pg->arcs[4][3]=1;
	Pg->arcs[4][5]=1;
	Pg->arcs[5][2]=1;
	Pg->arcs[6][4]=1;
	Pg->arcs[7][4]=1;
	Pg->arcs[7][5]=1;
	Pg->arcs[7][6]=1;
	for(int i=1; i<=Pg->vexnum; ++i) {
		for(int j=1; j<=Pg->vexnum; ++j) {
			cout<<Pg->arcs[i][j]<<" ";
		}
		cout<<endl;
	}
}

void tranvese(PGraph &Pg) {
	for(int i=1; i<=7; ++i) {
		if(visited[i]==0) {
			dfs(Pg,i);
		}
	}
}

void dfs(PGraph &Pg,int k) {
	visited[k]=1;
	cout<<k<<"  ";
	for(int i=1; i<=Pg->vexnum; ++i) {
		if(Pg->arcs[k][i]!=infinity&&visited[i]==0) {
			dfs(Pg,i);
		}
	}
}



