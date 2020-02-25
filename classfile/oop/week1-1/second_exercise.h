typedef int ElemType;
typedef struct Node Stack;

//自定义栈接口(interface):使用者（用户,user）角度
bool InitStack(Stack &S);
bool isEmpty(Stack S);
ElemType GetTop(Stack S);
bool Push(Stack &S, ElemType e);
void Pop(Stack &S);
/*end of interface */

//自定义栈（链栈）：单链表表示（不含头结点）
typedef struct Snode *NodePTR;

struct Snode
{ //链表结点
    ElemType data;
    struct Snode *next;
};
struct Node
{
    NodePTR top; //栈顶指针（单链表头指针），空栈时为空指针(0,NULL或nullptr)
};