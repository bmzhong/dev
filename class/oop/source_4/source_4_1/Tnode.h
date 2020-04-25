/*
 * 文件描述：
 *		   树节点的相关函数接口
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
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

    Tnode(const std::string &text); // 第2个构造函数

    ~Tnode(); // 析构函数

public:
    //设置这个节点的值
    void setWord(const std::string &val) { word = val; }
    // return the const reference to the word of const Tnode
    const std::string &getWord() const { return word; }
    // return the non-const reference to the word of non-const Tnode
    std::string &getWord() { return word; }
    //设置左孩子的值
    void setLeft(Tnode *&val) { left = val; }
    // return the pointer to const left child of const Tnode
    const Tnode *getLeft() const { return left; }
    // return the non-const reference to left child of non-const Tnode
    Tnode *&getLeft() { return left; }
    //设置右孩子的值
    void setRight(Tnode *&val) { right = val; }
    // return the pointer to const right child of const Tnode
    const Tnode *getRight() const { return right; }
    // return the non-const reference to right child of non-const Tnode
    Tnode *&getRight() { return right; }
    //设置text出现的次数
    void setCount(int val) { count = val; }
    //返回text出现的次数
    int getCount() const { return count; }
    //返回text出现的次数的引用
    int &getCount() { return count; }

    // 仅输出当前结点自身的信息。
    // 参数 outFile 为（调用者指定的）输出文件
    void print(std::ostream &os) const { os << word << "\n"; }

private: //这两个操作定义为私有的，以阻止 Tnode 对象被复制.
    Tnode(const Tnode &);
    Tnode &operator=(const Tnode &);

private:
    std::string word; // the text in this node
    int count;        // occurrence number of the word in input
    Tnode *left;      // left  child
    Tnode *right;     // right child
};
#endif