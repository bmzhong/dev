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
void search(PNode &p,PNode &q,int v);
void searchFather(PNode &p,PNode &f,int v);
int main() {
	PNode p=NULL,q=NULL,f=NULL;
	vector<int> v {5,4,2,1,7,3,6};
	for(int i=0; i<v.size(); ++i) {
		insert(p,v[i]);
	}
	disp(p);
	search(p,q,4);
	cout<<endl<<q->data<<endl;
	searchFather(p,f,4);
	cout<<f->data<<endl;
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
	if(p==NULL) {
		q=NULL;
	}else if(p->data==v){
		q=p;
	}else if(p->data>v){
		search(p->lchild,q,v);
	}else{
		search(p->rchild,q,v);
	}
}
void searchFather(PNode &p,PNode &f,int v){
	if(!p||(!p->lchild&&!p->rchild)){
		f=NULL;
	}else if((p->lchild&&p->lchild->data==v)||(p->rchild&&p->rchild->data==v)){
		f=p;
	}else if(p->rchild&&p->data>v){
		searchFather(p->lchild,f,v);
	}else if(p->rchild&&p->data<=v){
		searchFather(p->lchild,f,v);
	}
}
