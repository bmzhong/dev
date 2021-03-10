/*
 * 文件描述：
 *	   Expr模块的相关函数接口
 *
 *     Expr模块：构造函数调用Parse模块的相关函数建立语法树，析构函数销毁语法树。成员函数
 *     printMid、printPre、printPost、GetValue调用Node模块的相关函数得到相应的字符串，
 *     并将字符串提供给用户。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/23
 *
 */


#ifndef _THIS_IS_EXPR_
#define _THIS_IS_EXPR_
#include "Parser.hpp"
#include "Node.hpp"
#include <iostream>
class Expr
{
public:
    Expr(const char *str);//构造语法树

    ~Expr();//销毁语法树

    double getValue() const;//得到表达式的值

    void printMid() const;//打印中缀表达式

    void printPre() const;//打印前缀表达式

    void printPost() const;//打印后缀表达式

private:
    Node *root; // 指向表达式的树根结点
};
#endif
