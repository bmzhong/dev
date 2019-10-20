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
#define LIST_INIT_SIZE 100
#define LIST_INCREAMENT 10
typedef struct {
	int *elem;
	int length;
	int listsize;
} SqList;

Status initList(SqList &L) {
	L.elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status ListInsert(SqList &L,int i,int e) {
	if(i<1||i>L.length+1) return ERROR;
	if(L.length>=L.listsize) {
		int *newbase = (int *)realloc(L.elem,(L.listsize+LIST_INCREAMENT)*sizeof(int));
		if(!newbase) exit(OVERFLOW);
		L.elem = newbase;
		L.listsize+=LIST_INCREAMENT;
	}
	int *q = &(L.elem[i-1]);
	for(int *p=&(L.elem[L.length-1]); p>=q; --p) {
		*(p+1) = *p;
	}
	*q=e;
	++L.length;
	return OK;
}

Status ListDelete(SqList &L,int i,int &e) {
	if((i<1||i>L.length)) return ERROR;
	int *p=&L.elem[i-1];
	e=*p;
	int *q = L.elem+L.length-1;
	for(++p; p<q; ++p) {
		*(p-1)=*p;
	}
	--L.length;
	return OK;

}

Status CompareTwoElements(int a,int b) {
	return a>b?1:(a==b?0:-1);
}

Status LocateElement(SqList &L,int e,int (*compare)(int,int)) {
	compare=CompareTwoElements;
	int i=1;
	int *p= L.elem;
	while(i<L.length&&!(*compare)(*p++,e)==0) i++;
	if(i<=L.length) return i;
	else return 0;
}

void MergeList(SqList La,SqList Lb,SqList &Lc) {
	Lc.length=Lc.listsize=La.length+Lb.length;
	int *pa=La.elem,*pb=Lb.elem;
	int *pc=Lc.elem=(int *)malloc(Lc.length*sizeof(int));
	if(!Lc.elem) exit(OVERFLOW);
	int *paLast=La.elem+La.length-1;
	int *pbLast=Lb.elem+Lb.length-1;
	while(pa<=paLast&&pb<=pbLast) {
		*pa<*pb?*pc++=*pa++:*pc++=*pb++;
	}
	while(*pa<=*paLast) {
		*pc++=*pa++;
	}
	while(*pb<=*pbLast) {
		*pc++=*pb++;
	}
}
