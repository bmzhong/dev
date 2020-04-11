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

}; //枚举类型定义

// 下面是模块内的全局变量的 “非定义声明”
extern Token_value curr_tok; // 当前读到的单词之种类

extern string string_value; 

extern double number_value;

extern std::istream *input; // 定义指向标准输入设备或文件的指针

extern std::vector<std::string> fileNames;

// 下面是模块内的函数 “非定义”声明
Token_value get_token();

int parseCommandLine(int argc, char *argv[]);

int switch_input();

void skip();
} // end of namespace Lexer


#endif