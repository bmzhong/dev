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

    Symbol_table::init();

    // ����δ�����ͼ���������һ�����ʽ
    while (Lexer::END != Lexer::get_token())
    {
        double value = 0;
        Parser::error_type = 0;
        if (Lexer::curr_tok == Lexer::PRINT)
            continue; //�ձ��ʽ
        else if (Lexer::curr_tok == Lexer::ERR)
        {
            Lexer::skip();           //���������ʽ�д�������������ʽ��ʣ�ಿ��
            Parser::error_type = 3;  //��ʱ����ִ��Ӧ��������󣬶�����continue��
        }
        else
            value = Parser::expr(false);//ִ�б��ʽ
        std::string error_message;
        if (Parser::error_type != 0)//error_type != 0��ʾ�д�
        {
            curr_tok = ERR;
            error_message = Error::error_msg(Parser::error_type);//��ȡ������Ϣ
        }
        switch (Lexer::curr_tok) // ���ʽ�������������ж�
        {
        case Lexer::PRINT: // ���ʽ��������
        case Lexer::END:   // ���һ�����ʽ֮���޻��л�ֺ�ʱ
            ++rows;
            cout << rows << "th row's result is " << value << " " << endl;
            continue;
        case Lexer::ERR: 
            ++rows;
            // Lexer::skip();�Ѿ��ڴ���ط�����ʣ�µı��ʽ
            Error::error(rows, error_message);
            continue;
        default:
            ++rows;
            Lexer::skip();//����������ʽ��ʣ�ಿ��
            Error::error(rows, "may need expression ending");
        }
    }

    if (Lexer::input != &std::cin)
        delete Lexer::input;

    system("pause");
    return 0;
}
