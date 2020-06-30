/*
 * �ļ�������
 *	       CUnaryMinusNode��Ķ��塣
 *         һԪ������
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
class CUnaryMinusNode : public CUnaryOpNode
{
public:
    ~CUnaryMinusNode() = default;

    CUnaryMinusNode(Lexer::t_token _mToken, basic_node *_mChild = nullptr)
        : CUnaryOpNode(_mToken, _mChild) {} // ����д�ŵ���ֵ

    CUnaryMinusNode() = default;

    virtual double eval() const;

    virtual std::string typeName() const;
};