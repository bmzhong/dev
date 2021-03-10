#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define INIT_SIZE 30
#define INCREAMENT 10
typedef int Status;
typedef char ElementType;
typedef struct SqStack {
	ElementType *base;
	ElementType *top;
	int size;
} SqStack;
Status init(SqStack &S);
bool stackEmpty(SqStack &S);
Status pop(SqStack &S);
Status push(SqStack &S,ElementType e);
Status getTop(SqStack &S,ElementType &e);
Status match(SqStack &S);
int main() {
	SqStack S;
	init(S);
	match(S);
	return 0;
}
Status init(SqStack &S) {
	S.base=(ElementType *)malloc(INIT_SIZE*sizeof(ElementType));
	if(!S.base) {
		exit(OVERFLOW);
	}
	S.top=S.base;
	S.size=INIT_SIZE;
	return OK;
}
bool stackEmpty(SqStack &S) {
	return S.top==S.base?true:false;
}
Status pop(SqStack &S) {
	if(stackEmpty(S)) {
		return ERROR;
	}
	--S.top;
	return OK;
}
Status push(SqStack &S,ElementType e) {
	if(S.top-S.base>=S.size) {
		S.base=(ElementType *)realloc(S.base,(S.size+INCREAMENT)*sizeof(ElementType));
		if(!S.base) {
			exit(OVERFLOW);
		}
		S.top=S.base+S.size;
		S.size=S.size+INCREAMENT;
	}
	*S.top++=e;
	return OK;
}
Status getTop(SqStack &S,ElementType &e) {
	if(stackEmpty(S)) {
		return ERROR;
	}
	e=*--S.top;
	S.top++;
	return OK;
}
Status match(SqStack &S) {
	string  str;
	char c;
	cin>>str;
	for(int i=0; i<str.length(); ++i) {
		if(str[i]=='('||str[i]=='['||str[i]=='{') {
			push(S,str[i]);
		} else if(str[i]==')'||str[i]==']'||str[i]=='}') {
			getTop(S,c);
			if(stackEmpty(S)) {
				cout<<"no"<<endl;
				return ERROR;
			} else {
				switch(str[i]) {
					case ')':
						if(c=='(') {
							break;
						} else {
							cout<<"no"<<endl;
							return ERROR;
						}
					case ']':
						if(c=='[') {
							break;
						} else {
							cout<<"no"<<endl;
							return ERROR;
						}
					case '}':
						if(c=='}') {
							break;
						} else {
							cout<<"no"<<endl;
							return ERROR;
						}
				}
			}
			pop(S);
		}
	}
	if(stackEmpty(S)) {
		cout<<"yes"<<endl;
	}
	return OK;
}
//	if(!S.base) exit(OVERFLOW);注意if(!S.base)是当S.base为空的时候才执行后面的语句。
//  在写程序的时候直接写成了if(S.base);导致程序直接退出。
//  pop函数中的语句写成了 *S.top++=e；而push函数中的语句写成了*S.top--；两者写反了。 
//	注意switch中的case，如果在执行的case中没有break，后面的case无论是否匹配都
//  执行相应的内容; 
