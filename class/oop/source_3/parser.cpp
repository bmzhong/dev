/*
 * �ļ�������ʵ���﷨������ ��parser��
 *		   
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
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

double expr(bool get) //���ʽ������ʼ�Լ�����'+'��'-'���㣨����
{
    double left = term(get); //left��ʾ'+'��'-'����߽��
    for (;;)                 //����ѭ��
        switch (curr_tok)
        {
        case PLUS:
            left += term(true); //����term()�õ�'+'���ұ߽����'+'�������������left��
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
double term(bool get) //����'*'��'/'���㣨����
{

    double left = prim(get); //left��ʾ'*'��'/'����߽��
    for (;;)
        switch (curr_tok)
        {
        case MUL:
            left *= prim(true); //����term()�õ�'*'���ұ߽����'*'�������������left��
            break;
        case DIV: //��������Ϊ0
            if (double d = prim(true))
            {
                left /= d;
                break;
            }
            error_type = 1;
            skip();//�������ʽʣ�µĲ���
            return 1;
            // return error(curr_tok, "divide by 0");
        default:
            if (curr_tok == ERR)
                return 1;
            return left;
        }
}
double prim(bool get) //���ʽ�Ļ�����
{
    if (get)
        get_token(); //����get_token()��ȡһ���Ǻţ����ţ���curr_tok

    switch (curr_tok)
    {
    case NUMBER:
    { //����������
        double v = number_value;
        get_token();
        return v;
    }
    case NAME:
    { //�������������������
        // double &v = table[string_value]; //�Ѷ������������
        double v = Symbol_table::select(string_value); //�Ѷ������������
        if (get_token() == ASSIGN)                     //���ֺ����ֵ��������Ǳ�����
        {
            v = expr(true);//��ñ�����ֵ(Ҳ��һ�����ʽ)
            Symbol_table::add(string_value,v);
        } 
        return v;
    }
    case MINUS:
    { //ȡ��
        return -prim(true);
    }
    case LP:
    { //������
        double e = expr(true);
        if (curr_tok != RP)
        {
            error_type = 2;
            skip();//�������ʽʣ�µĲ���
            return 1;
            // return error(curr_tok, ") expected");
        }

        get_token(); //�ӵ�')'
        return e;
    }
    default:
        error_type = 3;
        // error(curr_tok, "primary expected");
        skip();//�������ʽʣ�µĲ���
        return 1;
    }
}
} // namespace Parser
