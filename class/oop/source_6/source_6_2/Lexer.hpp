/*
 * �ļ�������
 * 
 *	   Lexerģ�����غ����ӿ�
 *
 *     Lexerģ������ɨ���ַ�����ÿ�ζ�ȡһ��double���͵������߲�������curr_tok���浱ǰ
 *     ɨ���״̬��number_value���浱ǰ��ȡ��ֵ��
 * 
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/06/23
 *
 */
#pragma once
#include <string>
class Lexer
{
public:
    enum Token_type
    {
        NUMBER,
        END,
        ERROR,
        UnaryPlus,
        UnartMinus,
        PLUS = '+',
        MINUS = '-',
        MUL = '*',
        DIV = '/',
        PRINT = ';',
        LP = '(',
        RP = ')',
    };
    struct t_token
    {
        int tok_pos;
        Token_type tok_kind;
        std::string tok_txt;
        t_token() : tok_kind(END), tok_pos(-1) {}
        t_token(Token_type kind, const std::string &txt, int pos)
            : tok_kind(kind), tok_txt(txt), tok_pos(pos) {}
        void clear()
        {
            tok_kind = END;
            tok_txt.clear();
            tok_pos = -1;
        }
    };

public:
    Lexer(const char *str);

    ~Lexer();

    Token_type get_token(); // ��ȡ���е�һ���Ǻ�(TOKEN)

    Token_type currentToken(); //���ص�ǰ��token

    void setToken(Token_type token); //����token��ֵ

    double getValue() const; //���ز�����value

    int getPos() const;

    void oppositeValue(); //�Բ�����ȡ���������ʽ��һ���ַ�Ϊ'-'ʱ���á�

private:
    const char *exprText; // ��¼ԭʼ���ʽ�ĵ�ַ

    Token_type curr_tok; //  ��ĿǰΪֹ��ʶ�𵽵����һ���Ǻŵ�����

    double number_value; // ��curr_tok=NUMBER���ó�Ա��ס������ʾ����ֵ

    int index; //ָ��ǰ��ȡ��λ��

    int len; //���ʽ�ĳ���

    int pos;
};