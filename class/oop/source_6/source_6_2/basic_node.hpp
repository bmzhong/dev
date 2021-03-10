/*
 * �ļ�������
 *	       basic_node��Ķ��塣
 *		   �����﷨���ڵ�ģ�ֱ�ӻ��ӣ����࣬
 *         ������ȫ���﷨����㶼���е����ԣ��������е����ݺͲ����ӿڣ���
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/06/23
 *
 */

#pragma once
#include "Lexer.hpp"
#include <string>
#include <sstream>
#include <iostream>
class basic_node
{
protected:
	Lexer::t_token mToken;

public:
	~basic_node() = default;

	virtual double eval() const = 0; //������ʽ��ֵ

	virtual std::string generateInfix() const = 0;//������׺���ʽ

	virtual std::string generatePreFix() const = 0;//����ǰ׺���ʽ

	virtual std::string generatePostFix() const = 0;//������׺���ʽ

	virtual std::string typeName() const = 0;//���ؽڵ�����

	virtual void deleteNode() = 0; //������

	virtual Lexer::Token_type getKind() const //���ش������ݵ�����
	{
		return this->mToken.tok_kind;
	}

	virtual long getPosition() const //��������ڵ�������ԭ���ʽ��λ��
	{
		return this->mToken.tok_pos;
	}

	virtual std::string getText() const//���ؽڵ㴢�������
	{
		return this->mToken.tok_txt;
	}

	virtual void printTree() const//��ӡ·
	{
		std::cout << this->mToken.tok_txt;
	}

protected:
	basic_node(Lexer::t_token _mToken) : mToken(_mToken) {}

	basic_node() = default;
};