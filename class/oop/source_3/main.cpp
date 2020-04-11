#include <iostream>
#include <string>
#include "lexer.cpp"
#include "sym.cpp"
#include "error.cpp"
#include "parser.cpp"

using namespace std;

int rows = 0;

int main(int argc, char *argv[])
{
    if (Lexer::parseCommandLine(argc, argv) != 0)
    { //�����ļ��޷��򿪣�
        return 1;
    }
    // �ȵǼ�Ԥ����ķ��š��������ű����������table
    Symbol_table::init();

    // ����δ�����ͼ���������һ�����ʽ
    while (Lexer::END != Lexer::get_token())
    {
        if (Lexer::curr_tok == Lexer::PRINT)
            continue; //�ձ��ʽ
        if (Lexer::curr_tok == Lexer::ERR)
        { //���������ʽ�д�������������ʽ��ʣ�ಿ��
            Lexer::skip();
            continue;
        }

        double value = Parser::expr(false);

        string error_message;
        if (Parser::error_type > 0)
        {
            curr_tok = RUN_ERROR;
            error_message = Error::error_msg(Parser::error_type);
        }
        switch (Lexer::curr_tok) // ���ʽ�������������ж�
        {
        case Lexer::PRINT: // ���ʽ��������
        case Lexer::END:   // ���һ�����ʽ֮���޻��л�ֺ�ʱ
            ++rows;
            cout << rows << "th row's result is " << value << " " << endl;
            continue;
        case Lexer::ERR: // ���ʽ�д���������δ��ȡ��ʣ�ಿ��
            Lexer::skip();
            continue;
        case Lexer::RUN_ERROR:
            ++rows;
            Error::error(rows, error_message);
            continue;
        default:
            ++rows;
            Error::error(rows, "may need expression ending");
            Lexer::skip();
        }
        Parser::error_type = 0;
    }

    if (Lexer::input != &std::cin)
        delete Lexer::input;

    return 0;
}
