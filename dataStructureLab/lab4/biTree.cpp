#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;
typedef int ElementType;
typedef struct BiNode {
	ElementType data;
	struct BiNode* lchild;
	struct BiNode* rchild;
} BiNode,*BiTree;
Status createBiTree(BiTree &T);
Status preTraverse(BiTree &T);
Status midTraverse(BiTree &T);
Status afterTraverse(BiTree &T);
int main() {
	BiTree T;
	createBiTree(T);
	cout<<"先序遍历序列：";
	preTraverse(T);
	cout<<endl;
	cout<<"中续遍历序列："; 
	midTraverse(T);
	cout<<endl;
	cout<<"后续遍历序列：";
	afterTraverse(T);
	cout<<endl;
	return 0;
}

Status createBiTree(BiTree &T) {
	char ch;
	cin>>ch;
	if(ch=='.') {
		T=NULL;
	} else {
		T=(BiTree)malloc(sizeof(BiNode));
		if(!T) {
			exit(OVERFLOW);
		}
		T->data=ch;
		createBiTree(T->lchild);
		createBiTree(T->rchild);
	}
	return OK;
}

Status preTraverse(BiTree &T) {
	if(T==NULL) {
		return OK;
	} 
	cout<<(char)T->data<<" ";
	preTraverse(T->lchild);
	preTraverse(T->rchild);
	return OK;
}

Status midTraverse(BiTree &T) {
	if(T==NULL) {
		return OK;
	}
	if(T->lchild) {
		midTraverse(T->lchild);
	}
	cout<<(char)T->data<<" ";
	if(T->rchild) {
		midTraverse(T->rchild);
	}
	return 	OK;
}

Status afterTraverse(BiTree &T) {
	if(T==NULL) {
		return OK;
	}
	if(T->lchild) {
		afterTraverse(T->lchild);
	}
	if(T->rchild) {
		afterTraverse(T->rchild);
	}
	cout<<(char)T->data<<" ";
}
