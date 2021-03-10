/*
 * �ļ�������
 *		   ���ڵ����غ����ӿڵ�ʵ��
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/23
 *
 */
#include <string>
#include "Tnode.h"
using namespace std;
Tnode::Tnode(const char *text) //���캯��
{
    word = text;
    count = 1;
    this->left = 0;
    this->right = 0;
}

Tnode::Tnode(const std::string &text) // ��2�����캯��
{
    word = text;
    count = 1;
    this->left = 0;
    this->right = 0;
}

Tnode::Tnode(const Tnode &node) //���ƹ��캯��
{

    word = node.word;
    count = node.count;
    left = node.left;
    right = node.right;
}

Tnode::~Tnode() // ��������
{
}

Tnode &Tnode::operator=(const Tnode &node) // ��ֵ������������
{
    word = node.word;
    count = node.count;
    left = node.left;
    right = node.right;
}