#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 1
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
Status create(LinkList &L);
Status init(LinkList &L,int i);
Status sort(LinkList &L);
Status traverse(LinkList &L);
int main(){
	LinkList L;
	create(L);
	int i;
	cin>>i;
	init(L,i);
	cout<<"��ʼ����ı������"<<endl; 
	traverse(L);
	cout<<"�����ı������"<<endl; 
	sort(L);
	traverse(L);
	return OK;
}

Status create(LinkList &L){
	if(!L) return ERROR;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
    return OK; 
}

Status init(LinkList &L,int i){
	if(i<1) exit(OVERFLOW);
	create(L);
	LinkList q=L;
	for(int j=0; j<i; ++j) {
		LinkList p=(LinkList)malloc(sizeof(LNode));
		p->next=NULL;
		cin>>p->data;
		q->next=p;
		q=q->next;
	}
	return OK;
}

Status sort(LinkList &L){
	LinkList p=L;
	int i=1;
	p=p->next;
	while((p->next)!=NULL){
		++i;
		p=p->next;
	}
	int t;
	LinkList w=L->next;
	for(int j=i;j>0;--j){
		for(int k=0;k<j-1;++k){
			if(w->data>w->next->data){
					t=w->data;
					w->data=w->next->data;
					w->next->data=t;				
			}
			w=w->next;
		}
		w=L->next;
	}
	return OK;
}

Status traverse(LinkList &L) {
	LinkList p=L->next;
	if(!p) return ERROR;
	while(p){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
	return OK;
}
//while(p){loop};����ѭ��p���һ����ΪNULL��
//���붨λ�����һ���ڵ�Ӧ����while(p-next){loop};
//ע��ڵ������ͳ�ƣ�
//ע��ð�������ѡ����������� 

