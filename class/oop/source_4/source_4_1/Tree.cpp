#include <iostream>
#include "Tnode.h"
#include "Tree.h"
#include <string>
using namespace std;

Tree::Tree() { // make a empty tree
	this->myRoot=0;
}

Tree::~Tree() {// destroy all nodes in this tree
	clear();//���ù�������clear������
}

void Tree::clear() {
	delete_post_order(this->myRoot);//����˽�к���delete_post_order������
}

bool Tree::regist(const std::string &newWord) {
	if (regist(this->myRoot, newWord))//����˽�к���regist��newWordע�ᵽ����
		return true;
	return false;
}

bool Tree::regist(const char *newWord) {
	if (regist(this->myRoot, newWord))//����˽�к���regist��newWordע�ᵽ����
		return true;
	return false;
}

void Tree::print(std::ostream &os) const {
	if (NULL == this->myRoot) {
		os << "Tree is empty\n";
		return;
	}
	print_pre_order(os, this->myRoot, 0); //����˽�к���print_pre_order�����
}

void Tree::print_byorder(std::ostream &os) const {
	if (NULL == this->myRoot) {
		os << "Tree is empty\n";
		return;
	}
	print_byorder(os, this->myRoot, 0);//����˽�к���print_pre_order�����
}
//����Ϊ˽�г�Ա����
//���������
void Tree::print_pre_order(std::ostream &os, const Tnode *node, unsigned int deepth) const {
	for(unsigned int d=0; d<deepth; ++d) os << "   "; // �������Ա��ڹ۲������
	if(NULL == node)  {
		os << "<NULL>\n"; //���������ڱ���/�������Һ��ӡ�
		return;
	}
	node->print(os);
	if( (NULL == node->getLeft()) && (NULL == node->getRight() ) )
		return;

	print_pre_order(os, node->getLeft(), deepth+1);
	print_pre_order(os, node->getRight(), deepth+1);
}
//�ֵ��������
void Tree::print_byorder(std::ostream &os, const Tnode *node, unsigned int deepth) const {
	if (NULL == node) {
		for(unsigned int d=0; d<deepth; ++d)
			os << "   ";
		os << "<NULL>\n"; //���������ڱ���/�������Һ��ӡ�
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
//��newWordע�ᵽnode��
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
//������
void Tree::delete_post_order(Tnode *node) {
	if (!node)
		return;
	delete_post_order(node->getLeft());
	delete_post_order(node->getRight());
	delete node;
}