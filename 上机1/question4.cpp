#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define FEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef float ElemType0;
typedef int ElemType1;
typedef struct PolynNode {
	ElemType0 coef;
	ElemType1 expn;
	struct PolynNode *next;
} PolynNode,*PolynList;
Status create(PolynList &L);
Status init(PolynList &L,int n);
Status end(PolynList &L,PolynList &p);
Status last(PolynList &L,PolynList &p);
Status traverse(PolynList &L,int &sum);
Status merge(PolynList &La,PolynList &Lb);
Status negative(PolynList &L); 
int main() {
	int m,n,sum=0;
	cout<<"��ֱ�������������ʽ��������"<<endl;
	cin>>m>>n;
	PolynList La,Lb;
	create(La);
	create(Lb);
	init(La,m);
	init(Lb,n);
	merge(La,Lb);
	traverse(La,sum);
	cout<<"������Ӳ�����Ķ���ʽ������: "<<endl;
	cout<<sum<<endl;
//	negative(Lb);
//	merge(La,Lb);
//	traverse(La,sum);
//	cout<<"�������������Ķ���ʽ������: "<<endl;
//	cout<<sum<<endl;
	return 0;
}
//������ͷ�ڵ�ĵ����� 
Status create(PolynList &L) {
	if(!L) return ERROR;
	L=(PolynList)malloc(sizeof(PolynNode));
	L->next=NULL;
	return OK;
}
//��ʼ���������ڵ����Ϊn 
Status init(PolynList &L,int n) {
	PolynList p=L,q;
	cout<<"��ɶ�����ϵ����ָ����"<<endl;
	for(int i=0; i<n; ++i) {
		q=(PolynList)malloc(sizeof(PolynNode));
		cin>>q->coef>>q->expn;
		q->next=NULL;
		p->next=q;
		p=p->next;
	}
	return OK;
}
//����������� 
Status traverse(PolynList &L,int &sum) {
	PolynList ps=L->next,pe,po;
	sum=0;
//	�������
	cout<<"���������������"<<endl; 
	if(L->next==NULL) {
		cout<<"0"<<endl;
		return OK;
	}
	end(L,pe);
	po=pe;
	while(po&&po!=L) {
		cout<<po->coef<<","<<po->expn<<",  ";
		last(L,po);
		++sum;
	}
//	˳�����
//	while(pc){
//		++sum;
//		cout<<pc->coef<<","<<pc->expn<<" ";
//		pc=pc->next;
//	}
	cout<<endl;
	return OK;
}
//ʹp��Ϊp����һ���ڵ� 
Status last(PolynList &L,PolynList &p) {
	PolynList pa=L;
	while(pa->next!=p) {
		pa=pa->next;
	}
	p=pa;
	return OK;
}
//ʹp��ΪL��������һ���ڵ� 
Status end(PolynList &L,PolynList &p) {
	PolynList pa=L->next;
	while(pa->next) {
		pa=pa->next;
	}
	p=pa;
	return OK;
}
//��������ʽ��� 
Status merge(PolynList &La,PolynList &Lb) {
	PolynList pa=La->next,pb=Lb->next,pc;
	pc=La;
	while(pa&&pb) {
		if(pa->expn<pb->expn) {
			pc->next=pa;
			pc=pc->next;
			pa=pa->next;
		} else if(pa->expn>pb->expn) {
			pc->next=pb;
			pc=pc->next;
			pb=pb->next;
		} else {
			if(pa->coef==-pb->coef) {
				PolynList t1,t2;
				t1=pa,t2=pb;
				pa=pa->next;
				pb=pb->next;
				free(t1);
				free(t2);
			} else {
				pa->coef=pa->coef+pb->coef;
				pc->next=pa;
				pc=pc->next;
				pa=pc->next;
				pb=pb->next;
			}
		}
	}
	pc->next=pa?pa:pb;
	return OK;
}
//��L��ÿ���ϵ��ȡ�� 
Status negative(PolynList &L) {
	PolynList pa=L->next;
	while(pa) {
		pa->coef=-pa->coef;
		pa=pa->next;
	}
	return OK;
}
