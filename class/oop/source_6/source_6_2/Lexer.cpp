/*
 * �ļ�������
 *		   Lexer.hpp��غ����ӿڵ�ʵ�֡�
 *
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/06/23
 *
 */

#include "Lexer.hpp"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//һ�ζ�ȡһ���������������
Lexer::Token_type Lexer::get_token()
{
    ++pos;
    if (index >= len)
        return curr_tok = END;
    char ch = 0;
    ch = exprText[index++];
    while (ch != '\n' && isspace(ch)) //�����ո�
    {
        if (ch == '\0' || index++ >= len)
            return END;
    }
    switch (ch)
    {
    case 0:
        return END;
    case ';':
    case '\n':
        return curr_tok = PRINT;
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
        return curr_tok = Token_type(ch);
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
    { //NUMBER
        char temp[350];
        int ptemp = 0;
        temp[ptemp++] = exprText[index - 1];
        while (index < len && (isdigit(exprText[index]) || exprText[index] == '.'))
        {
            temp[ptemp++] = exprText[index++];
        }
        temp[ptemp] = '\0';        //�����ַ���
        number_value = atof(temp); //���ַ���ת����double����
        return curr_tok = NUMBER;
    }
    default:
    {
        curr_tok = ERROR;
        throw "���ʽ����"; //�Ѵ����׳�
    }
    }
}

Lexer::Lexer(const char *str)
{
    exprText = str;
    index = 0;
    pos = 0;
    len = strlen(str);
}

Lexer::~Lexer() {}

Lexer::Token_type Lexer::currentToken()
{
    return curr_tok;
}

double Lexer::getValue() const
{
    return number_value;
}

void Lexer::oppositeValue()
{
    number_value = -number_value;
}

void Lexer::setToken(Token_type token)
{
    curr_tok = token;
}

int Lexer::getPos() const
{
    return this->pos;
}