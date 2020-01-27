#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef struct Node
{
    int data;
    int height;
    struct Node *lchild = NULL;
    struct Node *rchild = NULL;
} * PNode;
int getHeight(PNode p);
int balance(PNode p);
PNode ll_rotate(PNode y);
PNode rr_rotate(PNode y);
PNode lr_rotate(PNode y);
PNode rl_rotate(PNode y);
PNode insert(PNode p, int a);
void search(PNode T, bool &is, int a);
void postOrder(PNode &p);
int main()
{
    PNode T = NULL;
    int n, m, a;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        T = insert(T, a);
    }
    for (int i = 0; i < m; ++i)
    {
        bool is = false;
        cin >> a;
        search(T, is, a);
        if (is)
        {
            cout << "1 ";
        }
        else
        {
            cout << "0 ";
        }
    }
    cout << endl;
    postOrder(T);
    system("pause");
    return 0;
}

int getHeight(PNode p)
{
    if (p)
    {
        return p->height;
    }
    else
    {
        return 0;
    }
}

int balance(PNode p)
{
    if (p)
    {
        return getHeight(p->lchild) - getHeight(p->rchild);
    }
    else
    {
        return 0;
    }
}
PNode insert(PNode p, int a)
{
    if (p)
    {
        if (p->data > a)
        {
            p->lchild = insert(p->lchild, a);
        }
        if (p->data < a)
        {
            p->rchild = insert(p->rchild, a);
        }
    }
    else
    {
        p = new Node;
        p->data = a;
    }
    p->height = max(getHeight(p->lchild), getHeight(p->rchild)) + 1;
    int b = balance(p);
    if (b > 1 && a < p->lchild->data)
    { //LL型
        return ll_rotate(p);
    }
    if (b > 1 && a > p->lchild->data)
    { //LR
        return lr_rotate(p);
    }
    if (b < -1 && a < p->rchild->data)
    { //RL
        return rl_rotate(p);
    }
    if (b < -1 && a > p->rchild->data)
    { //RR
        return rr_rotate(p);
    }
    return p;
}

PNode ll_rotate(PNode y)
{
    PNode x = y->lchild;
    y->lchild == x->rchild;
    x->rchild = y;
    y->height = max(getHeight(y->lchild), getHeight(y->rchild)) + 1;
    x->height = max(getHeight(x->lchild), getHeight(x->rchild)) + 1; //必须先计算子树(y)的高度再计算根(x)的高度。
                                                                     //这两行不可换位置
    return x;
}

PNode rr_rotate(PNode y)
{
    PNode x = y->rchild;
    y->rchild = x->lchild;
    x->lchild = y;
    y->height = max(getHeight(y->lchild), getHeight(y->rchild)) + 1;
    x->height = max(getHeight(x->lchild), getHeight(y->rchild)) + 1;
    return x;
}

PNode lr_rotate(PNode y)
{
    y->lchild = rr_rotate(y->lchild);
    return ll_rotate(y);
}

PNode rl_rotate(PNode y)
{
    y->rchild = ll_rotate(y->rchild);
    return rr_rotate(y);
}

void search(PNode T, bool &is, int a)
{
    if (T)
    {
        if (T->data == a)
        {
            is = true;
        }
        else if (a < T->data)
        {
            search(T->lchild, is, a);
        }
        else
        {
            search(T->rchild, is, a);
        }
    }
    else
    {
        is = false;
    }
}

void postOrder(PNode &p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        delete p;
    }
}