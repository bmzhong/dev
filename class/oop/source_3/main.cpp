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
    { //报告文件无法打开，
        return 1;
    }

    Symbol_table::init();

    // 输入未结束就继续分析下一个表达式
    while (Lexer::END != Lexer::get_token())
    {
        double value = 0;
        Parser::error_type = 0;
        if (Lexer::curr_tok == Lexer::PRINT)
            continue; //空表达式
        else if (Lexer::curr_tok == Lexer::ERR)
        {
            Lexer::skip();           //当遇到表达式有错误，则丢弃错误表达式的剩余部分
            Parser::error_type = 3;  //此时往下执行应该输出错误，而不是continue。
        }
        else
            value = Parser::expr(false);//执行表达式
        std::string error_message;
        if (Parser::error_type != 0)//error_type != 0表示有错
        {
            curr_tok = ERR;
            error_message = Error::error_msg(Parser::error_type);//获取错误信息
        }
        switch (Lexer::curr_tok) // 表达式分析结束后，再判断
        {
        case Lexer::PRINT: // 表达式正常结束
        case Lexer::END:   // 最后一个表达式之后无换行或分号时
            ++rows;
            cout << rows << "th row's result is " << value << " " << endl;
            continue;
        case Lexer::ERR: 
            ++rows;
            // Lexer::skip();已经在错误地方丢弃剩下的表达式
            Error::error(rows, error_message);
            continue;
        default:
            ++rows;
            Lexer::skip();//丢弃错误表达式的剩余部分
            Error::error(rows, "may need expression ending");
        }
    }

    if (Lexer::input != &std::cin)
        delete Lexer::input;

    system("pause");
    return 0;
}
