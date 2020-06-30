/*
 * �ļ�������
 *	       CMulNode��Ķ��塣
 *         �˷��ࡣ
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/06/23
 *
 */
#pragma once
#include "CBinaryOpNode.hpp"
#include "Lexer.hpp"
class CMulNode : public CBinaryOpNode
{
public:
    ~CMulNode() = default;

    CMulNode(Lexer::t_token _mToken,
             basic_node *_mLeftChild = nullptr, basic_node *_mRightChild = nullptr)
        : CBinaryOpNode(_mToken, _mLeftChild, _mRightChild) {} 

    CMulNode() = default;

    virtual double eval() const;

    virtual std::string typeName() const;
};
