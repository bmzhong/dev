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
Status createArray(SqList &L,int size);
Status sortArray(SqList &L);
Status insertList(SqList &L,int e);
int main() {
	int n,m;
	cout<<"输入随机数的个数"<<endl;
	cin>>n;
	SqList L;
	initList(L);
	createArray(L,n);
	sortArray(L);
	for(int i=0; i<L.lenth; ++i) {
		cout<<*(L.elem+i)<<" ";
	}
	cout<<endl<<"输入需要插入的数据"<<endl;
	cin>>m;
	insertList(L,m);
	for(int i=0; i<L.lenth; ++i) {
		cout<<*(L.elem+i)<<" ";
	}
	return 0;
}
Status initList(SqList &L) {
	L.elem=(int *)malloc(DSIZE*sizeof(int));
	if(!L.elem) exit(OVERFLOW);
	L.lenth=0;
	L.listsize=DSIZE;
	return OK;
}

Status createArray(SqList &L,int size) {
	if(size<1) return ERROR;
	if(size>L.listsize) {
		L.elem=(int *)realloc(L.elem,size*sizeof(int));
		L.listsize=size;
	}
	if(!L.elem) exit(OVERFLOW);
	int randomNum;
	for(int i=0; i<size; ++i) {
		randomNum=rand()%100;
		*(L.elem+i)=randomNum;
		++L.lenth;
	}
	return OK;
}

Status sortArray(SqList &L) {
	int temp;
	for(int i=0; i<L.lenth-1; ++i) {
		for(int j=i; j<L.lenth; ++j) {
			if(*(L.elem+j)<*(L.elem+i)) {
				temp=*(L.elem+i);
				*(L.elem+i)=*(L.elem+j);
				*(L.elem+j)=temp;
			}
		}
	}
	return OK;
}

Status insertList(SqList &L,int e) {
	if(!(L.lenth<L.listsize)) {
		L.elem=(int *)realloc(L.elem,(L.listsize+INCREAMENT)*sizeof(int));
		L.listsize=L.listsize+INCREAMENT;
	}
	int a=0;
	if(!L.elem) exit(OVERFLOW);
	int i=0;
	while(e>*(L.elem+i)) {
		i++;
	}
	for(int j=L.lenth; j>i&&j>0; --j) {
		*(L.elem+j)=*(L.elem+j-1);
	}
	*(L.elem+i)=e;
	++L.lenth;
	return OK;
}



