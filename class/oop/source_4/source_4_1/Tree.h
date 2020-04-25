/*
 * 文件描述：
 *		   树的相关函数接口
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/23
 *
 */

#ifndef _Tree_
#define _Tree_

#include <iostream>
#include "Tnode.h"
#include <string>
using namespace std;

class Tree
{
public:
    Tree(); // make a empty tree

    ~Tree(); // destroy all nodes in this tree

    void clear(); // destroy all nodes in this tree
    // 将单词 newWord 存储到树中
    bool regist(const std::string &newWord);
    // 将单词 newWord 存储到树中
    bool regist(const char *newWord);

    // 按先序遍历，输出整颗树.
    // 参数 os 为输出目标文件对象
    void print(std::ostream &os) const;

    // 按单词之字典顺序输出整颗树
    // 参数 os 为输出目标文件
    void print_byorder(std::ostream &os) const;

private: //这两个操作定义为私有的，以阻止对 Tree 对象复制.
    Tree(const Tree &);

    Tree &operator=(const Tree &);
    //先序遍历输出这颗树，私有接口，提供给print函数调用
    void print_pre_order(std::ostream &os, const Tnode *node, unsigned int deepth) const;
    //字典顺序输出这颗树，私有接口，提供给print_byorder函数调用
    void print_byorder(std::ostream &os, const Tnode *node, unsigned int deepth) const;
    //后序遍历这颗树，私有接口，提供给clear函数调用
    void delete_post_order(Tnode *node);
    //将newWord注册到node中，私有接口，提供给公共接口regist函数调用
    bool regist(Tnode *(&node), const std::string &newWord);

private:
    Tnode *myRoot; // 指向 树根结点

};   // end of class Tree

#endif