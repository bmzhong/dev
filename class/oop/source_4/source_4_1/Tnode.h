/*
 * �ļ�������
 *		   ���ڵ����غ����ӿ�
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/23
 *
 */

#ifndef _Tnode_
#define _Tnode_
#include <string>
#include <iostream>

using namespace std;

class Tnode
{
public:
    Tnode(const char *text = 0); //default constructor

    Tnode(const std::string &text); // ��2�����캯��

    ~Tnode(); // ��������

public:
    //��������ڵ��ֵ
    void setWord(const std::string &val) { word = val; }
    // return the const reference to the word of const Tnode
    const std::string &getWord() const { return word; }
    // return the non-const reference to the word of non-const Tnode
    std::string &getWord() { return word; }
    //�������ӵ�ֵ
    void setLeft(Tnode *&val) { left = val; }
    // return the pointer to const left child of const Tnode
    const Tnode *getLeft() const { return left; }
    // return the non-const reference to left child of non-const Tnode
    Tnode *&getLeft() { return left; }
    //�����Һ��ӵ�ֵ
    void setRight(Tnode *&val) { right = val; }
    // return the pointer to const right child of const Tnode
    const Tnode *getRight() const { return right; }
    // return the non-const reference to right child of non-const Tnode
    Tnode *&getRight() { return right; }
    //����text���ֵĴ���
    void setCount(int val) { count = val; }
    //����text���ֵĴ���
    int getCount() const { return count; }
    //����text���ֵĴ���������
    int &getCount() { return count; }

    // �������ǰ����������Ϣ��
    // ���� outFile Ϊ��������ָ���ģ�����ļ�
    void print(std::ostream &os) const { os << word << "\n"; }

private: //��������������Ϊ˽�еģ�����ֹ Tnode ���󱻸���.
    Tnode(const Tnode &);
    Tnode &operator=(const Tnode &);

private:
    std::string word; // the text in this node
    int count;        // occurrence number of the word in input
    Tnode *left;      // left  child
    Tnode *right;     // right child
};
#endif