#ifndef _Tree_
#define _Tree_

#include <iostream>
#include "Tnode.h"
#include <string>
using namespace std;

class Tree
{
public:     // public interface for operations
    Tree(); // make a empty tree

    ~Tree(); // destroy all nodes in this tree

    void clear(); // destroy all nodes in this tree
    // 将单词 newWord 存储到树中
    bool regist(const std::string &newWord);

    bool regist(const char *newWord);

    // 按先序遍历，输出整颗树.
    // 参数 os 为输出目标文件对象，如
    void print(std::ostream &os) const; 

    // 按单词之字典顺序输出整颗树
    // 参数 os 为输出目标文件
    void print_byorder(std::ostream &os) const;

private:                //这两个操作定义为私有的，以阻止对 Tree 对象复制.
    Tree(const Tree &); //无需定义

    Tree &operator=(const Tree &); //无需定义
                                   // 还可以声明其他所需的辅助函数……
    void print_pre_order(std::ostream &os, const Tnode *node, unsigned int deepth) const;

    void print_byorder (std::ostream &os,const Tnode *node, unsigned int deepth) const;

    void delete_post_order(Tnode *node);

    bool regist(Tnode * &node,const std::string &newWord);

private:
    Tnode *myRoot; // 指向 树根结点
    // 还可以声明其他所需的辅助数据成员……
    // end of class Tree
};

#endif
