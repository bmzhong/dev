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
bool insert(PNode &p,int v);
void disp(PNode &p);
int main() {
	PNode p=NULL;
	vector<int> v {5,4,2,1,7,3,6};
	for(int i=0; i<v.size(); ++i) {
		insert(p,v[i]);
	}
	disp(p);
	return 0;
}
bool insert(PNode &p,int v) {
	if(p==NULL) {
		p=(PNode)malloc(sizeof(Node));
		p->lchild=NULL;
		p->rchild=NULL;
		p->data=v;
		return true;
	} else if(v>=p->data) {
		insert(p->rchild,v);
	} else {
		insert(p->lchild,v);
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

void search(PNode &p,PNode &q,int v) {
	if(!p->lchild&&!p->rchild&&p->data!=v) {
		q=NULL;
	}else if()
}
bool delete(PNode &p,int v) {
	if(!p->lchild&&p->!rchild) {
		free(p);
		return true;
	} else if(!p->lchild&&p->rchild) {

	}
}
