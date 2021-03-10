#include <iostream>
#include <string>
using namespace std;
typedef struct Node
{
    char data;
    struct Node *lchild = NULL;
    struct Node *rchild = NULL;
} * PNode;
void create(int L1, int R1, int L2, int R2, PNode &p);
void postOrder(PNode &p);
string pre, in;
int main()
{
    while (cin >> pre)
    {
        PNode T = NULL;
        int len = pre.length();
        cin >> in;
        create(0, len - 1, 0, len - 1, T);
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
        cout << p->data;
    }
}

void create(int L1, int R1, int L2, int R2, PNode &p)
{
    if (L1 > R1 || L2 > R2)
        return;
    p = new Node;
    p->data = pre[L1];
    int index = L2;
    while (in[index] != p->data)
    {
        ++index;
    }
    int len = index - L2;
    create(L1 + 1, L1 + len, L2, index - 1, p->lchild);
    create(L1 + len + 1, R1, index + 1, R2, p->rchild);
}