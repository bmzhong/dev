/*
 * �ļ�������
 *	       CNumberNode��Ķ��塣
 *         ��ֵ��
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
#include "CLeafNode.hpp"
#include <cstdio>
class CNumberNode : public CLeafNode
{
public:
    ~CNumberNode() = default;

    virtual double eval() const; // ���㲢���ر��ʽ��ֵ

    virtual std::string typeName() const;

    CNumberNode(Lexer::t_token _mToken) : CLeafNode(_mToken) {} // ����д�ŵ���ֵ

    CNumberNode() = default;

    virtual void deleteNode();

    virtual std::string generateInfix() const ;

    virtual std::string generatePreFix() const ;

    virtual std::string generatePostFix() const ;
};