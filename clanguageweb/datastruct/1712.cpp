#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *lchild = NULL;
    struct Node *rchild = NULL;
};
typedef Node *PNode;
void insert(PNode &p, int a);
void find(PNode &p, int a);
int main()
{
    int n, m, a;
    cin >> n >> m;
    PNode P=NULL;
    for (int i = 0; i < n; ++i)
    {
        cin >> a;
        insert(P, a);
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> a;
        find(P, a);
    }
    cout<<endl;
    system("pause");
    return 0;
}
void insert(PNode &p, int a)
{
    if (!p)
    {
        p = new Node;
        p->data = a;
    }
    else if (p->data > a)
    {
        insert(p->lchild, a);
    }
    else if (p->data < a)
    {
        insert(p->rchild, a);
    }
}

void find(PNode &p, int a)
{
    if (!p)
    {
        cout << "0 ";
    }
    else if (p->data == a)
    {
        cout << "1 ";
    }
    else if (p->data > a)
    {
        find(p->lchild, a);
    }
    else if (p->data < a)
    {
        find(p->rchild, a);
    }
}