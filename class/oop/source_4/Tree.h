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
    // ������ newWord �洢������
    bool regist(const std::string &newWord);

    bool regist(const char *newWord);

    // ��������������������.
    // ���� os Ϊ���Ŀ���ļ�������
    void print(std::ostream &os) const; 

    // ������֮�ֵ�˳�����������
    // ���� os Ϊ���Ŀ���ļ�
    void print_byorder(std::ostream &os) const;

private:                //��������������Ϊ˽�еģ�����ֹ�� Tree ������.
    Tree(const Tree &); //���趨��

    Tree &operator=(const Tree &); //���趨��
                                   // ������������������ĸ�����������
    void print_pre_order(std::ostream &os, const Tnode *node, unsigned int deepth) const;

    void print_byorder (std::ostream &os,const Tnode *node, unsigned int deepth) const;

    void delete_post_order(Tnode *node);

    bool regist(Tnode * &node,const std::string &newWord);

private:
    Tnode *myRoot; // ָ�� �������
    // ������������������ĸ������ݳ�Ա����
    // end of class Tree
};

#endif
