#include <iostream>
#include <stack>
using namespace std;
struct A
{
    struct A *lchild;
    char data;
    struct A *rchild;
};
typedef A *PA;
void init(PA &p);
void pre(PA Tr);
void mid(PA Tr);
void newmid1(PA Tr);
int main()
{
    PA Tr;
    init(Tr);
    cin.get();
    pre(Tr);
    cout << endl;
    mid(Tr);
    cout << endl;
    newmid1(Tr);
    cout<<endl;
    system("pause");
    return 0;
}

void pre(PA Tr)
{
    if (Tr)
    {
        cout << Tr->data << " ";
        pre(Tr->lchild);
        pre(Tr->rchild);
    }
}

void newmid1(PA Tr)
{
    stack<PA> s;
    while (Tr || !s.empty())
    {
        if (Tr)
        {
            s.push(Tr);
            Tr = Tr->lchild;
        }
        else
        {
            Tr=s.top();
            s.pop();
            cout << Tr->data<<" ";
            Tr=Tr->rchild;
        }
    }
}

void mid(PA Tr)
{
    if (Tr)
    {
        mid(Tr->lchild);
        cout << Tr->data << " ";
        mid(Tr->rchild);
    }
}

void init(PA &p)
{
    char a;
    cin.get(a);
    if (a == ' ')
    {
        p = NULL;
    }
    else
    {
        p = (PA) new A;
        p->data = a;
        init(p->lchild);
        init(p->rchild);
    }
}
