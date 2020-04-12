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
//RUN_ERROR为表达式求值错误，如除数为0等
}; //枚举类型定义

// 下面是模块内的全局变量的 “非定义声明”
extern Token_value curr_tok; // 当前读到的单词之种类

extern string string_value; //全局变量string_value表示从表达式中取到的字符串

extern double number_value;//全局变量number_value表示从表达式中取到的数值常量

extern std::istream *input; // 定义指向标准输入设备或文件的指针

extern std::vector<std::string> fileNames;//储存文件名的向量

// 下面是模块内的函数 “非定义”声明
Token_value get_token();//从输入序列中逐个字符分析，读取一个记号（符号）给curr_tok

int parseCommandLine(int argc, char *argv[]);//解析命令行参数，并记录待读入的文件之路径

int switch_input();//用于当前文件读入结束时，立即打开下一个输入文件
// 当发现某个表达式有错误时，调用该函数以丢弃当前表达式的剩余文本
void skip();
} // end of namespace Lexer


#endif