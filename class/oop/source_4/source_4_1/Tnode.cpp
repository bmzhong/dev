/*
 * 文件描述：
 *		   树节点的相关函数接口的实现
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/23
 *
 */
#include <string>
#include "Tnode.h"
using namespace std;
Tnode::Tnode(const char *text) //构造函数
{
    word = text;
    count = 1;
    this->left = 0;
    this->right = 0;
}

Tnode::Tnode(const std::string &text) // 第2个构造函数
{
    word = text;
    count = 1;
    this->left = 0;
    this->right = 0;
}

Tnode::Tnode(const Tnode &node) //复制构造函数
{

    word = node.word;
    count = node.count;
    left = node.left;
    right = node.right;
}

Tnode::~Tnode() // 析构函数
{
}

Tnode &Tnode::operator=(const Tnode &node) // 赋值操作符的重载
{
    word = node.word;
    count = node.count;
    left = node.left;
    right = node.right;
}