/*
 * 文件描述：实现语法分析器 （parser）
 *		   
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/11
 *
 */
#include <string>
#include "lexer.h"
#include "error.h"
#include "sym.h"
#include "parser.h"

using namespace std;
using namespace Lexer;
using namespace Error;
using namespace Symbol_table;
namespace Parser
{

int error_type = 0;

double expr(bool get) //表达式分析开始以及处理'+'、'-'运算（符）
{
    double left = term(get); //left表示'+'、'-'的左边结果
    for (;;)                 //无穷循环
        switch (curr_tok)
        {
        case PLUS:
            left += term(true); //调用term()得到'+'的右边结果，'+'运算后结果保存在left中
            break;
        case MINUS:
            left -= term(true);
            break;
        default:
            if (curr_tok == ERR)
                return 1;
            return left;
        }
}
double term(bool get) //处理'*'、'/'运算（符）
{

    double left = prim(get); //left表示'*'、'/'的左边结果
    for (;;)
        switch (curr_tok)
        {
        case MUL:
            left *= prim(true); //调用term()得到'*'的右边结果，'*'运算后结果保存在left中
            break;
        case DIV: //除数不能为0
            if (double d = prim(true))
            {
                left /= d;
                break;
            }
            error_type = 1;
            skip();//丢弃表达式剩下的部分
            return 1;
            // return error(curr_tok, "divide by 0");
        default:
            if (curr_tok == ERR)
                return 1;
            return left;
        }
}
double prim(bool get) //表达式的基本项
{
    if (get)
        get_token(); //调用get_token()获取一个记号（符号）给curr_tok

    switch (curr_tok)
    {
    case NUMBER:
    { //浮点数常量
        double v = number_value;
        get_token();
        return v;
    }
    case NAME:
    { //命名常量或变量的名字
        // double &v = table[string_value]; //已定义的命名常量
        double v = Symbol_table::select(string_value); //已定义的命名常量
        if (get_token() == ASSIGN)                     //名字后跟赋值运算符，是变量名
        {
            v = expr(true);//获得变量的值(也是一个表达式)
            Symbol_table::add(string_value,v);
        } 
        return v;
    }
    case MINUS:
    { //取负
        return -prim(true);
    }
    case LP:
    { //左括号
        double e = expr(true);
        if (curr_tok != RP)
        {
            error_type = 2;
            skip();//丢弃表达式剩下的部分
            return 1;
            // return error(curr_tok, ") expected");
        }

        get_token(); //扔掉')'
        return e;
    }
    default:
        error_type = 3;
        // error(curr_tok, "primary expected");
        skip();//丢弃表达式剩下的部分
        return 1;
    }
}
} // namespace Parser
