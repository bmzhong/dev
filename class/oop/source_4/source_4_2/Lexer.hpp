/*
 * �ļ�������
 * 
 *	   Lexerģ�����غ����ӿ�
 *
 *     Lexerģ������ɨ���ַ�����ÿ�ζ�ȡһ��double���͵������߲�������curr_tok���浱ǰ
 *     ɨ���״̬��number_value���浱ǰ��ȡ��ֵ����
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
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

    Token_type get_token(); // ��ȡ���е�һ���Ǻ�(TOKEN)

    Token_type currentToken();//���ص�ǰ��token

    void setToken(Token_type token);//����token��ֵ

    double getValue() const;//���ز�����value

    void oppositeValue();//�Բ�����ȡ���������ʽ��һ���ַ�Ϊ'-'ʱ���á�

private:
    const char *exprText; // ��¼ԭʼ���ʽ�ĵ�ַ

    Token_type curr_tok; //  ��ĿǰΪֹ��ʶ�𵽵����һ���Ǻŵ�����

    double number_value; // ��curr_tok=NUMBER���ó�Ա��ס������ʾ����ֵ

    int index;//ָ��ǰ��ȡ��λ��

    int len;//���ʽ�ĳ���
};
#endif