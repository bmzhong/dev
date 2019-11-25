#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct Node {
	int data;
	struct Node *lchild;
	struct Node *rchild;
} Node,*PNode;
bool initTree(PNode &p,vector<int> v,int &i);
void disp(PNode &p);
int main() {
	PNode p=NULL;
	int i=0;
	vector<int> v{5,4,2,1,7,3,6};
	initTree(p,v,i);
	disp(p);
	return 0;
}
bool initTree(PNode &p,vector<int> v,int &i) {
	if(i>=v.size()){
		return false;
	}
	if(p==NULL) {
		PNode p=(PNode)malloc(sizeof(Node));
		p->lchild=NULL;
		p->rchild=NULL;
		p->data=v[i];
		i++;
		if(v[i]>p->data) {
			initTree(p->rchild,v,i);
		} else {
			initTree(p->lchild,v,i);
		}
	}
	return true;
}

void disp(PNode &p) {
	if(p->lchild) {
		disp(p->lchild);
	}
	cout<<p->data<<" ";
	if(p->rchild) {
		disp(p->rchild);
	}
}
