/*
 * 文件描述：实现词法分析器（Lexer）
 *		   
 * 姓名:
 *		   钟保明
 * 学号:
 *		   18070100017
 * 日期:
 *		   2020/04/11
 *
 */
#include <iostream>
#include <fstream>
#include "lexer.h" // 包含自己的接口声明头文件
using namespace std;

namespace Lexer
{
// 下面是模块内的全局变量的 “定义”
// 当前读到的单词的种类
Token_value curr_tok = PRINT;

std::string string_value;

double number_value;

std::vector<std::string> fileNames;

istream *input;
char ch = 0;
// 下面是模块内的函数的“定义”
Token_value get_token()
{
    ch = 0;
    do
    { // 这里是跳过空白字符
        if (!(input->get(ch)))
        {
            if (PRINT != curr_tok)
                return curr_tok = PRINT;
            // 当前文件结束了，尝试打开下一文件
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
    { //NAME(字母开头的字母数字串),NAME=,or error  Page115
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
        // 先打开第1个输入文件
        input = new ifstream(fileNames[0].c_str());

        //接着判断文件是否成功打开了。
        if (input->good())
        {                                       //为true时就表示成功打开了
            fileNames.erase(fileNames.begin()); //  若成功打开则 接着可将第1个文件名剔除：
            return 0;                           //最后若成功打开则返回0，
        }
        // 否则返回非0值并报错。
        return 1;
    }
}
int switch_input()
{
    if (fileNames.empty())
    {
        return 1;
    } /*没有文件了*/
    else
    {
        delete input; //关闭上个文件，接着打开下个文件
        input = new ifstream(fileNames[0].c_str());
        //接着判断文件是否成功打开了。
        if (input->good())
        {                                       //为true时就表示成功打开了
            fileNames.erase(fileNames.begin()); //  若成功打开则 接着可将第1个文件名剔除：
            return 0;                           //最后若成功打开则返回0，
        }
        // 否则返回非0值并报错。
        return 1;
    }
}
void skip()
{
    if(ch=='\n'||ch==';')//有可能已经读取整个错误表达式并且此时curr_tok值为ERR，
         return;          //此时不应该再执行下面的语句，否则会把下一个表达式清空。
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
