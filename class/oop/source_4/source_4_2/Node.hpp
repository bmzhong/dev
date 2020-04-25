/*
 * �ļ�������
 *	   Nodeģ��Ľӿڡ�
 *
 *     Nodeģ���ṩ�﷨���Ľڵ����ͣ�˽�г�Ա����midRecursion��preRecursion��postRecursion
 *     �ֱ�����������򡢺�����������������н����ڵ�����������������׺ǰ׺��׺�ַ�����˽��
 *     ��Ա����caculateByPost���ڼ�����ʽ�����ṩһ����Щ�����Ĺ����ӿڸ�Exprģ�顣
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
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
		 Node *rightChild = nullptr, // �������Һ��ӣ�������
		 double value1 = 0);		 // ����д�ŵ���ֵ

	~Node();

	double getValue() const; // ���㲢���ر��ʽ��ֵ

	Node *getLeftChild() const;

	Node *getRightChild() const;

	std::string getText_mid() const; // ������׺ʽ�ַ���

	std::string getText_pre() const; // ����ǰ׺ʽ�ַ���

	std::string getText_post() const; // ���غ�׺ʽ�ַ���

	void deleteNode(Node *node);

private:
	void midRecursion(std::string &text, const Node *node) const; // ������׺ʽ�ַ���

	void preRecursion(std::string &text, const Node *node) const; // ����ǰ׺ʽ�ַ���

	void postRecursion(std::string &text, const Node *node) const; // ���غ�׺ʽ�ַ���

	double caculateByPost(const Node *node) const;

private:					 //�����������е�����
	Lexer::Token_type token; // ��ס�ý�������

	double value; // �� tok ��Lexer::NUMBER����ó�Ա�洢��Ӧ����ֵ

	Node *left, *right; // ָ���������ӽ���ָ��
};
#endif