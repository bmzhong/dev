/*
 * �ļ�������
 *	       COpNode��Ķ��塣
 *         �������ĸ��ࡣ
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
class COpNode : public basic_node
{
public:
    ~COpNode() = default;

protected:
    COpNode(Lexer::t_token _mToken) : basic_node(_mToken) {} // ����д�ŵ���ֵ

    COpNode() = default;
};