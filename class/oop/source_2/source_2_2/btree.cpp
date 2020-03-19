#include "btree.h"
#include <iostream>
using namespace std;
//将str插入到二叉树中
void Btree::insert(PNode &p, string str)
{
    if (!p)//如果p==0,则创建这个节点，并将str插入到p中。
    {
        p = new Node;
        p->word = str;
        p->count = 1;
        return;
    }
    if (p->word == str)//如果str和p节点的word相等，则令p->count加一
        ++(p->count);
    else if (p->word > str)
        insert(p->lchild, str);//从左子树中寻找合适的节点
    else if (p->word < str)
        insert(p->rchild, str);//从柚子树中寻找合适的节点
}

void Btree::preOrder(const PNode &p, unsigned int indent)
{
    for (int i = 0; i < indent; ++i)
    {
        cout << " ";//输出缩进
    }
    if (!p)
    {
        cout << "null" << endl;//这个节点为空输出null
        return;
    }
    cout << p->word << ": " << p->count << endl;
    preOrder(p->lchild, indent + 1);//输出左子树
    preOrder(p->rchild, indent + 1);//输出右子树
}

void Btree::midOrder(const PNode &p)
{
    if (!p)
        return;
    midOrder(p->lchild);//输出左子树
    cout << p->word << ": " << p->count << endl;
    midOrder(p->rchild);//输出右子树
}

void Btree::delete_tree(PNode &p)
{
    if (!p)
        return;
    delete_tree(p->lchild);//先删除左子树
    delete_tree(p->rchild);//删除右子树
    delete p;//删除这个节点
}