/*
 * �ļ�������
 *		   ������غ����ӿ�
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
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
    // ������ newWord �洢������
    bool regist(const std::string &newWord);
    // ������ newWord �洢������
    bool regist(const char *newWord);

    // ��������������������.
    // ���� os Ϊ���Ŀ���ļ�����
    void print(std::ostream &os) const;

    // ������֮�ֵ�˳�����������
    // ���� os Ϊ���Ŀ���ļ�
    void print_byorder(std::ostream &os) const;

private: //��������������Ϊ˽�еģ�����ֹ�� Tree ������.
    Tree(const Tree &);

    Tree &operator=(const Tree &);
    //�����������������˽�нӿڣ��ṩ��print��������
    void print_pre_order(std::ostream &os, const Tnode *node, unsigned int deepth) const;
    //�ֵ�˳������������˽�нӿڣ��ṩ��print_byorder��������
    void print_byorder(std::ostream &os, const Tnode *node, unsigned int deepth) const;
    //��������������˽�нӿڣ��ṩ��clear��������
    void delete_post_order(Tnode *node);
    //��newWordע�ᵽnode�У�˽�нӿڣ��ṩ�������ӿ�regist��������
    bool regist(Tnode *(&node), const std::string &newWord);

private:
    Tnode *myRoot; // ָ�� �������

};   // end of class Tree

#endif