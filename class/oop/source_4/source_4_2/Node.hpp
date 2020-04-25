/*
 * 文件描述：
 *	   Node模块的接口。
 *
 *     Node模块提供语法树的节点类型，私有成员函数midRecursion，preRecursion，postRecursion
 *     分别进行中序、先序、后序遍历，遍历过程中将本节点的数或操作符加入中缀前缀后缀字符串。私有
 *     成员函数caculateByPost用于计算表达式。并提供一组这些函数的公共接口给Expr模块。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/23
 *
 */

#ifndef _THIS_IS_EXPRNODE_
#define _THIS_IS_EXPRNODE_

#include "Lexer.hpp"
#include <string>
#include <sstream>
class Node
{
public:
	Node(Lexer::Token_type tokenType,
		 Node *leftChild = nullptr,
		 Node *rightChild = nullptr, // 结点的左、右孩子（子树）
		 double value1 = 0);		 // 结点中存放的数值

	~Node();

	double getValue() const; // 计算并返回表达式的值

	Node *getLeftChild() const;

	Node *getRightChild() const;

	std::string getText_mid() const; // 返回中缀式字符串

	std::string getText_pre() const; // 返回前缀式字符串

	std::string getText_post() const; // 返回后缀式字符串

	void deleteNode(Node *node);

private:
	void midRecursion(std::string &text, const Node *node) const; // 返回中缀式字符串

	void preRecursion(std::string &text, const Node *node) const; // 返回前缀式字符串

	void postRecursion(std::string &text, const Node *node) const; // 返回后缀式字符串

	double caculateByPost(const Node *node) const;

private:					 //存放在树结点中的数据
	Lexer::Token_type token; // 记住该结点的性质

	double value; // 若 tok 是Lexer::NUMBER，则该成员存储对应的数值

	Node *left, *right; // 指向两个孩子结点的指针
};
#endif