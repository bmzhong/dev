/*
 * �ļ�������
 *	       CUnaryPlusNode��Ķ��塣
 *         һԪ�ӷ���
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/06/23
 *
 */
#pragma once
#include "CUnaryOpNode.hpp"
#include "Lexer.hpp"
class CUnaryPlusNode : public CUnaryOpNode
{
public:
    ~CUnaryPlusNode() = default;

    CUnaryPlusNode(Lexer::t_token _mToken, basic_node *_mChild = nullptr)
        : CUnaryOpNode(_mToken, _mChild) {} // ����д�ŵ���ֵ

    CUnaryPlusNode() = default;

    virtual double eval() const;

    virtual std::string typeName() const;
};