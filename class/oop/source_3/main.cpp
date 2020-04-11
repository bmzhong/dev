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
    // 先登记预定义的符号——若符号表保留了其变量table
    Symbol_table::init();

    // 输入未结束就继续分析下一个表达式
    while (Lexer::END != Lexer::get_token())
    {
        if (Lexer::curr_tok == Lexer::PRINT)
            continue; //空表达式
        if (Lexer::curr_tok == Lexer::ERR)
        { //当遇到表达式有错误，则丢弃错误表达式的剩余部分
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
        switch (Lexer::curr_tok) // 表达式分析结束后，再判断
        {
        case Lexer::PRINT: // 表达式正常结束
        case Lexer::END:   // 最后一个表达式之后无换行或分号时
            ++rows;
            cout << rows << "th row's result is " << value << " " << endl;
            continue;
        case Lexer::ERR: // 表达式有错误，则丢弃尚未读取的剩余部分
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
