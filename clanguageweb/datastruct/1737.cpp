#include <iostream>
#include <string>
using namespace std;
typedef struct Node
{
    char data;
    struct Node *lchild = NULL;
    struct Node *rchild = NULL;
} * PNode;
void insert(PNode &p, char a);
void isSame(PNode p, PNode q, bool &is);
int main()
{
    string str, str1;
    int n;
    PNode T = NULL, CT = NULL;
    while (cin >> n && n != 0)
    {
        T = NULL;
        cin >> str;
        int len = str.size();
        for (int i = 0; i < len; ++i)
        {
            insert(T, str[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            CT = NULL;
            cin >> str1;
            int len1 = str1.size();
            for (int j = 0; j < len1; ++j)
            {
                insert(CT, str1[j]);
            }
            bool is = true;
            isSame(T, CT, is);
            if (is)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    system("pause");
    return 0;
}

void isSame(PNode p, PNode q, bool &is)
{
    if (p && q)
    {
        if (p->data != q->data)
        {
            is = false;
        }
        else
        {
            isSame(p->lchild, q->lchild, is);
            isSame(p->rchild, q->rchild, is);
        }
    }
    else if ((!p && q) || (!q && p))
    {
        is = false;
    }
}

void insert(PNode &p, char a)
{
    if (p)
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
    else
    {
        p = new Node;
        p->data = a;
    }
}