/*
 * �ļ�������
 *	       CLeafNode��Ķ���
 *         Ҷ�ӽڵ��ࡣ
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/06/23
 *
 */
#pragma once
#include "basic_node.hpp"
#include "Lexer.hpp"
class CLeafNode : public basic_node
{
public:
    ~CLeafNode() = default;

protected:
    CLeafNode(Lexer::t_token _mToken) : basic_node(_mToken) {} 

    CLeafNode() = default;
};