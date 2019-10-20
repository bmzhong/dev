#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define INFEASIBLE -2
#define TRUE 1
#define ERROR 0
#define DSIZE 100
#define INCREAMENT 5
typedef int Status;
typedef struct LNode {
	double real;
	double imaginary;
	struct LNode* next;
}LNode,*LinkList;

Status initLinkList(LinkList &L);
Status createLNode(LinkList &L,int real,int imaginary);
Status add(LinkList &La,LinkList &Lb);
Status mutiply(LinkList &La,LinkList &Lb);
Status subtract(LinkList &La,LinkList &Lb);
Status divide(LinkList &La,LinkList &Lb);
int main(){
	LinkList La,Lb;
	initLinkList(La);
	initLinkList(Lb);
	int real1,imaginary1,real2,imaginary2;
	cin>>real1>>imaginary1>>real2>>imaginary2;
	createLNode(La,real1,imaginary1);
	createLNode(Lb,real2,imaginary2);
	char symbol;
	cin>>symbol;
	switch(symbol){
		case '+':
			add(La,Lb);
			break;
		case '*':
			mutiply(La,Lb);
			break;
		case '-':
			subtract(La,Lb);
			break;
		case '/':
			divide(La,Lb);
	}
	return 0;
}
Status initLinkList(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
	if(!L) exit(OVERFLOW);
	L->next=NULL;
	return OK;
}
Status createLNode(LinkList &L,int real,int imaginary){
	LinkList p=L;
	while(!p){
		p=p->next;
	}
	LinkList t=(LinkList)malloc(sizeof(LNode));
	if(!t) exit(OVERFLOW);
	p->next=t;
	t->real=real;
	t->imaginary=imaginary;
	t->next=NULL;
	return OK;
}

Status add(LinkList &La,LinkList &Lb){
	int r=La->next->real+Lb->next->real;
	int i=La->next->imaginary+Lb->next->imaginary;
	cout<<r<<"+"<<i<<"i"<<endl;
	return OK;
}
Status subtract(LinkList &La,LinkList &Lb){
	int r=La->next->real-Lb->next->real;
	int i=La->next->imaginary-Lb->next->imaginary;
	cout<<r<<"+"<<i<<"i"<<endl;
	return OK;
}
Status mutiply(LinkList &La,LinkList &Lb){
	int r=(La->next->real)*(Lb->next->real)-(La->next->imaginary)*(Lb->next->imaginary);
	int i=(La->next->imaginary)*(Lb->next->real)+(La->next->real)*(Lb->next->imaginary);
	cout<<r<<"+"<<i<<"i"<<endl;
	return OK;
}
Status divide(LinkList &La,LinkList &Lb){
	int cd=(Lb->next->real)*(Lb->next->real)+(Lb->next->imaginary)*(Lb->next->imaginary);
	int r=((La->next->real)*(Lb->next->real)+(La->next->imaginary)*(Lb->next->imaginary));
	int bcad=(La->next->imaginary)*(Lb->next->real)-(La->next->real)*(Lb->next->imaginary);
	int i=bcad;
	cout<<r<<"/"<<cd<<"+"<<i<<"i/"<<cd<<endl;
}

