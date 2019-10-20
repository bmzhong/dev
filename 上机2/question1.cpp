#include<iostream>
#include<cstdlib>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define INFEASIBLE -2
#define INIT_SIZE 20
#define INCREAMENT 10
typedef int Status;
typedef int ElementType;
typedef struct SqStack {
    ElementType *base;
    ElementType *top;
    int size;
}SqStack;
bool stackEmpty(SqStack &S);
Status push(SqStack &S, ElementType e);
Status converse(SqStack &S);
Status pop(SqStack &S, ElementType &e);
Status init(SqStack &S);
int main(){
    SqStack S;
    init(S);
    converse(S);
    return 0;
};
Status init(SqStack &S){
    S.base = (ElementType *) malloc(INIT_SIZE * sizeof(ElementType));
    if(!S.base) exit(OVERFLOW);
    S.top=S.base;
    S.size=INIT_SIZE;
    return OK;
}



Status converse(SqStack &S){
    int n;
    cin>>n;
    ElementType e,t;
    while (n) {
        push(S, n % 2);
        n=n/2;
    }
    while (!stackEmpty(S)) {
        pop(S, e);
        cout<<e;
    }
    cout<<endl;
    return OK;
}

bool stackEmpty(SqStack &S){
   return S.base==S.top?true:false;
}
//注意*S.top不是栈顶元素
//注意*S.top++=e和e=*--S.top; 
Status pop(SqStack &S, ElementType &e) {
    if (S.top == S.base) {
        return ERROR;
    }
    e=*--S.top;
    return OK;
}

Status push(SqStack &S, ElementType e) {
    if (S.top - S.base >= S.size) {
        S.base = (int *) realloc(S.base, (S.size + INCREAMENT * sizeof(ElementType)));
        if (!S.base) {
            exit(OVERFLOW);
        }
        S.top = S.base + S.size;
        S.size = S.size + INCREAMENT;
    }
    *S.top++ = e;
    return OK;
}
