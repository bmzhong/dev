#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define VOERFLOW -1
#define INFEASIBLE -2
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;

Status getElement(LinkList L,int i,int &e){
	LinkList p=L->next;
	int j=1;
	while(p&&j<i){
		p=p->next;
		j++;
	}
	if(!p||j>i) return ERROR;
	e=p->data;
	return OK; 
}

Status listInsert(LinkList &L,int i,int e){
	LinkList p=L;
	int j=0;
	while(j<i-1&&p){
		p=p->next;
		j++;
	}
	if(!p||j>i-1)  return ERROR;
	LinkList q=(LinkList)malloc(sizeof(LNode));
	q->next=p->next;
	q->data=e;
	p->next=q;
	return OK;
}

Status listDelete(LinkList &L,int i,int &e){
	LinkList p = L;
	int j=0;
	while(p->next&&j<i-1){
		p=p->next;
		j++;
	}
	if(!(p->next)||j>i-1) return ERROR;
	LinkList q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK;
}

