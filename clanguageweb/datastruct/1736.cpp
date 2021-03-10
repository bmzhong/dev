#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *lchild = NULL;
    struct Node *rchild = NULL;
} * PNode;
void insert(PNode &p, int a);
void postOrder(PNode &p);
void inOrder(PNode &p);
void preOrder(PNode &p);
int main()
{
    PNode T = NULL;
    int n, a;
    while (cin >> n)
    {
        T=NULL;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            insert(T, a);
        }
        preOrder(T);
        cout<<endl;
        inOrder(T);
        cout<<endl;
        postOrder(T);
        cout<<endl;
    }
    system("pause");
    return 0;
}

void postOrder(PNode &p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}

void inOrder(PNode &p)
{
    if (p)
    {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

void preOrder(PNode &p)
{
    if (p)
    {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void insert(PNode &p, int a)
{
    if (!p)
    {
        p = new Node;
        p->data = a;
    }
    else
    {
        if (p->data > a)
        {
            insert(p->lchild, a);
        }
        if (p->data < a)
        {
            insert(p->rchild, a);
        }
    }
}