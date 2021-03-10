#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 1
#define INFEASIBLE -1
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
typedef int elemtype;
typedef int Status;
typedef struct LNode {
	elemtype data;
	struct LNode* next;
} LNode,*LinkList;
Status createList(LinkList &L);
Status init(LinkList &L,int i);
Status insertElem(LinkList &L,int i);
Status deleteElem(LinkList &L,int i);
Status traverse(LinkList &L);
int main() {
	LinkList L;
	createList(L);
	cout<<"�������ʼ���Ľڵ����"<<endl;
	int count;
	cin>>count;
	init(L,count);
	traverse(L);
	int site1,site2;
	cout<<"������ڵ�����λ��"<<endl;
	cin>>site1;
	insertElem(L,site1);
	cout<<"������Ҫɾ���ڵ��λ��"<<endl;
	cin>>site2;
	deleteElem(L,site2);
	return 0;
}
Status createList(LinkList &L) {
	if(!L) exit(INFEASIBLE);
	LinkList p=(LinkList)malloc(sizeof(LNode));
	p->next=NULL;
	L=p;
	return OK;
}

Status init(LinkList &L,int i) {
	if(i<1) exit(OVERFLOW);
	createList(L);
	LinkList q=L;
	cout<<"������ÿ���ڵ������"<<endl;
	for(int j=0; j<i; ++j) {
		LinkList p=(LinkList)malloc(sizeof(LNode));
		p->next=NULL;
		cin>>p->data;
		q->next=p;
		q=q->next;
	}
	return OK;
}

Status insertElem(LinkList &L,int i) {
	if(!L) exit(INFEASIBLE);
	if(i<1) exit(ERROR);
	cout<<"���������ڵ������"<<endl;
	LinkList p=(LinkList)malloc(sizeof(LNode));
	cin>>p->data;
	LinkList q=L;
	int j=0;
	while(j<i-1) {
		q=q->next;
		++j;
	}
	p->next=q->next;
	q->next=p;
	traverse(L);
	return OK;
}
Status deleteElem(LinkList &L,int i) {
	if(i<1) return ERROR;
	LinkList p=L;
	int j=0;
	while(j<i-1) {
		p=p->next;
		++j;
	}
	LinkList t=p->next->next;
	free(p->next);
	p->next=t;
	traverse(L);
	return OK;
}

Status traverse(LinkList &L) {
	LinkList p=L->next;
	cout<<"���������������"<<endl;
	if(p==NULL) {
		cout<<"empty list"<<endl;
		return ERROR;
	}
	while(p!=NULL) {
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
	return OK;
}
