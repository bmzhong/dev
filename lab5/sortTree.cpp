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
void searchFather(PNode &root,PNode &p,PNode &f,int v);
void prior(PNode &p,PNode &q);
void deleteElem(PNode &root,int v);
void searchElem(PNode &p,int m);
int main() {
	PNode p=NULL,q=NULL,f=NULL;
	vector<int> v;
	int e,count=0;
	cout<<"输入元素个数: "<<endl;
	cin>>count;
	cout<<"依次输入每个元素："<<endl;
	for(int i=0; i<count; ++i) {
		cin>>e;
		v.push_back(e);
		insert(p,v[i]);
	}
	int m,n;
	cout<<"二叉树中序遍历序列："<<endl;
	disp(p);
	cout<<endl<<"输入需要查找的数据："<<endl;
	cin>>m;
	searchElem(p,m);
	cout<<"输入需要删除的数据："<<endl;
	cin>>n;
	deleteElem(p,n);
	cout<<"二叉树中序遍历序列："<<endl;
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
	if(p==NULL) {
		q=NULL;
	} else if(p->data==v) {
		q=p;
	} else if(p->data>v) {
		search(p->lchild,q,v);
	} else {
		search(p->rchild,q,v);
	}
}
void searchFather(PNode &root,PNode &p,PNode &f,int v) {
	if(root->data==v) {
		f=root;
	}
	if(!p||(!p->lchild&&!p->rchild)) {
		f=NULL;
	} else if((p->lchild&&p->lchild->data==v)||(p->rchild&&p->rchild->data==v)) {
		f=p;
		return ;
	} else if(p->lchild&&p->data>v) {
		searchFather(root,p->lchild,f,v);
	} else if(p->rchild&&p->data<v) {
		searchFather(root,p->rchild,f,v);
	}
}

void deleteElem(PNode &root,int v) {
	PNode q=NULL,f=NULL;
	search(root,q,v);
	searchFather(root,root,f,v);
	if(!q->lchild&&!q->rchild) {
		if(q==root){
			free(q);
			root=NULL;
		}
		if(f->lchild->data==v) {
			f->lchild=NULL;
			free(q);
		} else if(f->rchild->data==v) {
			f->rchild=NULL;
			free(q);
		}
	} else if(!q->lchild&&q->rchild) {
		if(q==root) {
			PNode y=root;
			root=root->rchild;
			free(y);
		}else if(f->lchild->data==v) {
			f->lchild=q->rchild;
			free(q);
		} else if(f->rchild->data==v) {
			f->rchild=q->rchild;
			free(q);
		}
	} else if(!q->rchild&&q->lchild) {
		if(q==root) {
			PNode y=root;
			root=root->lchild;
			free(y);
		}else if(f->lchild->data==v) {
			f->lchild=q->lchild;
			free(q);
		} else if(f->rchild->data==v) {
			f->rchild=q->lchild;
			free(q);
		}
	} else if(q->lchild&&q->rchild) {
		PNode p=q->lchild,t=q;
		while(p->rchild) {
			t=p;
			p=p->rchild;
		}
		if(t!=q) {
			if(p->lchild) {
				t->rchild=p->lchild;
			} else {
				t->rchild=NULL;
			}
			q->data=p->data;
			free(p);
		} else {
			if(p->lchild) {
				q->lchild=p->lchild;
			} else {
				q->lchild=NULL;
			}
			q->data=p->data;
			free(p);
		}
	}
}

void searchElem(PNode &p,int m) {
	PNode q=NULL,f=NULL;
	search(p,q,m);
	searchFather(p,p,f,m);
	if(q->lchild) {
		cout<<"左孩子为：  "<<q->lchild->data<<"	";
	} else {
		cout<<"没有左孩子   ";
	}
	if(q->rchild) {
		cout<<"右孩子为：  "<<q->rchild->data<<"    ";
	} else {
		cout<<"没有右孩子   ";
	}
	if(f==p&&q==p) {
		cout<<"此节点为根节点	";
	} else {
		cout<<"父节点为：	"<<f->data;
	}
	cout<<endl;
}

