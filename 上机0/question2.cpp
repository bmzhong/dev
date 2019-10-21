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
typedef struct SqList {
	int *elem;
	int lenth;
	int listsize;
} SqList;

Status initList(SqList &L);
Status createArray(SqList &L,int n);
Status winner(SqList &L,int m);
Status deleteElement(SqList &L,int i);
Status find(SqList &L,int &t,int m);

int main() {
	int m,n;
	cin>>n>>m;
	SqList L;
	initList(L);
	createArray(L,n);
	winner(L,m);
	cout<<"ʤ���߱�ţ�"<<endl;
	cout<<*L.elem<<endl;
	return 0;
}

Status initList(SqList &L) {
	L.elem=(int *)malloc(DSIZE*sizeof(int));
	if(!L.elem) exit(OVERFLOW);
	L.lenth=0;
	L.listsize=DSIZE;
	return OK;
}

Status createArray(SqList &L,int n) {
	if(n<1) return ERROR;
	if(n>L.listsize) {
		L.elem=(int *)realloc(L.elem,n*sizeof(int));
		L.listsize=n;
	}
	if(!L.elem) exit(OVERFLOW);
	for(int i=1; i<=n; ++i) {
		*(L.elem+i-1)=i;
		++L.lenth;
	}
	cout<<"����ı��˳��"<<endl;
	for(int i=0; i<L.lenth; ++i) {
		cout<<L.elem[i]<<" ";
	}
	cout<<endl;
	return OK;
}

Status winner(SqList &L,int m) {
	int t=1;
	int d=0;
	int x;
	cout<<"�����߱�ţ�"<<endl; 
	while(L.lenth!=1) {
		if(t+m-1<L.lenth) {
			t=t+m-1;
			deleteElement(L,t);
			continue;
		}
		if(t+m-1==L.lenth) {
			t=t+m-1;
			deleteElement(L,t);
			t=1;
			continue;
		}
		if(t+m-1>L.lenth) {
			find(L,t,m);
			if(t==L.lenth) {
				deleteElement(L,t);
				t=1;
				continue;
			}else{
				deleteElement(L,t);
			}
//			x=(m-(L.lenth+t+1))/L.lenth;
//			d=m-(L.lenth-t+1+L.lenth*x);
//			t=d;
//			deleteElement(L,t);
		}
	}
	cout<<endl;
	return OK;
}

Status deleteElement(SqList &L,int i) {
	if(i<1||i>L.lenth) return ERROR;
	int* p=L.elem+i-1 ;
	cout<<*p<<" ";
	for(p; p<=L.elem+L.lenth-1; ++p) {
		*p=*(p+1);
	}
	--L.lenth;
	return OK;
}
Status find(SqList &L,int &t,int m) {
	int i=1;
	while(i!=m) {
		if(i==m) break;
		if(t<L.lenth) {
			++t;
			++i;
			continue;
		}
		if(t==L.lenth) {
			t=1;
			++i;
		}
	}
	return OK;
}
/*
	if(t+m-1<L.lenth) {
			t=t+m-1;
			deleteElement(L,t);
			continue;
		}
		if(t+m-1==L.lenth) 
��winner������whileѭ���У�if(t+m-1<L.lenth){}��ı���t��ֵ��
����һ��if(t+m-1==L.lenth)�жϵ�ʱ��t��ֵ�Ѿ�����ԭ���Ǹ�ֵ������
��һ��if����ı���ֵ�����Ӱ��ڶ���if���жϣ�����Ҫ��continue���������ѭ���� 
*/

