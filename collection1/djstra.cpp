#include <iostream>
#include<iomanip>
using namespace std;
#define  num  100
#define inf  100000
void path(int *last,int first, int aim);
void dijkstra(int n, int v, int *distance, int *last, int k[num][num]);
void init(int &n,int &arcs,int *distance,int *last,int k[num][num]);
void showMatrix(int k[num][num],int n);
int main() {
	int distance[num];     
	int k[num][num];   
	int n, arcs;       
	int last[num];
	init(n,arcs,distance,last,k);
	showMatrix(k,n);     
	dijkstra(n, 1, distance, last, k);
	cout << "源点到点的最短路径长度: " << distance[n] << endl;
	cout << "源点到点的路径为: ";
	path(last, 1, n);
	return 0;
}

void init(int &n,int &arcs,int *distance,int *last,int c[num][num]) {
	cout<<"请输入顶点数和边的数目: "<<endl; 
	cin >> n >>arcs;
	int v1, v2, weight;          
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			c[i][j] = inf;
		}
	}
	cout<<"请分别输入两个临界点和权值: "<<endl;
	for(int i=1; i<=arcs; ++i) {
		cin >> v1 >> v2 >> weight;  
		c[v1][v2] = c[v2][v1] = weight;
	}
	for(int i=1; i<=n; ++i) {
		distance[i] = inf;
	}
}

void showMatrix(int k[num][num],int n) {
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cout << setw(8) << left << setfill(' ')<<k[i][j]<<"  ";
		}
		cout<<endl;
	}
}

void dijkstra(int n, int v, int *distance, int *last, int k[num][num]) {
	bool visited[num];
	for(int i=1; i<=n; ++i) {
		distance[i] = k[v][i];   
		visited[i] = 0;           
		if(distance[i] == inf) 
			last[i] = 0;    
		else
			last[i] = v;
	}
	distance[v] = 0;
	visited[v] = 1;
	for(int i=2; i<=n; ++i) {
		int temp = inf;
		int u = v;
		for(int j=1; j<=n; ++j) {
			if((!visited[j]) && distance[j]<temp) {
				u = j;             
				temp = distance[j];
			}
		}
		visited[u] = 1;    
		for(int j=1; j<=n; ++j) {
			if((!visited[j]) && k[u][j]<inf) {
				int newdistance = distance[u] + k[u][j];
				if(newdistance < distance[j]) {
					distance[j] = newdistance;
					last[j] = u;
				}
			}
		}
	}
}
void path(int *last,int first, int aim) {
	int mark[num];
	int index = 1;
	mark[index] = aim;
	index++;
	int temp = last[aim];
	while(temp != first) {
		mark[index] = temp;
		index++;
		temp = last[temp];
	}
	mark[index] = first;
	for(int i=index; i>=1; --i) {
		if(i != 1) {
			cout << mark[i] << " -> ";
		} else {
			cout << mark[i] << endl;
		}
	}
}

