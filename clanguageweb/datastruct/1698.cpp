#include <iostream>
using namespace std;
struct A
{
    char data;
    struct A *lchild;
    struct A *rchild;
    int ltag=0, rtag=0;
};
typedef A *PA;
void InThreading(PA &p, PA &pre);
void InOrderThreading(PA &Thr, PA &T);
void InOrderTranverse(PA &Thr);
void init(PA &T);
int main()
{
    PA Thr,T;
    init(T);
    InOrderThreading(Thr,T);
    InOrderTranverse(Thr);
    cout<<endl;
    system("pause");
    return 0;
}

void init(PA &T)
{
    char a;
    cin.get(a);
    if (a == ' ')
    {
        T = NULL;
    }
    else
    {
        T = new A;
        T->data = a;
        init(T->lchild);
        init(T->rchild);
    }
}

void InOrderThreading(PA &Thr, PA &T)
{
    Thr = new A;
    Thr->rchild = Thr;
    PA pre;
    Thr->ltag = 0;
    if (!T)
        Thr->lchild = Thr;
    else
    {
        Thr->lchild = T;
        pre = Thr;
        InThreading(T, pre);
        Thr->rchild = pre;
        Thr->rtag = 1;
        pre->rchild = Thr;
        pre->rtag = 1;
    }
}

void InThreading(PA &p, PA &pre)
{
    if (p)
    {
        InThreading(p->lchild, pre);
        if (!p->lchild)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (!pre->rchild)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        pre = p;
        InThreading(p->rchild, pre);
    }
}

void InOrderTranverse(PA &Thr)
{
    PA p = Thr->lchild;
    while (p != Thr)
    {
        while (p->ltag == 0)
            p = p->lchild;
        cout << p->data << " ";
        while (p->rtag == 1 && p->rchild != Thr)
        {
            p = p->rchild;
            cout << p->data << " ";
        }
        p = p->rchild;
    }
}
