#ifndef _lexer_
#define _lexer_

#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace Lexer
{
enum Token_value
{
    NAME, NUMBER, END,ERR,RUN_ERROR,
	PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
	PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'

}; //ö�����Ͷ���

// ������ģ���ڵ�ȫ�ֱ����� ���Ƕ���������
extern Token_value curr_tok; // ��ǰ�����ĵ���֮����

extern string string_value; 

extern double number_value;

extern std::istream *input; // ����ָ���׼�����豸���ļ���ָ��

extern std::vector<std::string> fileNames;

// ������ģ���ڵĺ��� ���Ƕ��塱����
Token_value get_token();

int parseCommandLine(int argc, char *argv[]);

int switch_input();

void skip();
} // end of namespace Lexer


#endif