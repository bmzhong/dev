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
	cout<<"请分别输入两个多项式的项数："<<endl;
	cin>>m>>n;
	PolynList La,Lb;
	create(La);
	create(Lb);
	init(La,m);
	init(Lb,n);
	merge(La,Lb);
	traverse(La,sum);
	cout<<"经过相加操作后的多项式的项数: "<<endl;
	cout<<sum<<endl;
//	negative(Lb);
//	merge(La,Lb);
//	traverse(La,sum);
//	cout<<"经过相减操作后的多项式的项数: "<<endl;
//	cout<<sum<<endl;
	return 0;
}
//创建带头节点的单链表 
Status create(PolynList &L) {
	if(!L) return ERROR;
	L=(PolynList)malloc(sizeof(PolynNode));
	L->next=NULL;
	return OK;
}
//初始化单链表，节点个数为n 
Status init(PolynList &L,int n) {
	PolynList p=L,q;
	cout<<"请成对输入系数和指数："<<endl;
	for(int i=0; i<n; ++i) {
		q=(PolynList)malloc(sizeof(PolynNode));
		cin>>q->coef>>q->expn;
		q->next=NULL;
		p->next=q;
		p=p->next;
	}
	return OK;
}
//逆序遍历链表 
Status traverse(PolynList &L,int &sum) {
	PolynList ps=L->next,pe,po;
	sum=0;
//	逆序输出
	cout<<"逆序遍历输出结果："<<endl; 
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
//	顺序输出
//	while(pc){
//		++sum;
//		cout<<pc->coef<<","<<pc->expn<<" ";
//		pc=pc->next;
//	}
	cout<<endl;
	return OK;
}
//使p成为p的上一个节点 
Status last(PolynList &L,PolynList &p) {
	PolynList pa=L;
	while(pa->next!=p) {
		pa=pa->next;
	}
	p=pa;
	return OK;
}
//使p成为L链表的最后一个节点 
Status end(PolynList &L,PolynList &p) {
	PolynList pa=L->next;
	while(pa->next) {
		pa=pa->next;
	}
	p=pa;
	return OK;
}
//两个多项式相加 
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
//对L的每项的系数取负 
Status negative(PolynList &L) {
	PolynList pa=L->next;
	while(pa) {
		pa->coef=-pa->coef;
		pa=pa->next;
	}
	return OK;
}
