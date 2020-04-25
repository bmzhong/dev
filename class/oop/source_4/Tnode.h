#ifndef _Tnode_
#define _Tnode_
#include <string>
#include<iostream>

using namespace std;

class Tnode
{
public:                          // public interface for operations
    Tnode(const char *text = 0); //default constructor

    Tnode(const std::string &text); // 第2个构造函数

    ~Tnode(); // the ONLY destructor

public:

    void setWord(const std::string &val) { word = val; }
    // return the const reference to the word of const Tnode
    const std::string &getWord() const { return word; }
    // return the non-const reference to the word of non-const Tnode
    std::string &getWord() { return word; }

    void setLeft(Tnode * &val) { left = val; }
    // return the pointer to const left child of const Tnode
    const Tnode *getLeft() const { return left; }
    // return the non-const reference to left child of non-const Tnode
    Tnode * &getLeft() { return left; }

    void setRight(Tnode * &val) { right = val; }

    const Tnode *getRight() const { return right; }

    Tnode * &getRight() { return right; }

    void setCount(int val) { count = val; }

    int getCount() const { return count; }

    int &getCount() { return count; }

    // 仅输出当前结点自身的信息。6
    // 参数 outFile 为（调用者指定的）输出文件
    void print(std::ostream &os) const { os << word << "\n"; } //一定要传引用

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
