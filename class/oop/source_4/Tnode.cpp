#include <string>
#include "Tnode.h"
using namespace std;
Tnode::Tnode(const char *text) //default constructor
{
    word = text;
    count = 1;
    this->left=0;
    this->right=0;
}

Tnode::Tnode(const std::string &text) // 第2个构造函数
{
    word = text;
    count = 1;
    this->left=0;
    this->right=0;
}

Tnode::~Tnode() // the ONLY destructor
{
}

Tnode::Tnode(const Tnode &node)
{
	
    word = node.word;
    count = node.count;
    left = node.left;
    right = node.right;
}

Tnode &Tnode::operator=(const Tnode &node)
{
    word = node.word;
    count = node.count;
    left = node.left;
    right = node.right;
}
