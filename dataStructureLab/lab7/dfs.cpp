#include<iostream>
#include<cstdlib>
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

void dfs(PGraph &Pg, int k);

void tranverse(PGraph &Pg);

void initListMatrix(PLGraph &PL);

void dfsList(PLGraph &PL, int k);

void tranverseList(PLGraph &PL);

int main() {
	PGraph Pg;
	PLGraph PL;
	init(Pg);
	tranverse(Pg);
	initListMatrix(PL);
	tranverseList(PL);
	return 0;
}

void tranverseList(PLGraph &PL) {
	for (int i = 0; i < PL->vexnum; ++i) {
		if (visitedList[i] == 0) {
			dfsList(PL, i);
		}
	}
}

void dfsList(PLGraph &PL, int k) {
	visitedList[k] = 1;
	cout << "v" << PL->vertices[k].data << " ";
	PEdgeNode p = new EdgeNode;
	p = PL->vertices[k].firstArc;
	while (p&&visitedList[p->adjvex]==0) {
		dfsList(PL, p->adjvex);
		p = p->next;
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


void tranverse(PGraph &Pg) {
	for (int i = 1; i <= 7; ++i) {
		if (visited[i] == 0) {
			dfs(Pg, i);
		}
	}
	cout<<endl<<endl;
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

void dfs(PGraph &Pg, int k) {
	visited[k] = 1;
	cout << k << "  ";
	for (int i = 1; i <= Pg->vexnum; ++i) {
		if (Pg->arcs[k][i] != infinity && visited[i] == 0) {
			dfs(Pg, i);
		}
	}
}
