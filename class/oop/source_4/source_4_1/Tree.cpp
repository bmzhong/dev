#include <iostream>
#include "Tnode.h"
#include "Tree.h"
#include <string>
using namespace std;

Tree::Tree() { // make a empty tree
	this->myRoot=0;
}

Tree::~Tree() {// destroy all nodes in this tree
	clear();//调用公共函数clear销毁树
}

void Tree::clear() {
	delete_post_order(this->myRoot);//调用私有函数delete_post_order销毁树
}

bool Tree::regist(const std::string &newWord) {
	if (regist(this->myRoot, newWord))//调用私有函数regist将newWord注册到树上
		return true;
	return false;
}

bool Tree::regist(const char *newWord) {
	if (regist(this->myRoot, newWord))//调用私有函数regist将newWord注册到树上
		return true;
	return false;
}

void Tree::print(std::ostream &os) const {
	if (NULL == this->myRoot) {
		os << "Tree is empty\n";
		return;
	}
	print_pre_order(os, this->myRoot, 0); //调用私有函数print_pre_order输出树
}

void Tree::print_byorder(std::ostream &os) const {
	if (NULL == this->myRoot) {
		os << "Tree is empty\n";
		return;
	}
	print_byorder(os, this->myRoot, 0);//调用私有函数print_pre_order输出树
}
//以下为私有成员函数
//先序输出树
void Tree::print_pre_order(std::ostream &os, const Tnode *node, unsigned int deepth) const {
	for(unsigned int d=0; d<deepth; ++d) os << "   "; // 缩进，以便于观察结点深度
	if(NULL == node)  {
		os << "<NULL>\n"; //这个输出用于表现/区分左右孩子。
		return;
	}
	node->print(os);
	if( (NULL == node->getLeft()) && (NULL == node->getRight() ) )
		return;

	print_pre_order(os, node->getLeft(), deepth+1);
	print_pre_order(os, node->getRight(), deepth+1);
}
//字典序输出树
void Tree::print_byorder(std::ostream &os, const Tnode *node, unsigned int deepth) const {
	if (NULL == node) {
		for(unsigned int d=0; d<deepth; ++d)
			os << "   ";
		os << "<NULL>\n"; //这个输出用于表现/区分左右孩子。
		return;
	}
	if ((NULL == node->getLeft()) && (NULL == node->getRight())) {
		for(unsigned int d=0; d<deepth; ++d)
			os << "   ";
		node->print(os);
		return;
	}
	print_byorder(os, node->getLeft(), deepth + 1);
	for(unsigned int d=0; d<deepth; ++d)
		os << "   ";
	node->print(os);
	print_byorder(os, node->getRight(), deepth + 1);
}
//将newWord注册到node中
bool Tree::regist(Tnode * &node, const std::string &newWord) {
	if (!node) {
		node = new Tnode(newWord);
		return true;
	}
	if (node->getWord() == newWord)//
		node->setCount(++node->getCount());
	else if (node->getWord() > newWord)
		regist(node->getLeft(), newWord);
	else if (node->getWord() < newWord)
		regist(node->getRight(), newWord);
	return true;
}
//销毁树
void Tree::delete_post_order(Tnode *node) {
	if (!node)
		return;
	delete_post_order(node->getLeft());
	delete_post_order(node->getRight());
	delete node;
}