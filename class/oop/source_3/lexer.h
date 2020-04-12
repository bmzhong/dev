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
    NAME, NUMBER, END,ERR,
	PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
	PRINT = ';', ASSIGN = '=', LP = '(', RP = ')'
//RUN_ERRORΪ���ʽ��ֵ���������Ϊ0��
}; //ö�����Ͷ���

// ������ģ���ڵ�ȫ�ֱ����� ���Ƕ���������
extern Token_value curr_tok; // ��ǰ�����ĵ���֮����

extern string string_value; //ȫ�ֱ���string_value��ʾ�ӱ��ʽ��ȡ�����ַ���

extern double number_value;//ȫ�ֱ���number_value��ʾ�ӱ��ʽ��ȡ������ֵ����

extern std::istream *input; // ����ָ���׼�����豸���ļ���ָ��

extern std::vector<std::string> fileNames;//�����ļ���������

// ������ģ���ڵĺ��� ���Ƕ��塱����
Token_value get_token();//����������������ַ���������ȡһ���Ǻţ����ţ���curr_tok

int parseCommandLine(int argc, char *argv[]);//���������в���������¼��������ļ�֮·��

int switch_input();//���ڵ�ǰ�ļ��������ʱ����������һ�������ļ�
// ������ĳ�����ʽ�д���ʱ�����øú����Զ�����ǰ���ʽ��ʣ���ı�
void skip();
} // end of namespace Lexer


#endif