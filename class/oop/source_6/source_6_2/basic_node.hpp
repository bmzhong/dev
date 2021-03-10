/*
 * 文件描述：
 *	       basic_node类的定义。
 *		   所有语法树节点的（直接或间接）父类，
 *         定义了全部语法树结点都具有的特性（包括共有的数据和操作接口）。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
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

	virtual double eval() const = 0; //计算表达式的值

	virtual std::string generateInfix() const = 0;//产生中缀表达式

	virtual std::string generatePreFix() const = 0;//产生前缀表达式

	virtual std::string generatePostFix() const = 0;//产生后缀表达式

	virtual std::string typeName() const = 0;//返回节点类名

	virtual void deleteNode() = 0; //销毁树

	virtual Lexer::Token_type getKind() const //返回储存内容的类型
	{
		return this->mToken.tok_kind;
	}

	virtual long getPosition() const //返回这个节点内容在原表达式的位置
	{
		return this->mToken.tok_pos;
	}

	virtual std::string getText() const//返回节点储存的内容
	{
		return this->mToken.tok_txt;
	}

	virtual void printTree() const//打印路
	{
		std::cout << this->mToken.tok_txt;
	}

protected:
	basic_node(Lexer::t_token _mToken) : mToken(_mToken) {}

	basic_node() = default;
};