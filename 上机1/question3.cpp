#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int Elemtype;
typedef struct LNode {
	Elemtype num;
	Elemtype code;
	struct LNode *next;
} LNode, *LinkList;
Status create(LinkList &L);
Status init(LinkList &L,int n);
Status traverseNum(LinkList &L);
Status locate(LinkList &L,int m);
Status traverseCode(LinkList &L);
Status leave(LinkList &L,int m,int n);
Status last(LinkList &p);
int main() {
	int m,n;
	cout<<"请输入m的值"<<endl;
	cin>>m;
	cout<<"请输入n的值"<<endl;
	cin>>n;
	LinkList L=NULL;
	init(L,n);
	traverseNum(L);
	traverseCode(L);
	leave(L,m,n);
	return 0;
}
Status init(LinkList &L,int n) {
	if(n<1) return INFEASIBLE;
	cout<<"请输入每个人的密码"<<endl;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	cin>>L->code;
	L->num=1;
	LinkList q=L,p;
	for(int i=1; i<n; ++i) {
		p=(LinkList)malloc(sizeof(LNode));
		p->next=NULL;
		p->num=i+1;
		cin>>p->code;
		q->next=p;
		q=q->next;
	}
	p->next=L;
	return OK;
}

Status traverseNum(LinkList &L) {
	if(!L) return ERROR;
	LinkList p=L;
	cout<<"输出的每个人的元素编号"<<endl;
	cout<<p->num<<" ";
	p=p->next;
	while(p!=L) {
		cout<<p->num<<" ";
		p=p->next;
	}
	cout<<endl;
	return OK;
}
Status traverseCode(LinkList &L) {
	if(!L) return ERROR;
	LinkList p=L;
	cout<<"输出的每个人的密码"<<endl;
	cout<<p->code<<" ";
	p=p->next;
	while(p!=L) {
		cout<<p->code<<" ";
		p=p->next;
	}
	cout<<endl;
	return OK;
}
Status leave(LinkList &L,int m,int n) {
	int site=m;
	if(!L||m<1) return INFEASIBLE;
	LinkList p=L,q=L,t;
	int j=0;
	cout<<"按照出列顺序输出的每个人的编号"<<endl;
	while(p) {
		if(site==1) last(p);	
		locate(p,site);
		site=p->next->code;
		cout<<p->next->num<<" ";
		t=p->next;
		p->next=p->next->next;
		free(t);
		p=p->next;
		++j;
		if(j==n) break;
		
	}
	cout<<endl;
	return OK;
}

Status locate(LinkList &p,int m) {
	if(!p) return INFEASIBLE;
	int i=0;
	while(i<m-2) {
		p=p->next;
		++i;
	}
	return OK;
}
Status last(LinkList &p){
	LinkList q=p;
	while(q->next!=p){
		q=q->next; 
	}
    p=q;
	return OK;
}
