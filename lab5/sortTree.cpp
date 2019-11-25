#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm> 
using namespace std;
typedef struct Node{
	int data;
	struct Node *lchild;
	struct Node *rchild;
}Node,*PNode;
int main(){
	
}
bool createTree(PNode &P){
	P=(PNode)malloc(sizeof(Node));
	P->lchild=NULL;
	P->rchild=NULL;
	P->data=0;	
	return true;
}

bool initTree(PNode &P,vector<int> v,int &pos){
	
}
