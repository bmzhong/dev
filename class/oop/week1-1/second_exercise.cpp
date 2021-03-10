#include <iostream>
#include "second_exercise.h"
int main()
{//自定义栈测试 
    Stack S1;
    ElemType e;
    if (!InitStack(S1))
      return -1;
    Push(S1,10);
    Push(S1,20);
    Push(S1,30);
    while (!isEmpty(S1)){
    	e = GetTop(S1);
        Pop(S1);
        std::cout << e << std::endl;
    }
    return 0;         
}
//自定义栈实现(implementation)
bool InitStack(Stack  &S)
{
	S.top = nullptr;
	return true;
}

bool isEmpty(Stack S)
{
	return (S.top == nullptr);
}

ElemType GetTop(Stack S)
{
    return S.top->data; 
}

bool Push(Stack &S, ElemType e)
{
	NodePTR p = (NodePTR)malloc(sizeof(struct Snode));
	if (!p)
	  return false;
	p->data = e;
	p->next = S.top;
	S.top = p;
	return true;
}

void Pop(Stack  &S)
{
   	NodePTR p = S.top;   
	S.top = S.top->next;
	free(p);
}
/*end of linklisted stack implementation */