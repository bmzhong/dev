/*
 * �ļ�������ʵ�ִʷ���������Lexer��
 *		   
 * ����:
 *		   �ӱ���
 * ѧ��:
 *		   18070100017
 * ����:
 *		   2020/04/11
 *
 */
#include <iostream>
#include <fstream>
#include "lexer.h" // �����Լ��Ľӿ�����ͷ�ļ�
using namespace std;

namespace Lexer
{
// ������ģ���ڵ�ȫ�ֱ����� �����塱
// ��ǰ�����ĵ��ʵ�����
Token_value curr_tok = PRINT;

std::string string_value;

double number_value;

std::vector<std::string> fileNames;

istream *input;
char ch = 0;
// ������ģ���ڵĺ����ġ����塱
Token_value get_token()
{
    ch = 0;
    do
    { // �����������հ��ַ�
        if (!(input->get(ch)))
        {
            if (PRINT != curr_tok)
                return curr_tok = PRINT;
            // ��ǰ�ļ������ˣ����Դ���һ�ļ�
            if (0 != switch_input())
                return curr_tok = END;
            else
            {
                ch = ' ';
                continue;
            }
        }
    } while (ch != '\n' && isspace(ch));

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
    case '=':
        return curr_tok = Token_value(ch);
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
        input->putback(ch);
        *input >> number_value;
        return curr_tok = NUMBER;
    }
    default:
    { //NAME(��ĸ��ͷ����ĸ���ִ�),NAME=,or error  Page115
        if (isalpha(ch))
        {
            string_value = ch;
            while (input->get(ch) && isalnum(ch))
                string_value.push_back(ch);
            input->putback(ch);
            return curr_tok = NAME;
        }
        return curr_tok = ERR;
    }
    }
}

int parseCommandLine(int argc, char *argv[])
{
    if (argc == 1)
    {
        Lexer::input = &cin;
        return 0;
    }
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            fileNames.push_back(argv[i]);
        }
        // �ȴ򿪵�1�������ļ�
        input = new ifstream(fileNames[0].c_str());

        //�����ж��ļ��Ƿ�ɹ����ˡ�
        if (input->good())
        {                                       //Ϊtrueʱ�ͱ�ʾ�ɹ�����
            fileNames.erase(fileNames.begin()); //  ���ɹ����� ���ſɽ���1���ļ����޳���
            return 0;                           //������ɹ����򷵻�0��
        }
        // ���򷵻ط�0ֵ������
        return 1;
    }
}
int switch_input()
{
    if (fileNames.empty())
    {
        return 1;
    } /*û���ļ���*/
    else
    {
        delete input; //�ر��ϸ��ļ������Ŵ��¸��ļ�
        input = new ifstream(fileNames[0].c_str());
        //�����ж��ļ��Ƿ�ɹ����ˡ�
        if (input->good())
        {                                       //Ϊtrueʱ�ͱ�ʾ�ɹ�����
            fileNames.erase(fileNames.begin()); //  ���ɹ����� ���ſɽ���1���ļ����޳���
            return 0;                           //������ɹ����򷵻�0��
        }
        // ���򷵻ط�0ֵ������
        return 1;
    }
}
void skip()
{
    if(ch=='\n'||ch==';')//�п����Ѿ���ȡ����������ʽ���Ҵ�ʱcurr_tokֵΪERR��
         return;          //��ʱ��Ӧ����ִ���������䣬��������һ�����ʽ��ա�
    while(*input){
        input->get(ch);
        switch (ch)
        {
        case '\n':
        case ';':
            return;
        }
    }
}

} // namespace Lexer
