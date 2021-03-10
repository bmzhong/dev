#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string word;
    int count = 0;
    struct Node *lchild = NULL;
    struct Node *rchild = NULL;
};
typedef Node *PNode;
PNode root = NULL;
void insert(PNode &p, string str);
void preOrder(const PNode &p);
void midOrder(const PNode &p);
int main()
{
    string str;
    //(1) Write a function for entering new words into a tree of Tnodes;
    while (cin >> str)
        insert(root, str);
    cout << endl;

    //(2) Write a function to write out a tree of Tnodes;
    preOrder(root);

    cout << "\nthe words in ahlpabetical order:" << endl;
    //(3) Write a function to write out a tree of Tnodes with the words in ahlpabetical order.
    midOrder(root);

    system("pause");
    return 0;
}

void insert(PNode &p, string str)
{
    if (!p)
    {
        p = new Node;
        p->word = str;
        p->count = 1;
        return;
    }
    if (p->word == str)
        ++(p->count);
    else if (p->word > str)
        insert(p->lchild, str);
    else if (p->word < str)
        insert(p->rchild, str);
}

void preOrder(const PNode &p)
{
    if (!p)
        return;
    cout << "word:    " << p->word << "      count:    " << p->count << endl;
    preOrder(p->lchild);
    preOrder(p->rchild);
}

void midOrder(const PNode &p)
{
    if (!p)
        return;
    midOrder(p->lchild);
    cout << "word:    " << p->word << "      count:   " << p->count << endl;
    midOrder(p->rchild);
}