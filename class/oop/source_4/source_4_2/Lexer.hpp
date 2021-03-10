/*
 * 文件描述：
 * 
 *	   Lexer模块的相关函数接口
 *
 *     Lexer模块用于扫描字符串：每次读取一个double类型的数或者操作符，curr_tok保存当前
 *     扫描的状态，number_value保存当前读取的值。。
 *
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/23
 *
 */

#ifndef _THIS_IS_LEXER_
#define _THIS_IS_LEXER_

class Lexer
{     
public: 
    enum Token_type
    {
        NUMBER,
        END,
        ERROR,
        PLUS = '+',
        MINUS = '-',
        MUL = '*',
        DIV = '/',
        PRINT = ';',
        LP = '(',
        RP = ')'
    };

public:
    Lexer(const char *str);

    ~Lexer();

    Token_type get_token(); // 读取串中的一个记号(TOKEN)

    Token_type currentToken();//返回当前的token

    void setToken(Token_type token);//设置token的值

    double getValue() const;//返回操作数value

    void oppositeValue();//对操作数取反，当表达式第一个字符为'-'时调用。

private:
    const char *exprText; // 记录原始表达式的地址

    Token_type curr_tok; //  到目前为止，识别到的最后一个记号的种类

    double number_value; // 若curr_tok=NUMBER，该成员记住它所表示的数值

    int index;//指向当前读取的位置

    int len;//表达式的长度
};
#endif